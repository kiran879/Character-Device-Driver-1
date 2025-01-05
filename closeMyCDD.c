#include"headers.h"
#include"declarations.h"
int closeMyCDD(struct inode *pin,struct file *pfi)
{
	printk(KERN_INFO "FILE:%s -> %s:Begin\n",__FILE__,__func__);


	printk(KERN_INFO "FILE:%s -> %s:End\n",__FILE__,__func__);
	return 0;
}
