#include<asm/ioctl.h>
#ifndef MAGIC 
#define MAGIC 'K'
#endif

#ifndef DEVRESET
#define DEVRESET _IO(MAGIC,0)
#endif
