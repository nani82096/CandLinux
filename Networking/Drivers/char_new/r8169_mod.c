#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/pci.h>
#include <linux/netdevice.h>
#include <linux/etherdevice.h>
#include <linux/delay.h>
#include <linux/ethtool.h>
#include <linux/mii.h>
#include <linux/if_vlan.h>
#include <linux/crc32.h>
#include <linux/in.h>
#include <linux/ip.h>
#include <linux/tcp.h>
#include <linux/interrupt.h>
#include <linux/dma-mapping.h>
#include <linux/pm_runtime.h>
#include <linux/firmware.h>
#include <linux/pci-aspm.h>
#include <linux/prefetch.h>
#include <linux/ipv6.h>
#include <net/ip6_checksum.h>

#include <asm/io.h>
#include <asm/irq.h>

#define RTL8169_VERSION "2.3LK-NAPI"
#define MODULENAME "r8169_mod"
#define PFX MODULENAME ": "

#define TX_SLOTS_AVAIL(tp) \
	(tp->dirty_tx + NUM_TX_DESC - tp->cur_tx)

/* A skbuff with nr_frags needs nr_frags+1 entries in the tx queue */
#define TX_FRAGS_READY_FOR(tp,nr_frags) \
	(TX_SLOTS_AVAIL(tp) >= (nr_frags + 1))

/* Maximum number of multicast addresses to filter (vs. Rx-all-multicast).
   The RTL chips use a 64 element hash table based on the Ethernet CRC. */
static const int multicast_filter_limit = 32;

#define MAX_READ_REQUEST_SHIFT	12
#define TX_DMA_BURST	7	/* Maximum PCI burst, '7' is unlimited */
#define InterFrameGap	0x03	/* 3 means InterFrameGap = the shortest one */

#define R8169_REGS_SIZE		256
#define R8169_NAPI_WEIGHT	64
#define NUM_TX_DESC	64	/* Number of Tx descriptor registers */
#define NUM_RX_DESC	256U	/* Number of Rx descriptor registers */
#define R8169_TX_RING_BYTES	(NUM_TX_DESC * sizeof(struct TxDesc))
#define R8169_RX_RING_BYTES	(NUM_RX_DESC * sizeof(struct RxDesc))

#define RTL8169_TX_TIMEOUT	(6*HZ)
#define RTL8169_PHY_TIMEOUT	(10*HZ)

/* write/read MMIO register */
#define RTL_W8(reg, val8)	writeb ((val8), ioaddr + (reg))
#define RTL_W16(reg, val16)	writew ((val16), ioaddr + (reg))
#define RTL_W32(reg, val32)	writel ((val32), ioaddr + (reg))
#define RTL_R8(reg)		readb (ioaddr + (reg))
#define RTL_R16(reg)		readw (ioaddr + (reg))
#define RTL_R32(reg)		readl (ioaddr + (reg))

#define PRINTK printk("In %s\n",__func__);

static const struct pci_device_id rtl8169_pci_tbl[] = {
	{PCI_DEVICE(PCI_VENDOR_ID_REALTEK, 0x8168), 0, 0, 0x1},
	{0,},
};

MODULE_DEVICE_TABLE(pci, rtl8169_pci_tbl);

static int rx_buf_sz = 16383;

#define	RX128_INT_EN			(1 << 15)	/* 8111c and later */

#define	RXCFG_DMA_SHIFT			8
					/* Unlimited maximum PCI burst. */
#define	RX_DMA_BURST			(7 << RXCFG_DMA_SHIFT)

#define	TXCFG_EMPTY			(1 << 11)	/* 8111e-vl */

#define TxPacketMax	(8064 >> 7)

enum rtl_registers {
	MAC0		= 0,	/* Ethernet hardware address. */
	MAC4		= 4,
	MAR0		= 8,	/* Multicast filter. */
	CounterAddrLow		= 0x10,
	CounterAddrHigh		= 0x14,
	TxDescStartAddrLow	= 0x20,
	TxDescStartAddrHigh	= 0x24,
	ChipCmd		= 0x37,
	TxPoll		= 0x38,
	IntrMask	= 0x3c,
	IntrStatus	= 0x3e,
	TxConfig	= 0x40,
	RxConfig	= 0x44,
	Cfg9346		= 0x50,
	Config3		= 0x54,
	Config4		= 0x55,
	Config5		= 0x56,
	MultiIntr	= 0x5c,
	PHYstatus	= 0x6c,
	RxMaxSize	= 0xda,
	CPlusCmd	= 0xe0,
	IntrMitigate	= 0xe2,
	RxDescAddrLow	= 0xe4,
	RxDescAddrHigh	= 0xe8,
	MaxTxPacketSize	= 0xec,	/* 8101/8168. Unit of 128 bytes. */
};

enum rtl_register_content {
	/* InterruptStatusBits */
	SWInt		= 0x0100,
	RxOverflow	= 0x0010,
	TxErr		= 0x0008,
	TxOK		= 0x0004,
	RxErr		= 0x0002,
	RxOK		= 0x0001,

	/* RxStatusDesc */
	RxBOVF	= (1 << 24),
	RxFOVF	= (1 << 23),

	/* ChipCmdBits */
	StopReq		= 0x80,
	CmdReset	= 0x10,
	CmdRxEnb	= 0x08,
	CmdTxEnb	= 0x04,

	/* TXPoll register p.5 */
	NPQ		= 0x40,		/* Poll cmd on the low prio queue */

	/* Cfg9346Bits */
	Cfg9346_Lock	= 0x00,
	Cfg9346_Unlock	= 0xc0,

	/* rx_mode_bits */
	AcceptErr	= 0x20,
	AcceptRunt	= 0x10,
	AcceptBroadcast	= 0x08,
	AcceptMulticast	= 0x04,
	AcceptMyPhys	= 0x02,
	AcceptAllPhys	= 0x01,
#define RX_CONFIG_ACCEPT_MASK		0x3f

	/* TxConfigBits */
	TxInterFrameGapShift = 24,
	TxDMAShift = 8,	/* DMA burst value (0-7) is shift this many bits */

	/* rtl8169_PHYstatus */
	LinkStatus	= 0x02,
};

enum rtl_desc_bit {
	/* First doubleword. */
	DescOwn		= (1 << 31), /* Descriptor is owned by NIC */
	RingEnd		= (1 << 30), /* End of descriptor ring */
	FirstFrag	= (1 << 29), /* First segment of a packet */
	LastFrag	= (1 << 28), /* Final segment of a packet */
};

#define RsvdMask	0x3fffc000

struct TxDesc {
	__le32 opts1;
	__le32 opts2;
	__le64 addr;
};

struct RxDesc {
	__le32 opts1;
	__le32 opts2;
	__le64 addr;
};

struct ring_info {
	struct sk_buff *skb;
	u32 len;
	u8 __pad[sizeof(void *) - sizeof(u32)];
};


struct rtl8169_stats {
	u64 packets;
	u64 bytes;
	struct u64_stats_sync syncp;
};

struct rtl8169_private {
	void __iomem *mmio_addr;	/* memory map physical address */
	struct pci_dev *pci_dev;
	struct net_device *dev;
	struct napi_struct napi;
	u32 msg_enable;
	u16 mac_version;
	u32 cur_rx;		/* Index into the Rx descriptor buffer of next Rx pkt. */
	u32 cur_tx;		/* Index into the Tx descriptor buffer of next Rx pkt. */
	u32 dirty_tx;
	struct rtl8169_stats rx_stats;
	struct rtl8169_stats tx_stats;
	struct TxDesc *TxDescArray;	/* 256-aligned Tx descriptor ring */
	struct RxDesc *RxDescArray;	/* 256-aligned Rx descriptor ring */
	dma_addr_t TxPhyAddr;
	dma_addr_t RxPhyAddr;
	void *Rx_databuff[NUM_RX_DESC];	/* Rx data buffers */
	struct ring_info tx_skb[NUM_TX_DESC];	/* Tx data buffers */
	struct timer_list timer;
	u16 cp_cmd;

	int (*get_settings) (struct net_device *, struct ethtool_cmd *);
	void (*hw_start) (struct net_device *);
	unsigned int (*link_ok) (void __iomem *);
	
	unsigned features;
	
	u32 opts1_mask;

};

MODULE_AUTHOR("Realtek and the Linux r8169 crew <netdev@vger.kernel.org>");
MODULE_DESCRIPTION("RealTek RTL-8169 Gigabit Ethernet driver");
MODULE_LICENSE("GPL");
MODULE_VERSION(RTL8169_VERSION);

struct rtl_cond {
	bool(*check) (struct rtl8169_private *);
	const char *msg;
};

#define DECLARE_RTL_COND(name)				\
static bool name ## _check(struct rtl8169_private *);	\
							\
static const struct rtl_cond name = {			\
	.check	= name ## _check,			\
	.msg	= #name					\
};							\
							\
static bool name ## _check(struct rtl8169_private *tp)


static u16 rtl_get_events(struct rtl8169_private *tp)
{
	void __iomem *ioaddr = tp->mmio_addr;

	return RTL_R16(IntrStatus);
}

static void rtl_ack_events(struct rtl8169_private *tp, u16 bits)
{
	void __iomem *ioaddr = tp->mmio_addr;

	RTL_W16(IntrStatus, bits);
	mmiowb();
}

static void rtl_irq_enable(struct rtl8169_private *tp, u16 bits)
{
	void __iomem *ioaddr = tp->mmio_addr;

	RTL_W16(IntrMask, bits);
}

static void rtl_irq_disable(struct rtl8169_private *tp) 
{
    void __iomem *ioaddr = tp->mmio_addr;

    RTL_W16(IntrMask, 0);
    mmiowb();
}


#define RTL_EVENT_NAPI_RX	(RxOK | RxErr)
#define RTL_EVENT_NAPI_TX	(TxOK | TxErr)
#define RTL_EVENT_NAPI		(RTL_EVENT_NAPI_RX | RTL_EVENT_NAPI_TX)

static void rtl_irq_enable_all(struct rtl8169_private *tp)
{
	rtl_irq_enable(tp, RTL_EVENT_NAPI);
}

static void rtl8169_irq_mask_and_ack(struct rtl8169_private *tp)
{
	void __iomem *ioaddr = tp->mmio_addr;

	rtl_irq_disable(tp);
	rtl_ack_events(tp, RTL_EVENT_NAPI);
	RTL_R8(ChipCmd);
}

static unsigned int rtl8169_link_ok(void __iomem * ioaddr)
{
	return RTL_R8(PHYstatus) & LinkStatus;
}

static void __rtl8169_check_link_status(struct net_device *dev,
					struct rtl8169_private *tp,
					void __iomem * ioaddr, bool pm)
{
	if (tp->link_ok(ioaddr)) {
		if (pm)
			pm_request_resume(&tp->pci_dev->dev);
		netif_carrier_on(dev);
		if (net_ratelimit())
			netif_info(tp, ifup, dev, "link up\n");
	} else {
		netif_carrier_off(dev);
		netif_info(tp, ifdown, dev, "link down\n");
		if (pm)
			pm_schedule_suspend(&tp->pci_dev->dev, 5000);
	}
}

static void rtl8169_check_link_status(struct net_device *dev,
				      struct rtl8169_private *tp,
				      void __iomem * ioaddr)
{
	__rtl8169_check_link_status(dev, tp, ioaddr, false);
}

#define WAKE_ANY (WAKE_PHY | WAKE_MAGIC | WAKE_UCAST | WAKE_BCAST | WAKE_MCAST)

#define PHY_READ		0x00000000
#define PHY_DATA_OR		0x10000000
#define PHY_DATA_AND		0x20000000
#define PHY_BJMPN		0x30000000
#define PHY_MDIO_CHG		0x40000000
#define PHY_CLEAR_READCOUNT	0x70000000
#define PHY_WRITE		0x80000000
#define PHY_READCOUNT_EQ_SKIP	0x90000000
#define PHY_COMP_EQ_SKIPN	0xa0000000
#define PHY_COMP_NEQ_SKIPN	0xb0000000
#define PHY_WRITE_PREVIOUS	0xc0000000
#define PHY_SKIPN		0xd0000000
#define PHY_DELAY_MS		0xe0000000


#define FW_OPCODE_SIZE	sizeof(typeof(*((struct rtl_fw_phy_action *)0)->code))

static void rtl8169_release_board(struct pci_dev *pdev, struct net_device *dev,
				  void __iomem * ioaddr)
{
	iounmap(ioaddr);
	pci_release_regions(pdev);
//	pci_clear_mwi(pdev);
	pci_disable_device(pdev);
	free_netdev(dev);
}

static void rtl8169_init_phy(struct net_device *dev, struct rtl8169_private *tp)
{
	pci_write_config_byte(tp->pci_dev, PCI_LATENCY_TIMER, 0x40);
}


static void rtl_init_rxcfg(struct rtl8169_private *tp)
{
	void __iomem *ioaddr = tp->mmio_addr;
	RTL_W32(RxConfig, RX128_INT_EN | RX_DMA_BURST);
}

static void rtl8169_init_ring_indexes(struct rtl8169_private *tp)
{
	tp->dirty_tx = tp->cur_tx = tp->cur_rx = 0;
}


DECLARE_RTL_COND(rtl_chipcmd_cond)
{
	void __iomem *ioaddr = tp->mmio_addr;
	return RTL_R8(ChipCmd) & CmdReset;
}


static void rtl_hw_reset(struct rtl8169_private *tp)
{
	void __iomem *ioaddr = tp->mmio_addr;
	PRINTK RTL_W8(ChipCmd, CmdReset);

	netdev_reset_queue(tp->dev);
}

static void rtl_rx_close(struct rtl8169_private *tp)
{
	void __iomem *ioaddr = tp->mmio_addr;

	RTL_W32(RxConfig, RTL_R32(RxConfig) & ~RX_CONFIG_ACCEPT_MASK);
}

static void rtl8169_hw_reset(struct rtl8169_private *tp)
{
	void __iomem *ioaddr = tp->mmio_addr;

	/* Disable interrupts */
	rtl8169_irq_mask_and_ack(tp);
	PRINTK rtl_rx_close(tp);
	RTL_W8(ChipCmd, RTL_R8(ChipCmd) | StopReq);
	udelay(100);
	rtl_hw_reset(tp);
}

static void rtl_set_rx_tx_config_registers(struct rtl8169_private *tp)
{
	void __iomem *ioaddr = tp->mmio_addr;

	/* Set DMA burst size and Interframe Gap Time */
	RTL_W32(TxConfig, (TX_DMA_BURST << TxDMAShift) |
		(InterFrameGap << TxInterFrameGapShift));
}

static void rtl_hw_start(struct net_device *dev)
{
	struct rtl8169_private *tp = netdev_priv(dev);
	PRINTK tp->hw_start(dev);

	rtl_irq_enable_all(tp);
}

static void rtl_set_rx_tx_desc_registers(struct rtl8169_private *tp,
					 void __iomem * ioaddr)
{
	RTL_W32(TxDescStartAddrHigh, ((u64) tp->TxPhyAddr) >> 32);
	RTL_W32(TxDescStartAddrLow, ((u64) tp->TxPhyAddr) & DMA_BIT_MASK(32));
	RTL_W32(RxDescAddrHigh, ((u64) tp->RxPhyAddr) >> 32);
	RTL_W32(RxDescAddrLow, ((u64) tp->RxPhyAddr) & DMA_BIT_MASK(32));
}

static void rtl_set_rx_max_size(void __iomem * ioaddr, unsigned int rx_buf_sz)
{
	/* Low hurts. Let's disable the filtering. */
	RTL_W16(RxMaxSize, rx_buf_sz + 1);
}

static void rtl_set_rx_mode(struct net_device *dev)
{
	struct rtl8169_private *tp = netdev_priv(dev);
	void __iomem *ioaddr = tp->mmio_addr;
	int rx_mode;
	u32 tmp = 0;
	u32 data = 0;
	PRINTK 

	rx_mode = AcceptBroadcast | AcceptMyPhys;

	if (dev->features & NETIF_F_RXALL)
		rx_mode |= (AcceptErr | AcceptRunt);

	tmp = (RTL_R32(RxConfig) & ~RX_CONFIG_ACCEPT_MASK) | rx_mode;

	RTL_W32(RxConfig, tmp);
}

struct ephy_info {
	unsigned int offset;
	u16 mask;
	u16 bits;
};


static void rtl_hw_start_8168(struct net_device *dev)
{
	struct rtl8169_private *tp = netdev_priv(dev);
	void __iomem *ioaddr = tp->mmio_addr;
	PRINTK RTL_W8(Cfg9346, Cfg9346_Unlock);

	RTL_W8(MaxTxPacketSize, TxPacketMax);

	rtl_set_rx_max_size(ioaddr, rx_buf_sz);

	RTL_W16(IntrMitigate, 0x5151);

	rtl_set_rx_tx_desc_registers(tp, ioaddr);

	rtl_set_rx_tx_config_registers(tp);

	RTL_R8(IntrMask);

	RTL_W8(Cfg9346, Cfg9346_Lock);

	RTL_W8(ChipCmd, CmdTxEnb | CmdRxEnb);

	rtl_set_rx_mode(dev);

	RTL_W16(MultiIntr, RTL_R16(MultiIntr) & 0xf000);
}


static void rtl8169_free_rx_databuff(struct rtl8169_private *tp,
				     void **data_buff, struct RxDesc *desc)
{
	dma_unmap_single(&tp->pci_dev->dev, le64_to_cpu(desc->addr), rx_buf_sz,
			 DMA_FROM_DEVICE);

	kfree(*data_buff);
	*data_buff = NULL;
}

static inline void rtl8169_mark_to_asic(struct RxDesc *desc, u32 rx_buf_sz)
{
	u32 eor = le32_to_cpu(desc->opts1) & RingEnd;

	desc->opts1 = cpu_to_le32(DescOwn | eor | rx_buf_sz);
}

static inline void rtl8169_map_to_asic(struct RxDesc *desc, dma_addr_t mapping,
				       u32 rx_buf_sz)
{
	desc->addr = cpu_to_le64(mapping);
	wmb();
	rtl8169_mark_to_asic(desc, rx_buf_sz);
}

static inline void *rtl8169_align(void *data)
{
	return (void *)ALIGN((long)data, 16);
}

static struct sk_buff *rtl8169_alloc_rx_data(struct rtl8169_private *tp,
					     struct RxDesc *desc)
{
	void *data;
	dma_addr_t mapping;
	struct device *d = &tp->pci_dev->dev;
	struct net_device *dev = tp->dev;
	int node = dev->dev.parent ? dev_to_node(dev->dev.parent) : -1;

	data = kmalloc_node(rx_buf_sz, GFP_KERNEL, node);
	if (!data)
		return NULL;

	if (rtl8169_align(data) != data) {
		kfree(data);
		data = kmalloc_node(rx_buf_sz + 15, GFP_KERNEL, node);
		if (!data)
			return NULL;
	}

	mapping = dma_map_single(d, rtl8169_align(data), rx_buf_sz,
				 DMA_FROM_DEVICE);
	if (unlikely(dma_mapping_error(d, mapping))) {
		if (net_ratelimit())
			netif_err(tp, drv, tp->dev, "Failed to map RX DMA!\n");
		goto err_out;
	}

	rtl8169_map_to_asic(desc, mapping, rx_buf_sz);
	return data;

 err_out:
	kfree(data);
	return NULL;
}

static void rtl8169_rx_clear(struct rtl8169_private *tp)
{
	unsigned int i;

	for (i = 0; i < NUM_RX_DESC; i++) {
		if (tp->Rx_databuff[i]) {
			rtl8169_free_rx_databuff(tp, tp->Rx_databuff + i,
						 tp->RxDescArray + i);
		}
	}
}

static inline void rtl8169_mark_as_last_descriptor(struct RxDesc *desc)
{
	desc->opts1 |= cpu_to_le32(RingEnd);
}

static int rtl8169_rx_fill(struct rtl8169_private *tp)
{
	unsigned int i;

	for (i = 0; i < NUM_RX_DESC; i++) {
		void *data;

		if (tp->Rx_databuff[i])
			continue;

		data = rtl8169_alloc_rx_data(tp, tp->RxDescArray + i);
		if (!data) {
			goto err_out;
		}
		tp->Rx_databuff[i] = data;
	}

	rtl8169_mark_as_last_descriptor(tp->RxDescArray + NUM_RX_DESC - 1);
	return 0;

 err_out:
	rtl8169_rx_clear(tp);
	return -ENOMEM;
}

static int rtl8169_init_ring(struct net_device *dev)
{
	struct rtl8169_private *tp = netdev_priv(dev);

	rtl8169_init_ring_indexes(tp);

	memset(tp->tx_skb, 0x0, NUM_TX_DESC * sizeof(struct ring_info));
	memset(tp->Rx_databuff, 0x0, NUM_RX_DESC * sizeof(void *));

	return rtl8169_rx_fill(tp);
}

static void rtl8169_unmap_tx_skb(struct device *d, struct ring_info *tx_skb,
				 struct TxDesc *desc)
{
	unsigned int len = tx_skb->len;

	dma_unmap_single(d, le64_to_cpu(desc->addr), len, DMA_TO_DEVICE);

	desc->opts1 = 0x00;
	desc->opts2 = 0x00;
	desc->addr = 0x00;
	tx_skb->len = 0;
}

static void rtl8169_tx_clear_range(struct rtl8169_private *tp, u32 start,
				   unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++) {
		unsigned int entry = (start + i) % NUM_TX_DESC;
		struct ring_info *tx_skb = tp->tx_skb + entry;
		unsigned int len = tx_skb->len;

		if (len) {
			struct sk_buff *skb = tx_skb->skb;

			rtl8169_unmap_tx_skb(&tp->pci_dev->dev, tx_skb,
					     tp->TxDescArray + entry);
			if (skb) {
				tp->dev->stats.tx_dropped++;
				dev_kfree_skb_any(skb);
				tx_skb->skb = NULL;
			}
		}
	}
}

static void rtl8169_tx_clear(struct rtl8169_private *tp)
{
	rtl8169_tx_clear_range(tp, tp->dirty_tx, NUM_TX_DESC);
	tp->cur_tx = tp->dirty_tx = 0;
}


static int rtl8169_xmit_frags(struct rtl8169_private *tp, struct sk_buff *skb,
			      u32 * opts)
{
	struct skb_shared_info *info = skb_shinfo(skb);
	unsigned int cur_frag, entry;
	struct TxDesc *uninitialized_var(txd);
	struct device *d = &tp->pci_dev->dev;
	entry = tp->cur_tx;
	for (cur_frag = 0; cur_frag < info->nr_frags; cur_frag++) {
		const skb_frag_t *frag = info->frags + cur_frag;
		dma_addr_t mapping;
		u32 status, len;
		void *addr;

		entry = (entry + 1) % NUM_TX_DESC;

		txd = tp->TxDescArray + entry;
		len = skb_frag_size(frag);
		addr = skb_frag_address(frag);
		mapping = dma_map_single(d, addr, len, DMA_TO_DEVICE);
		if (unlikely(dma_mapping_error(d, mapping))) {
			if (net_ratelimit())
				netif_err(tp, drv, tp->dev,
					  "Failed to map TX fragments DMA!\n");
			goto err_out;
		}

		/* Anti gcc 2.95.3 bugware (sic) */
		status = opts[0] | len |
		    (RingEnd * !((entry + 1) % NUM_TX_DESC));

		txd->opts1 = cpu_to_le32(status);
		txd->opts2 = cpu_to_le32(opts[1]);
		txd->addr = cpu_to_le64(mapping);

		tp->tx_skb[entry].len = len;
	}

	if (cur_frag) {
		tp->tx_skb[entry].skb = skb;
		txd->opts1 |= cpu_to_le32(LastFrag);
	}

	return cur_frag;

 err_out:
	rtl8169_tx_clear_range(tp, tp->cur_tx + 1, cur_frag);
	return -EIO;
}

static inline __be16 get_protocol(struct sk_buff *skb)
{
	__be16 protocol;
	if (skb->protocol == htons(ETH_P_8021Q))
		protocol = vlan_eth_hdr(skb)->h_vlan_encapsulated_proto;
	else
		protocol = skb->protocol;

	return protocol;
}


static netdev_tx_t rtl8169_start_xmit(struct sk_buff *skb,
				      struct net_device *dev)
{
unsigned char *ptr = NULL;
printk(KERN_INFO "\n inside start_xmit\n");
if (skb == NULL)
	return NETDEV_TX_OK;
else
{
	ptr = skb->data;
	printk(KERN_INFO "\n Data is :\n \t %s\n", ptr + 14);
}
#if 0
	struct rtl8169_private *tp = netdev_priv(dev);
	unsigned int entry = tp->cur_tx % NUM_TX_DESC;
	struct TxDesc *txd = tp->TxDescArray + entry;
	void __iomem *ioaddr = tp->mmio_addr;
	struct device *d = &tp->pci_dev->dev;
	dma_addr_t mapping;
	u32 status, len;
	u32 opts[2];
	int frags;
	if (unlikely(!TX_FRAGS_READY_FOR(tp, skb_shinfo(skb)->nr_frags))) {
		netif_err(tp, drv, dev,
			  "BUG! Tx Ring full when queue awake!\n");
		goto err_stop_0;
	}

	if (unlikely(le32_to_cpu(txd->opts1) & DescOwn))
		goto err_stop_0;

	opts[1] = 0;
	opts[0] = DescOwn;

	len = skb_headlen(skb);
	mapping = dma_map_single(d, skb->data, len, DMA_TO_DEVICE);
	if (unlikely(dma_mapping_error(d, mapping))) {
		if (net_ratelimit())
			netif_err(tp, drv, dev, "Failed to map TX DMA!\n");
		goto err_dma_0;
	}

	tp->tx_skb[entry].len = len;
	txd->addr = cpu_to_le64(mapping);

	frags = rtl8169_xmit_frags(tp, skb, opts);
	if (frags < 0)
		goto err_dma_1;
	else if (frags)
		opts[0] |= FirstFrag;
	else {
		opts[0] |= FirstFrag | LastFrag;
		tp->tx_skb[entry].skb = skb;
	}

	txd->opts2 = cpu_to_le32(opts[1]);

	netdev_sent_queue(dev, skb->len);

	skb_tx_timestamp(skb);

	wmb();

	status = opts[0] | len | (RingEnd * !((entry + 1) % NUM_TX_DESC));
	txd->opts1 = cpu_to_le32(status);

	tp->cur_tx += frags + 1;

	wmb();

	RTL_W8(TxPoll, NPQ);

	mmiowb();

	if (!TX_FRAGS_READY_FOR(tp, MAX_SKB_FRAGS)) {
		smp_wmb();
		netif_stop_queue(dev);
		smp_mb();
		if (TX_FRAGS_READY_FOR(tp, MAX_SKB_FRAGS))
			netif_wake_queue(dev);
	}

	return NETDEV_TX_OK;

 err_dma_1:
	rtl8169_unmap_tx_skb(d, tp->tx_skb + entry, txd);
 err_dma_0:
	dev_kfree_skb_any(skb);
	dev->stats.tx_dropped++;
	return NETDEV_TX_OK;

 err_stop_0:
	netif_stop_queue(dev);
	dev->stats.tx_dropped++;
	return NETDEV_TX_BUSY;
#endif
	return NETDEV_TX_OK;
}

static void rtl_tx(struct net_device *dev, struct rtl8169_private *tp)
{
	unsigned int dirty_tx, tx_left;
	unsigned int bytes_compl = 0, pkts_compl = 0;
	dirty_tx = tp->dirty_tx;
	smp_rmb();
	tx_left = tp->cur_tx - dirty_tx;

	while (tx_left > 0) {
		unsigned int entry = dirty_tx % NUM_TX_DESC;
		struct ring_info *tx_skb = tp->tx_skb + entry;
		u32 status;

		rmb();
		status = le32_to_cpu(tp->TxDescArray[entry].opts1);
		if (status & DescOwn)
			break;

		rtl8169_unmap_tx_skb(&tp->pci_dev->dev, tx_skb,
				     tp->TxDescArray + entry);
		if (status & LastFrag) {
			pkts_compl++;
			bytes_compl += tx_skb->skb->len;
			dev_kfree_skb_any(tx_skb->skb);
			tx_skb->skb = NULL;
		}
		dirty_tx++;
		tx_left--;
	}

	if (tp->dirty_tx != dirty_tx) {
		netdev_completed_queue(tp->dev, pkts_compl, bytes_compl);

		u64_stats_update_begin(&tp->tx_stats.syncp);
		tp->tx_stats.packets += pkts_compl;
		tp->tx_stats.bytes += bytes_compl;
		u64_stats_update_end(&tp->tx_stats.syncp);

		tp->dirty_tx = dirty_tx;
		smp_mb();
		if (netif_queue_stopped(dev) &&
		    TX_FRAGS_READY_FOR(tp, MAX_SKB_FRAGS)) {
			netif_wake_queue(dev);
		}
		if (tp->cur_tx != dirty_tx) {
			void __iomem *ioaddr = tp->mmio_addr;

			RTL_W8(TxPoll, NPQ);
		}
	}
}

static inline int rtl8169_fragmented_frame(u32 status)
{
	return (status & (FirstFrag | LastFrag)) != (FirstFrag | LastFrag);
}

static struct sk_buff *rtl8169_try_rx_copy(void *data,
					   struct rtl8169_private *tp,
					   int pkt_size, dma_addr_t addr)
{
	struct sk_buff *skb;
	struct device *d = &tp->pci_dev->dev;
	data = rtl8169_align(data);
	dma_sync_single_for_cpu(d, addr, pkt_size, DMA_FROM_DEVICE);
	prefetch(data);
	skb = netdev_alloc_skb_ip_align(tp->dev, pkt_size);
	if (skb)
		memcpy(skb->data, data, pkt_size);
	dma_sync_single_for_device(d, addr, pkt_size, DMA_FROM_DEVICE);

	return skb;
}


static int rtl_rx(struct net_device *dev, struct rtl8169_private *tp,
		  u32 budget)
{
	unsigned int cur_rx, rx_left;
	unsigned int count;
	struct sk_buff *skb;
	dma_addr_t addr;
	int pkt_size;
	cur_rx = tp->cur_rx;

	for (rx_left = min(budget, NUM_RX_DESC); rx_left > 0;
	     rx_left--, cur_rx++) {
		unsigned int entry = cur_rx % NUM_RX_DESC;
		struct RxDesc *desc = tp->RxDescArray + entry;
		u32 status;

		rmb();
		status = le32_to_cpu(desc->opts1) & tp->opts1_mask;

		if (status & DescOwn)
			break;
		
		addr = le64_to_cpu(desc->addr);
		if (likely(!(dev->features & NETIF_F_RXFCS)))
			pkt_size = (status & 0x00003fff) - 4;
		else
			pkt_size = status & 0x00003fff;

		skb = rtl8169_try_rx_copy(tp->Rx_databuff[entry],
						  tp, pkt_size, addr);
		if (!skb) {
			dev->stats.rx_dropped++;
			goto release_descriptor;
		}
		
		skb->ip_summed = CHECKSUM_UNNECESSARY;
		skb_put(skb, pkt_size);
		skb->protocol = eth_type_trans(skb, dev);
		napi_gro_receive(&tp->napi, skb);
		u64_stats_update_begin(&tp->rx_stats.syncp);
		tp->rx_stats.packets++;
		tp->rx_stats.bytes += pkt_size;
		u64_stats_update_end(&tp->rx_stats.syncp);
	
 release_descriptor:
		desc->opts2 = 0;
		wmb();
		rtl8169_mark_to_asic(desc, rx_buf_sz);
	}

	count = cur_rx - tp->cur_rx;
	tp->cur_rx = cur_rx;
	return count;
}

static irqreturn_t rtl8169_interrupt(int irq, void *dev_instance)
{
	struct net_device *dev = dev_instance;
	struct rtl8169_private *tp = netdev_priv(dev);
	int handled = 0;
	u16 status;
	status = rtl_get_events(tp);
	if (status && status != 0xffff) {
		status &= RTL_EVENT_NAPI;
		if (status) {
			handled = 1;
			rtl_irq_disable(tp);
			/*Schedule napi*/
			napi_schedule(&tp->napi);
		}
	}
	return IRQ_RETVAL(handled);
}

static int rtl8169_poll(struct napi_struct *napi, int budget)
{
	struct rtl8169_private *tp =
	    container_of(napi, struct rtl8169_private, napi);
	struct net_device *dev = tp->dev;
	u16 enable_mask = RTL_EVENT_NAPI;
	int work_done = 0;
	u16 status;
	status = rtl_get_events(tp);
	rtl_ack_events(tp, status);

	if (status & RTL_EVENT_NAPI_RX)
		work_done = rtl_rx(dev, tp, (u32) budget);

	if (status & RTL_EVENT_NAPI_TX)
		rtl_tx(dev, tp);

	if (work_done < budget) {
		napi_complete(napi);

		rtl_irq_enable(tp, enable_mask);
		mmiowb();
	}

	return work_done;
}

static void rtl8169_down(struct net_device *dev)
{
	struct rtl8169_private *tp = netdev_priv(dev);

	del_timer_sync(&tp->timer);
	napi_disable(&tp->napi);
	netif_stop_queue(dev);

	rtl8169_hw_reset(tp);

	synchronize_sched();

	rtl8169_tx_clear(tp);

	rtl8169_rx_clear(tp);

}

static int rtl8169_close(struct net_device *dev)
{
printk(KERN_INFO "\n inside rtl8169_close\n");
#if 0
	struct rtl8169_private *tp = netdev_priv(dev);
	struct pci_dev *pdev = tp->pci_dev;
	pm_runtime_get_sync(&pdev->dev);

	rtl8169_down(dev);

	free_irq(pdev->irq, dev);

	dma_free_coherent(&pdev->dev, R8169_RX_RING_BYTES, tp->RxDescArray,
			  tp->RxPhyAddr);
	dma_free_coherent(&pdev->dev, R8169_TX_RING_BYTES, tp->TxDescArray,
			  tp->TxPhyAddr);
	tp->TxDescArray = NULL;
	tp->RxDescArray = NULL;

	pm_runtime_put_sync(&pdev->dev);
#endif
	return 0;
}

static int rtl_open(struct net_device *dev)
{
printk(KERN_INFO "\n inside rtl_open\n");
#if 0
	struct rtl8169_private *tp = netdev_priv(dev);
	void __iomem *ioaddr = tp->mmio_addr;
	struct pci_dev *pdev = tp->pci_dev;
	int retval = -ENOMEM;
	PRINTK
	pm_runtime_get_sync(&pdev->dev);
	
	tp->TxDescArray = dma_alloc_coherent(&pdev->dev, R8169_TX_RING_BYTES,
					     &tp->TxPhyAddr, GFP_KERNEL);
	if (!tp->TxDescArray)
		goto err_pm_runtime_put;

	tp->RxDescArray = dma_alloc_coherent(&pdev->dev, R8169_RX_RING_BYTES,
					     &tp->RxPhyAddr, GFP_KERNEL);
	if (!tp->RxDescArray)
		goto err_free_tx_0;

	retval = rtl8169_init_ring(dev);
	if (retval < 0)
		goto err_free_rx_1;

	smp_mb();

	retval = request_irq(pdev->irq, rtl8169_interrupt,
			     IRQF_SHARED, dev->name, dev);

	if (retval < 0)
		goto err_release_fw_2;

	napi_enable(&tp->napi);

	rtl8169_init_phy(dev, tp);

	//__rtl8169_set_features(dev, dev->features);

	rtl_hw_start(dev);

	netif_start_queue(dev);

	pm_runtime_put_noidle(&pdev->dev);

	rtl8169_check_link_status(dev, tp, ioaddr);
 out:
	return retval;

 err_release_fw_2:
	rtl8169_rx_clear(tp);
 err_free_rx_1:
	dma_free_coherent(&pdev->dev, R8169_RX_RING_BYTES, tp->RxDescArray,
			  tp->RxPhyAddr);
	tp->RxDescArray = NULL;
 err_free_tx_0:
	dma_free_coherent(&pdev->dev, R8169_TX_RING_BYTES, tp->TxDescArray,
			  tp->TxPhyAddr);
	tp->TxDescArray = NULL;
 err_pm_runtime_put:
	pm_runtime_put_noidle(&pdev->dev);
	goto out;
#endif 
return 0;
}

static struct rtnl_link_stats64 *rtl8169_get_stats64(struct net_device *dev, struct rtnl_link_stats64
						     *stats)
{
	struct rtl8169_private *tp = netdev_priv(dev);
	unsigned int start;

	do {
		start = u64_stats_fetch_begin_irq(&tp->rx_stats.syncp);
		stats->rx_packets = tp->rx_stats.packets;
		stats->rx_bytes = tp->rx_stats.bytes;
	} while (u64_stats_fetch_retry_irq(&tp->rx_stats.syncp, start));

	do {
		start = u64_stats_fetch_begin_irq(&tp->tx_stats.syncp);
		stats->tx_packets = tp->tx_stats.packets;
		stats->tx_bytes = tp->tx_stats.bytes;
	} while (u64_stats_fetch_retry_irq(&tp->tx_stats.syncp, start));

	stats->rx_dropped = dev->stats.rx_dropped;
	stats->tx_dropped = dev->stats.tx_dropped;
	stats->rx_length_errors = dev->stats.rx_length_errors;
	stats->rx_errors = dev->stats.rx_errors;
	stats->rx_crc_errors = dev->stats.rx_crc_errors;
	stats->rx_fifo_errors = dev->stats.rx_fifo_errors;
	stats->rx_missed_errors = dev->stats.rx_missed_errors;

	return stats;
}

static void rtl8169_net_suspend(struct net_device *dev)
{
	struct rtl8169_private *tp = netdev_priv(dev);

	if (!netif_running(dev))
		return;
	netif_device_detach(dev);
	netif_stop_queue(dev);
	napi_disable(&tp->napi);
}

#define RTL8169_PM_OPS	NULL

static void rtl_shutdown(struct pci_dev *pdev)
{
	struct net_device *dev = pci_get_drvdata(pdev);
	struct rtl8169_private *tp = netdev_priv(dev);
	struct device *d = &pdev->dev;

	pm_runtime_get_sync(d);
	rtl8169_net_suspend(dev);

	rtl8169_hw_reset(tp);

	if (system_state == SYSTEM_POWER_OFF) {

		pci_wake_from_d3(pdev, true);
		pci_set_power_state(pdev, PCI_D3hot);
	}

	pm_runtime_put_noidle(d);
}

static void rtl_remove_one(struct pci_dev *pdev)
{
	struct net_device *dev = pci_get_drvdata(pdev);
	struct rtl8169_private *tp = netdev_priv(dev);

	//netif_napi_del(&tp->napi);

	unregister_netdev(dev);

#if 0
	if (pci_dev_run_wake(pdev))
		pm_runtime_get_noresume(&pdev->dev);
#endif	
	rtl8169_release_board(pdev, dev, tp->mmio_addr);
}

static const struct net_device_ops rtl_netdev_ops = {
	.ndo_open = rtl_open,
	.ndo_stop = rtl8169_close,
	.ndo_start_xmit = rtl8169_start_xmit,
#if 0
	.ndo_get_stats64 = rtl8169_get_stats64,
	.ndo_start_xmit = rtl8169_start_xmit,
	.ndo_validate_addr = eth_validate_addr,
#endif
};

static const struct rtl_cfg_info {
	void (*hw_start) (struct net_device *);
	unsigned int region;
	unsigned int align;
	u16 event_slow;
	unsigned features;
	u8 default_ver;
} rtl_cfg_infos = {
.hw_start = rtl_hw_start_8168,.region = 2,.align =
		    8,.event_slow = 0,.features =
		    0,.default_ver = 11,};


static int rtl_init_one(struct pci_dev *pdev, const struct pci_device_id *ent)
{
	const struct rtl_cfg_info *cfg = &rtl_cfg_infos;
	const unsigned int region = cfg->region;
	struct rtl8169_private *tp;
	struct net_device *dev;
	void __iomem *ioaddr;
	int i;
	int rc;
	printk(KERN_INFO "%s Gigabit Ethernet driver %s loaded\n", MODULENAME, RTL8169_VERSION);

printk(KERN_INFO "\n 1 \n");
	dev = alloc_etherdev(sizeof(*tp));
	if (!dev) {
		rc = -ENOMEM;
		goto out;
	}
	printk(KERN_EMERG "Modified r8169 driver\n");
	SET_NETDEV_DEV(dev, &pdev->dev);
	dev->netdev_ops = &rtl_netdev_ops;
	tp = netdev_priv(dev);
#if 0
	tp->dev = dev;
	tp->pci_dev = pdev;
#endif 
printk(KERN_INFO "\n 2 \n");
	pci_disable_link_state(pdev, PCIE_LINK_STATE_L0S | PCIE_LINK_STATE_L1 |
			       PCIE_LINK_STATE_CLKPM);

printk(KERN_INFO "\n 3 \n");
	/* enable device (incl. PCI PM wakeup and hotplug setup) */
	rc = pci_enable_device(pdev);
	if (rc < 0) {
		netif_err(tp, probe, dev, "enable failure\n");
		goto err_out_free_dev_1;
	}

#if 0
	if (pci_set_mwi(pdev) < 0)
		netif_info(tp, probe, dev, "Mem-Wr-Inval unavailable\n");
#endif
printk(KERN_INFO "\n 4 \n");
	/* make sure PCI base addr 1 is MMIO */
	if (!(pci_resource_flags(pdev, region) & IORESOURCE_MEM)) {
		netif_err(tp, probe, dev,
			  "region #%d not an MMIO resource, aborting\n",
			  region);
		rc = -ENODEV;
		goto err_out_mwi_2;
	}

#if 0
	/* check for weird/broken PCI region reporting */
	if (pci_resource_len(pdev, region) < R8169_REGS_SIZE) {
		netif_err(tp, probe, dev,
			  "Invalid PCI region size(s), aborting\n");
		rc = -ENODEV;
		goto err_out_mwi_2;
	}
#endif
printk(KERN_INFO "\n 5 \n");
	rc = pci_request_regions(pdev, MODULENAME);
	if (rc < 0) {
		netif_err(tp, probe, dev, "could not request regions\n");
		goto err_out_mwi_2;
	}

printk(KERN_INFO "\n 6 \n");
	/* ioremap MMIO region */
	ioaddr = ioremap(pci_resource_start(pdev, region), R8169_REGS_SIZE);
	if (!ioaddr) {
		netif_err(tp, probe, dev, "cannot remap MMIO, aborting\n");
		rc = -EIO;
		goto err_out_free_res_3;
	}

	tp->mmio_addr = ioaddr;

#if 0
	if (!pci_is_pcie(pdev))
		netif_info(tp, probe, dev, "not PCI Express\n");
	/* Identify chip attached to board */

	rtl_init_rxcfg(tp);

	rtl_irq_disable(tp);

	rtl_ack_events(tp, 0xffff);

#endif
printk(KERN_INFO "\n 7 \n");
	pci_set_master(pdev);

#if 0
	RTL_W8(Cfg9346, Cfg9346_Unlock);
	RTL_W8(Cfg9346, Cfg9346_Lock);

	tp->link_ok = rtl8169_link_ok;

	u64_stats_init(&tp->rx_stats.syncp);
	u64_stats_init(&tp->tx_stats.syncp);

#endif
printk(KERN_INFO "\n 8 \n");
	for (i = 0; i < ETH_ALEN; i++)
		dev->dev_addr[i] = RTL_R8(MAC0 + i);

#if 0
	dev->watchdog_timeo = RTL8169_TX_TIMEOUT;

	/*Adding NAPI*/
	//netif_napi_add(dev, &tp->napi, rtl8169_poll, R8169_NAPI_WEIGHT);

#endif

printk(KERN_INFO "\n 9 \n");
	dev->features |= NETIF_F_RXCSUM;

	dev->hw_features = 0;
	dev->vlan_features = 0;

	dev->hw_features |= NETIF_F_RXALL;
	dev->hw_features |= NETIF_F_RXFCS;

#if 0
	tp->hw_start = cfg->hw_start;

	tp->opts1_mask = ~0;

	init_timer(&tp->timer);

	tp->timer.data = (unsigned long)dev;

#endif
printk(KERN_INFO "\n 10 \n");
	rc = register_netdev(dev);
	if (rc < 0)
		goto err_out_msi_4;

printk(KERN_INFO "\n 11 \n");
	pci_set_drvdata(pdev, dev);

#if 0

	if (pci_dev_run_wake(pdev))
		pm_runtime_put_noidle(&pdev->dev);

	netif_carrier_off(dev);

#endif

 out:
	return rc;

 err_out_msi_4:
	//netif_napi_del(&tp->napi);
	iounmap(ioaddr);
 err_out_free_res_3:
	pci_release_regions(pdev);
 err_out_mwi_2:
	pci_clear_mwi(pdev);
	pci_disable_device(pdev);
 err_out_free_dev_1:
	free_netdev(dev);
	goto out;
}

static struct pci_driver rtl8169_pci_driver = {
	.name = MODULENAME,
	.id_table = rtl8169_pci_tbl,
	.probe = rtl_init_one,
	.remove = rtl_remove_one,
#if 0
	.shutdown = rtl_shutdown,
#endif
};

module_pci_driver(rtl8169_pci_driver);
