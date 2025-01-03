#include"headers.h"
#include"declarations.h"
int openMyCDD(struct inode *pin, struct file *pfi)
{
	Device *ldev;
	printk(KERN_INFO "FILE:%s -> %s:Begin\n",__FILE__,__func__);
	ldev=container_of(pin->i_cdev, Device, mycdev);
	if(!ldev)
	{
		printk(KERN_ERR "Error: container_of failed\n");
		return 0;
	}
	printk(KERN_INFO "Container is embedded successfully\n");

	printk(KERN_INFO "FILE:%s -> %s:End\n",__FILE__,__func__);
	return 0;
}
