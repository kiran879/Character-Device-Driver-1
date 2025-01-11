#include"headers.h"
#include"declarations.h"
#include"file_operations.h"
int majorNo,minorNo,NoD;
dev_t devNo,devID;
Device *myDev;
int devSize, regSize, noofReg,dataSize;
module_param(NoD, int, S_IRUGO);
module_param(devSize,int,S_IRUGO);
module_param(regSize,int,S_IRUGO);
module_param(noofReg,int,S_IRUGO);
module_param(dataSize,int,S_IRUGO);

static int __init LKM_init(void)
{
	int ret,i;
//	file_operations fops;
	printk(KERN_INFO "FILE:%s -> %s:Begin\n",__FILE__,__func__);

	//major=register_chrdev(0,"My character device driver",&fops);
	ret=alloc_chrdev_region(&devNo,minorNo,NoD,CDDNAME);
	if(ret==-1)
	{
		printk(KERN_ERR "%s: Error: Failed to allocate device number\n",__func__);
		return 0;
	}
	majorNo=MAJOR(devNo);
	printk(KERN_INFO "FILE:%s -> %s: Device Number created successfully with Major No:%d\n",__FILE__,__func__,majorNo);
	myDev=kmalloc(sizeof(Device)*NoD,GFP_KERNEL);
	if(!myDev)
	{
		printk(KERN_ERR "%s: Error: kmalloc() failed!\n",__func__);
		return 0;
	}
	for(i=0;i<NoD;i++)
	{
		cdev_init(&myDev[i].mycdev,&fops);

		myDev[i].devSize=devSize;
		myDev[i].regSize=regSize;
		myDev[i].noofReg=noofReg;
		myDev[i].dataSize=dataSize;
		myDev[i].mycdev.ops=&fops;
		myDev[i].item=NULL;
		
		devID=MKDEV(majorNo,i);
		ret=cdev_add(&myDev[i].mycdev,devID,NoD);
		if(ret==-1)
		{
			printk(KERN_ERR "%s: Error: cdev_add() failed!\n",__func__);
			return 0;
		}
		printk(KERN_INFO "%s: Minor No:%d\n",__func__,MINOR(myDev[i].mycdev.dev));
	}
	printk(KERN_INFO "FILE:%s -> %s:End\n",__FILE__,__func__);
	return 0;
}
module_init(LKM_init);
