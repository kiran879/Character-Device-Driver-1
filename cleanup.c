#include"headers.h"
#include"declarations.h"
static void __exit LKM_exit(void)
{
	int i;
	printk(KERN_INFO "FILE:%s -> %s:Begin\n",__FILE__,__func__);
//	unregister_chrdev(major,"My character device driver");
	for(i=0;i<NoD;i++)
	{
		completion_done(&myDev[i].kcom);
		cdev_del(&myDev[i].mycdev);
	}
	kfree(myDev);
	unregister_chrdev_region(devNo,NoD);
	printk(KERN_INFO "unregisterd the device ID sucessfully");
	printk(KERN_INFO "FILE:%s -> %s:End\n",__FILE__,__func__);
}
module_exit(LKM_exit);

