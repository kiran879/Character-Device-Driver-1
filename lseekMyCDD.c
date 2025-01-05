#include"headers.h"
#include"declarations.h"
loff_t lseekMyCDD(struct file *pfi, loff_t offset, int pos)
{
	printk(KERN_INFO "FILE:%s -> %s:Begin\n",__FILE__,__func__);


	printk(KERN_INFO "FILE:%s -> %s:End\n",__FILE__,__func__);
	return 0;
}
