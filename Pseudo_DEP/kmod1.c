#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/sched.h>
#include <linux/cdev.h>
#include <asm/uaccess.h>
#include <linux/device.h>
#include <linux/slab.h>

MODULE_LICENSE ("Dual BSD/GPL");

int add ( int a, int b )
{

	int c = 0;

	printk("in kmod1.c a: %d b: %d\n", a, b );
	c = a + b;
	printk ("in kmod1.c--> c: %d\n", c );

	return c;

}

EXPORT_SYMBOL ( add );

//myinit: init function for kernel module

static int __init myInit (void)
{

	printk (KERN_INFO "Hello World...!! from kmod1\n");
	return 0;

}


static void myExit (void)
{

	printk (KERN_INFO "Bye...!! from kmod1\n");
	return;
}

module_init (myInit);
module_exit (myExit);


