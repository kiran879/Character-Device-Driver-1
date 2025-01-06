#include"headers.h"
#include"declarations.h"
int openMyCDD(struct inode *pin, struct file *pfi)
{
	Device *ldev;
	printk(KERN_INFO "FILE:%s -> %s:Begin\n",__FILE__,__func__);
	//container_of(): provides a pointer refering to both kernel space,user space, IO space
	ldev=container_of(pin->i_cdev, Device, mycdev);
	if(!ldev)
	{
		printk(KERN_ERR "Error: container_of failed\n");
		return 0;
	}
	printk(KERN_INFO "Container is embedded successfully\n");
	//ldev will be lost once this routine exits
	//therefore preserving the ldev in struct file's private_data for the further usage 
	pfi->private_data=ldev;

	//checking if the device is opened in which mode
	//perform respective tast for each mode
	if((pfi->f_flags & O_ACCMODE) == O_WRONLY)
	{
		trimMyCDD(ldev);
	}
	printk(KERN_INFO "FILE:%s -> %s:End\n",__FILE__,__func__);
	return 0;
}
