#include"headers.h"
#include"declarations.h"
ssize_t writeMyCDD(struct file *pfi, const char __user *ubuff, size_t size, loff_t *offset)
{
	int i,j,no_quantums,lsize,rem_size,wret,nob_tocopy;
	Device *ldev;
	Item *l_item;
	printk(KERN_INFO "FILE:%s -> %s:Begin\n",__FILE__,__func__);
	ldev=pfi->private_data;
	if(size<=ldev->devSize)
		lsize=size;
	else
		lsize=ldev->devSize;

	l_item=ldev->item=createScull(ldev,lsize);//creating scull
	//calculating no. of quantums required
	no_quantums=lsize/ldev->regSize;
	if(no_quantums%ldev->regSize != 0)
		no_quantums++;
	//write operation
	rem_size=lsize;
	for(i=j=0;j<no_quantums;j++)
	{
		nob_tocopy=ldev->regSize;//no. of bytes to copy
		if(rem_size<ldev->regSize)
		{	
			nob_tocopy=rem_size;
		}
		wret=copy_from_user(l_item->data[i],__user ubuff,nob_tocopy);
		if(wret==-1)
		{
			trimMyCDD(ldev);
			printk(KERN_ERR "Error: copy_from_user failed!\n");
			goto out;
		}
		rem_size = rem_size - (ldev->regSize-wret);//remaining size/bytes to copy;
		if(i==ldev->noofReg-1)//if all the quantums in a item are filled
		{
			i=0;
			l_item=l_item->next;
		}
		else
			i++;
	}
	printk(KERN_INFO "Data at 1st quantum:%s\n",ldev->item->data[0]);
	printk(KERN_INFO "Data at 2nd quantum:%s\n",ldev->item->next->data[2]);

out:
	printk(KERN_INFO "FILE:%s -> %s:End\n",__FILE__,__func__);
	return 0;
}
