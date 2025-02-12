#include"headers.h"
#include"declarations.h"
loff_t lseekMyCDD(struct file *pfi, loff_t offset, int origin)
{
	Device *ldev;
	printk(KERN_INFO "FILE:%s -> %s:Begin\n",__FILE__,__func__);
	ldev=pfi->private_data;
	if(ldev->dataSize==0)
	{
		printk(KERN_INFO "Device file is empty hence no seeking is allowed\n");
		goto out;
	}
	//crictical region. synchronize using completion interruptible
	if(wait_for_completion_interruptible(&ldev->kcom)==-1)
		return -ERESTARTSYS;
	switch(origin)
	{
		case 0:
			if(offset>ldev->dataSize || offset<0)
			{
				printk(KERN_ERR "Offset is larger than the data in the device\n");
				goto out;
			}
			pfi->f_pos=offset;
			break;
		case 1:
			if(offset > (ldev->dataSize-pfi->f_pos) || offset < (pfi->f_pos * -1))//checking both negative and positive offsets, if they are eceeding the limit
			{
				printk(KERN_ERR "Offset is larger than the data in the device\n");
				goto out;
			}
			pfi->f_pos=pfi->f_pos+offset;
			break;
		case 2:
			if(offset<ldev->dataSize * -1 || offset>0)
			{
				printk(KERN_ERR "Offset is larger than the data in the device\n");
				goto out;
			}
			pfi->f_pos=ldev->dataSize+offset;//adding with the f_pos of SEEK_END(which is end of the file)
			break;
	}
	complete(&ldev->kcom);

	printk(KERN_INFO "FILE:%s -> %s:End\n",__FILE__,__func__);
	return 0;
out:	printk(KERN_ERR "ERROR: FILE:%s -> %s:End\n",__FILE__,__func__);
	return -1;
}
