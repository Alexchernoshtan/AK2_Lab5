#include <linux/init.h>
#include <linux/module.h>
#include <linux/printk.h>

#include "hello1.h"

int print_hello(uint num)
{
	if (num == 0) {
		pr_warn("Small value!\n");
	}
	else if (num > 5 && num <= 10) {
		pr_warn("Big value!\n");
	} 
	else if (num > 0 && num <= 5) {
		int i;
		for (i = 0; i < num; i++) {
			pr_alert("Hello, world!\n");
		}
	}
	else {
		pr_err("Invalid value!\n");
		return -EINVAL;
	}
	return 0;
}
EXPORT_SYMBOL(print_hello);

static int __init hello1_init(void)
{
	pr_alert("hello1 started!\n");
	return 0;
}

static void __exit hello1_exit(void)
{
	pr_alert("hello1 closed!\n");
}

module_init(hello1_init);
module_exit(hello1_exit);

MODULE_AUTHOR("Herman Ananenko <example@exmpl.com>");
MODULE_DESCRIPTION("Hello, world in Linux Kernel Training. Part 1.");
MODULE_LICENSE("Dual BSD/GPL");
