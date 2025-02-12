#include"headers.h"
#include"declarations.h"
ssize_t writeMyCDD(struct file *pfi, const char __user *ubuff, size_t size, loff_t *offset)
{
	int i,j,no_quantums,lsize,rem_size,wret,nob_tocopy,nob_wrote;
	Device *ldev;
	Item *l_item;
	printk(KERN_INFO "FILE:%s -> %s:Begin\n",__FILE__,__func__);
	ldev=pfi->private_data;
	if(size<=ldev->devSize)
		lsize=size;
	else
		lsize=ldev->devSize;

	l_item=ldev->item=createScull(ldev,lsize);//creating scull
	if(l_item==0)
	{
		printk(KERN_ERR "Error: SCULL creation failed!\n");
		goto out;
	}
	//calculating no. of quantums required
	no_quantums=lsize/ldev->regSize;
	if(no_quantums%ldev->regSize != 0)
		no_quantums++;
	//write operation
	rem_size=lsize;
	nob_wrote=0;
	for(i=j=0;j<no_quantums;j++)
	{
		nob_tocopy=ldev->regSize;//no. of bytes to copy
		if(rem_size<ldev->regSize)
		{	
			nob_tocopy=rem_size;
		}
		//critical section
		down(&ldev->ksem);//semaphore decrement(wait)
		wret=copy_from_user(l_item->data[i],ubuff+nob_wrote,nob_tocopy);
		if(wret==-1)
		{
			trimMyCDD(ldev);
			printk(KERN_ERR "Error: copy_from_user failed!\n");
			goto out;
		}
		up(&ldev->ksem);//semaphore increment
		rem_size = rem_size - (nob_tocopy-wret);//remaining size/bytes to copy;
		nob_wrote=nob_wrote+nob_tocopy-wret;
		if(i==ldev->noofReg-1)//if all the quantums in a item are filled
		{
			i=0;
			l_item=l_item->next;
		}
		else
			i++;
	}
	//printk(KERN_INFO "Data at 1st quantum:%s\n",ldev->item->data[0]);
	//printk(KERN_INFO "Data at 2nd quantum:%s\n",ldev->item->next->data[2]);
	
	ldev->dataSize=nob_wrote;
	pfi->f_pos=nob_wrote;
	printk(KERN_INFO "FILE:%s -> %s:End\n",__FILE__,__func__);
	return nob_wrote;
out:
	printk(KERN_INFO "FILE:%s -> %s:End\n",__FILE__,__func__);
	return -1;
}
