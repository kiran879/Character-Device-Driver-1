#include"headers.h"
#include"declarations.h"
long ioctlMyCDD (struct file *pfi, unsigned int command, unsigned long arg)
{
	Device *ldev;
	printk(KERN_INFO "FILE:%s -> %s:Begin\n",__FILE__,__func__);
	ldev=pfi->private_data;
	switch(command)
	{
		case DEVRESET:
			printk(KERN_INFO "Inside Device Reset command\n");
			ldev->devSize = DEVSIZE;
			ldev->regSize = REGSIZE;
			ldev->noofReg = NOOFREG;
			ldev->dataSize = DATASIZE;
			break;
		default:
			printk(KERN_INFO "Default case invoked\n");

	}

	printk(KERN_INFO "FILE:%s -> %s:End\n",__FILE__,__func__);
	return 0;
out:
	printk(KERN_ERR "FILE:%s -> %s:ERROR\n",__FILE__,__func__);
	return -1;
	
}
