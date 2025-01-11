#include"headers.h"
#include"declarations.h"
Item* createScull(Device *dev,int size)
{	int no_items,no_quantums,i,j;
	Item *first,*last;
	printk(KERN_INFO "FILE:%s -> %s:Begin\n",__FILE__,__func__);
	//to find no.of Items required
	no_items=size/dev->noofReg;
	if(size%dev->noofReg!=0)
		no_items++;
	//creating items
	last=first=(Item*)kmalloc(sizeof(Item),GFP_KERNEL);//first item

	for(i=0;i<no_items-1;i++)
	{
		last->next=(Item*)kmalloc(sizeof(Item),GFP_KERNEL);
		last=last->next;
	}
	//creating array that holds the registers
	last=first;
	for(i=0;i<no_items;i++)
	{
		last->data=(char**)kmalloc(sizeof(char*)*dev->noofReg,GFP_KERNEL);
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
}
