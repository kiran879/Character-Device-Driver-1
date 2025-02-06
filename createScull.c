#include"headers.h"
#include"declarations.h"
Item* createScull(Device *dev,int size)
{	int item_size,no_items,no_quantums,i,j;
	Item *first,*last;
	printk(KERN_INFO "FILE:%s -> %s:Begin\n",__FILE__,__func__);
	//to find no.of Items required
	item_size= dev->noofReg * dev->regSize;
	no_items=size/item_size;
	if(size%item_size!=0)
		no_items++;
	//creating items
	last=first=(Item*)kmalloc(sizeof(Item),GFP_KERNEL);//first item
	if(!first)
	{
		printk(KERN_ERR "Error: item-1 allocation failed!\n");
		goto out;
	}
	memset(last,'\0',sizeof(Item));
	//last->next=NULL;
	for(i=1;i<no_items;i++)
	{
		last->next=(Item*)kmalloc(sizeof(Item),GFP_KERNEL);
		if(!last->next)
		{
			printk(KERN_ERR "Error: item-%d allocation failed!\n",i);
			goto out;
		}
		memset(last->next,'\0',sizeof(Item));
		last=last->next;
		//last=NULL;
	}
	//creating array that holds the registers
	last=first;
	for(i=0;i<no_items;i++)
	{
		last->data=kmalloc(sizeof(char*)*dev->noofReg,GFP_KERNEL);
		if(!last->data)
		{
			printk(KERN_ERR "Error: item data allocation failed for item no:%d\n",i);
			goto out;
		}
		memset(last->data,'\0',sizeof(char*)*dev->noofReg);
		last=last->next;
	}
	//finding no.of quantums required
	no_quantums=size/dev->regSize;
	if(size%dev->regSize!=0)
		no_quantums++;
	last=first;
	for(i=0,j=0;j<no_quantums;j++)
	{
		*(last->data+i)=(char*)kmalloc(sizeof(char)*dev->regSize,GFP_KERNEL);
		if(!*(last->data+i))
		{
			printk(KERN_ERR "Error: quantum-%d allocation failed!\n",j);
			goto out;
		}
		if(i==dev->noofReg-1)
		{
			last=last->next;
			i=0;
		}
		else
			i++;
	}

	printk(KERN_INFO "FILE:%s -> %s:End\n",__FILE__,__func__);
	return first;
out:	
	printk(KERN_INFO "FILE:%s -> %s:End\n",__FILE__,__func__);
	return 0;
}
