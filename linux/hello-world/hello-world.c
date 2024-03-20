#include <linux/init.h>
#include <linux/module.h>
#include <linux/uaccess.h>
#include <linux/fs.h>
#include <linux/proc_fs.h>

MODULE_AUTHOR("Misomosi");
MODULE_DESCRIPTION("Hello World Driver!");
MODULE_LICENSE("GPL");

static int __init hello_init(void)
{
	printk(KERN_INFO "HELLO WORLD DRIVER!\n");
	return 0;
}

static void __exit hello_fini(void)
{
	printk(KERN_INFO "GOODBYE WORLD! I'LL BE BACK!\n");
}

module_init(hello_init);
module_exit(hello_fini);
