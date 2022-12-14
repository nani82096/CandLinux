#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/sched.h>
#include <linux/cdev.h>
#include <asm/uaccess.h>
#include <linux/device.h>
#include <linux/slab.h>
#include <linux/mm.h>
#include <linux/thread_info.h>
#include <linux/highmem.h>


MODULE_LICENSE ("Dual BSD/GPL");

#define FIRST_MINOR	10
#define NR_DEVS 1	//	Number of device numbers

//Function definitions for system call definitions

long myioctl(int , unsigned int );
int myOpen (struct inode *inode,struct file *filep);
int myRelease (struct inode *in,struct file *fp);
void *kmap(struct page *page);
//Initioalization routines

static int myInit (void);
static void myExit (void);

struct file_operations fops = {
	.owner	=	THIS_MODULE,
	.open	=	myOpen,
	.unlocked_ioctl = myioctl,
	.release=	myRelease
};

//Global variables

char *devname;		//Device name
int majNo;			
static dev_t mydev;	//encodes device major and minor number
struct cdev *my_cdev;	//Holds character device driver descriptor

module_param (devname, charp, 0000);

//Class and device structures

static struct class *mychar_class;
static struct device *mychar_device;

//myOpen: Open function for sudo drivers

int myOpen (struct inode *inode, struct file *filep)
{	
	printk (KERN_INFO "Open successful\n");
	return 0;
}
//myIoctl: open ioctl 
long myioctl ( int fd, unsigned int pid)
{
	struct task_struct *task1 = current;
	unsigned int  *mypgd ;
	mypgd = task1->mm->pgd;
	unsigned int *mypte;
	int i = 0;
	int j = 0;
	int pt_cnt = 0;
	int count = 0;
//	printk("%u\t%u\t%u\n",PTRS_PER_PGD,PTRS_PER_PMD,PTRS_PER_PTE);
	while(i < (PTRS_PER_PGD - 256)){
		if ((*mypgd)){
			pt_cnt++;
			printk("PGD  [%d] = %8x\n", i , *mypgd);

			mypte =  kmap( (mem_map + (((*mypgd) & PAGE_MASK) >> PAGE_SHIFT)));
			for(j = 0; j <  PTRS_PER_PTE; j++,mypte++) {
				if(*mypte ) {
					printk("PT Entries \t\t%d = %8x \n", j, *(mypte));
					count++;
				}
			}
		}
		mypgd++;
		i++;
		
	}
	printk ("PT Page Count = %d\n", pt_cnt);
	printk ("Pages count  = %d\n",count);
	return 0;

}
//myRelease: Close function for sudo drivers

int myRelease (struct inode *in, struct file *fp)
{
	printk (KERN_INFO "File released \n");
	return 0;
}

//myinit: init function for kernel module

static int __init myInit (void)
{
	int ret	=	-ENODEV;
	int status;

	printk (KERN_INFO "Initializing Character Device \n");

//Allocationg device numbers

	status	=	alloc_chrdev_region (&mydev, FIRST_MINOR, NR_DEVS, devname);

	if (status < 0)
	{
		printk (KERN_NOTICE "Device numbers allocation failed: %d \n",status);
		goto err;
	}
	printk (KERN_INFO "Major number allocated = %d \n",MAJOR(mydev));
	my_cdev	=	cdev_alloc ();	//allocate memory for my_cdev
	
	if (my_cdev == NULL) {
		printk (KERN_ERR "cdev_alloc failed \n");
		goto err_cdev_alloc;
	}

	cdev_init (my_cdev, &fops);	//initialize my_cdev with fops
	my_cdev->owner	=	THIS_MODULE;	//Add my_cdev to list

	status	=	cdev_add (my_cdev, mydev, NR_DEVS);
	if (status) {
		printk (KERN_ERR "cdev_add failed \n");
		goto err_cdev_add;
	}

//create a class and entry in sysfs

	mychar_class	=	class_create (THIS_MODULE, devname);
	if (IS_ERR(mychar_class)) {
		printk (KERN_ERR "class_create() failed \n");
		goto err_class_create;
	}

//create mychar_device in sysfs and a device entry will be made in /dev directory

	mychar_device =	device_create (mychar_class, NULL, mydev, NULL, devname);
	if (IS_ERR(mychar_device)) {
		printk (KERN_ERR "device_create() failed \n");
		goto err_device_create;
	}

return 0;

err_device_create:
	class_destroy (mychar_class);

err_class_create:
	cdev_del(my_cdev);

err_cdev_add:
	kfree (my_cdev);

err_cdev_alloc:
	unregister_chrdev_region (mydev, NR_DEVS);

err:
	return ret;
}


static void myExit (void)
{
	printk (KERN_INFO "Exiting the Character Driver \n");

	device_destroy (mychar_class, mydev);
	class_destroy (mychar_class);
	cdev_del (my_cdev);
	unregister_chrdev_region (mydev, NR_DEVS);

	return;
}

module_init (myInit);
module_exit (myExit);

