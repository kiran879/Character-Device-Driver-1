#include"headers.h"
#include"declarations.h"
ssize_t readMyCDD(struct file *pfi, char __user *buff, size_t size, loff_t *offset)
{
	int i,j,no_quantums,lsize,rem_size,ret,nob_toRead,nob_read;
        Device *ldev;
        Item *l_item;
        printk(KERN_INFO "FILE:%s -> %s:Begin\n",__FILE__,__func__);
        ldev=pfi->private_data;
	l_item=ldev->item;
        if(size<=ldev->dataSize)
                lsize=size;
        else
                lsize=ldev->dataSize;

        //calculating no. of quantums used to read
        no_quantums=lsize/ldev->regSize;
        if(no_quantums%ldev->regSize != 0)
                no_quantums++;
        //read operation
        rem_size=lsize;
        nob_read=0;
        for(i=j=0;j<no_quantums;j++)
        {
                nob_toRead=ldev->regSize;//no. of bytes to copy
                if(rem_size<ldev->regSize)
                {    
                        nob_toRead=rem_size;
                }
                ret=copy_to_user(buff+nob_read,l_item->data[i],nob_toRead);
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
        }

        printk(KERN_INFO "FILE:%s -> %s:End\n",__FILE__,__func__);
        return nob_read;
out:
        printk(KERN_INFO "FILE:%s -> %s:End\n",__FILE__,__func__);
        return -1;
}
