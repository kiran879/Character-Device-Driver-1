#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/fs.h>
#include<linux/moduleparam.h>
#include<linux/slab.h>
#include<linux/cdev.h>
#include<linux/semaphore.h>
#include<linux/completion.h>
#include<linux/wait.h>
#include<linux/sched.h>
#include<linux/ioctl.h>
#include"ioctl.h"

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("My character device driver-1");
MODULE_AUTHOR("rk");
