#include"headers.h"
#include"declarations.h"
ssize_t writeMyCDD(struct file *pfi, const char __user *buff, size_t bytes, loff_t *offset)
{
	printk(KERN_INFO "FILE:%s -> %s:Begin\n",__FILE__,__func__);


	printk(KERN_INFO "FILE:%s -> %s:End\n",__FILE__,__func__);
	return 0;
}
