#include	<linux/init.h>
#include	<linux/module.h>
#include	<linux/mm.h>
#include	<linux/fs.h>
#include	<linux/sched.h>
#include	<linux/cdev.h>
#include	<asm/uaccess.h>
#include	<linux/device.h>
#include	<linux/slab.h>
#include	<asm/pgtable-2level_types.h>
#include	<linux/highmem.h>
#include	<linux/list.h>
#include	<linux/netdevice.h>
#include <linux/errno.h>    /* error codes */
#include <linux/types.h>    /* size_t */


MODULE_LICENSE("Dual BSD/GPL");

/** Constants **/
#define FIRST_MINOR	10
#define NR_DEVS 1		//Number of device numbers

//Function Declarations for syscall definitions

int myOpen(struct inode *inode, struct file *filep);
int myRelease(struct inode *in, struct file *fp);
int mymmap(struct file *fp, struct vm_area_struct *vma);	
long myIoctl(struct file *fd,unsigned int pid,unsigned long n);

//InitiaLIZATION ROUTINES

static int myInit(void);
static void myExit(void);

struct file_operations fops = {
	.owner = THIS_MODULE,
	.open = myOpen,
	.release = myRelease,
	.mmap = mymmap,
	.unlocked_ioctl = myIoctl,
};

/*Global variables */
char *devname;					//contains device name
int majNo;
static dev_t mydev;				// encodes major number and minor number 
struct cdev *my_cdev;			// holds character device driver descriptor
/* To accept input from command line */
module_param(devname, charp, 0000);

// class and device structures 

static struct class *mychar_class;
static struct device *mychar_device;

/* 
 * myopen: open function of the pseudo driver 
 *
 */

int myOpen(struct inode *inode, struct file *filep)
{

	printk( KERN_INFO "Open succesful\n");
	return 0;
}

/*
 * myRelease : close function of the pseudo driver 
 *
 */

int myRelease(struct inode *in, struct file *fp)
{
	printk(KERN_INFO "File released\n");
	return 0;
}

/* myInit : init function of the kernel module 
 *
 */
static int __init myInit(void)
{
	int ret = -ENODEV;
	int status;

	printk(KERN_INFO "Initializing Character Device\n");

	//Allocating Device NUmbers 

	status = alloc_chrdev_region(&mydev, FIRST_MINOR, NR_DEVS, devname);
	if (status < 0) {
		printk(KERN_NOTICE "Device numbers allocation failed %d \n",
				status);
		goto err;

	}
	printk("mydev is %d\n", mydev);
	printk(KERN_INFO "Major number allocated = %d \n ", MAJOR(mydev));
	my_cdev = cdev_alloc();	//Allocate memory for my_cdev;
	if (my_cdev == NULL) {
		printk(KERN_ERR "cdev_alloc failed\n");
		goto err_cdev_alloc;
	}

	cdev_init(my_cdev, &fops);	// Initialize my_cdev with fops
	my_cdev->owner = THIS_MODULE;

	status = cdev_add(my_cdev, mydev, NR_DEVS);	//Add my_cdev to the list
	if (status) {
		printk(KERN_ERR "cdev_add failed\n");
		goto err_cdev_add;
	}
	printk("status is %d\n", status );

	// create class and entry in sysfs 

	mychar_class = class_create(THIS_MODULE, devname);
	if (IS_ERR(mychar_class)) {
		printk(KERN_ERR "class_create() failed \n");
		goto err_class_create;
	}
	//creates mychar_device in sysfs and an
	//device entry willl be made in /dev directory
	mychar_device = device_create(mychar_class, NULL, mydev, NULL, devname);
	if (IS_ERR(mychar_device)) {
		printk(KERN_ERR "device_create() failed\n");
		goto err_device_create;
	}
	return 0;
err_device_create:
	class_destroy(mychar_class);

err_class_create:
	cdev_del(my_cdev);
err_cdev_add:
	kfree(my_cdev);

err_cdev_alloc:
	unregister_chrdev_region(mydev, NR_DEVS);
err:
	return ret;
}

/*
 * myExit:cleanup function of the kernel module
 */
static void myExit(void)
{
	printk(KERN_INFO "Exiting the Character Driver\n");

	device_destroy(mychar_class, mydev);
	class_destroy(mychar_class);
	cdev_del(my_cdev);
	unregister_chrdev_region(mydev, NR_DEVS);

	return;
}

/* myIoctl : Ioctl function of the pseudo driver 
 *
 */

long myIoctl( struct file *fd, unsigned int pid, unsigned long var_for_walk )
{
	struct net_device *my_net	 = NULL;	//Pointer to task_struct 

	list_for_each_entry( my_net, &(init_net.dev_base_head), dev_list) { 
		printk ("Name = %s\n", my_net->name);
	/*	int i = 0;
		for ( i = 0 ; my_net->name[i] != '\0'; i++){
			
			printk ( "%d\n", my_net->name[i]);
		}*/
	}

	return 0;

}
int mymmap(struct file *fp, struct vm_area_struct *vma)
{
        printk ("In Side mymmap\n");
        unsigned int pg_add = (0xf7c00000) >> PAGE_SHIFT;
      //  int pg_add = (0xd000) >> PAGE_SHIFT;
        if (remap_pfn_range(vma, vma->vm_start,
			 pg_add,4096,vma->vm_page_prot))
	        return -EAGAIN;

	
	
}

module_init(myInit);
module_exit(myExit);
