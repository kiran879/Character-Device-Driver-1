#include"headers.h"
#include"declarations.h"
ssize_t readMyCDD(struct file *pfi, char __user *buff, size_t size, loff_t *offset)
{
	int i,j,no_quantums,lsize,rem_size,ret,nob_toRead,nob_read;
        Device *ldev;
        Item *l_item;
	loff_t l_offset=0;
	int start_offset;//byte position inside the quantum

        printk(KERN_INFO "FILE:%s -> %s:Begin\n",__FILE__,__func__);
        ldev=pfi->private_data;
	l_item=ldev->item;
	if(*offset>0)
		l_offset=*offset-1;//to start reading exactly from the offset
        if(size<=ldev->dataSize)
                lsize=size;
        else
                lsize=ldev->dataSize;

        //calculating no. of quantums used to read
        no_quantums=lsize/ldev->regSize;
        if(no_quantums%ldev->regSize != 0)
                no_quantums++;
        //read operation
        rem_size=lsize;//remaining size to read
        nob_read=0;//number of bytes already read
	//adjusting item number and quantum according to the offset
	printk(KERN_INFO "offset: %lld\n",*offset);
	for(i=0;i<(l_offset/(ldev->noofReg*ldev->regSize));i++)//adjusting item number according to the offset to start reading
	{
		l_item=l_item->next;
	}
	//finding out ith quantum in the item to start reading
	i=l_offset/ldev->regSize;
	i=i%ldev->noofReg;

	start_offset=l_offset % ldev->regSize;//to start reading from byte position inside the quantum.
	//iterating number of qauntums time to read all the required data
        for(j=l_offset/ldev->regSize;j<no_quantums;j++)
        {
                nob_toRead=ldev->regSize;//no. of bytes to copy
                if(rem_size<ldev->regSize)
                {    
                        nob_toRead=rem_size;
                }
		if(start_offset>0)//adjusting number of bytes to in first iterating depending on the byte position in the quantum
			nob_toRead=ldev->regSize-start_offset;
                ret=copy_to_user(buff+nob_read,l_item->data[i]+start_offset,nob_toRead);
		if(ret==-1)
                {
                        trimMyCDD(ldev);
                        printk(KERN_ERR "Error: copy_to_user failed!\n");
                        goto out;
                }

                rem_size = rem_size - (nob_toRead-ret);//remaining size/bytes to copy;
                nob_read=nob_read+nob_toRead-ret;
                if(i==ldev->noofReg-1)//if all the quantums in a item are filled
                {
                        i=0;
                        l_item=l_item->next;
                }
                else
                        i++;
     		start_offset=0;//making zero inorder not to change nob_toRead in rest of the iterations
	}
	//pfi->f_pos=pfi->f_pos+(loff_t)nob_read;
	printk(KERN_INFO "Testing: f_pos:%lld\n",pfi->f_pos);
        printk(KERN_INFO "FILE:%s -> %s:End\n",__FILE__,__func__);
        return nob_read;
out:
        printk(KERN_INFO "FILE:%s -> %s:End\n",__FILE__,__func__);
        return -1;
}
