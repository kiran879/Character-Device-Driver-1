#include"headers.h"
#include"declarations.h"
int trimMyCDD(Device *dev)
{
	Item *last,*slast;
	int i,temp=0;
	printk(KERN_INFO "FILE:%s -> %s:Begin\n",__FILE__,__func__);
	last=slast=dev->item;
	while(last)
	{
		printk(KERN_INFO "inside top while\n");
		while(last->next)
		{
			printk(KERN_INFO "inside 2nd while\n");
			slast=last;
			last=last->next;
		}
		if(last->data)
		{
			for(i=dev->noofReg-1;i>=0;i--)
			{
				if(last->data[i])
				{
					kfree(last->data[i]);
					last->data[i]=NULL;
				}
			}
			kfree(last->data);
			last->data=NULL;
		}
		if(last==dev->item)//this implies we are on the first item
			dev->item=NULL;//inorder to make the myDevice's item to NULL,if we don't try to make this null it would be pointing some address that is freed and while loop will not gets terminated because we are assigning this item to 'last'
		kfree(last);
		slast->next=NULL;

		last=slast=dev->item;
		/*testing purpose
		if(temp==10)
			break;
		temp++;
		*/
	}
	dev->dataSize=0;

	printk(KERN_INFO "FILE:%s -> %s:End\n",__FILE__,__func__);
	return 0;
}
