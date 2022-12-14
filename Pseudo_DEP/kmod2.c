#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/sched.h>
#include <linux/cdev.h>
#include <asm/uaccess.h>
#include <linux/device.h>
#include <linux/slab.h>

MODULE_LICENSE ("Dual BSD/GPL");

//Function definitions for system call definitions

int add ( int a, int b );

//myinit: init function for kernel module

static int __init myInit (void)
{

	printk (KERN_INFO "Hello World...!! from kmod2\n");
	printk ("in kmod2.c--> c: %d\n", add(2,3) );
	return 0;

}

static void myExit (void)
{

	printk (KERN_INFO "Bye...!! from kmod2\n");
	return;
}

module_init (myInit);
module_exit (myExit);

