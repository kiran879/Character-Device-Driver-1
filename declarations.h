extern int NoD;
extern int majorNo;
extern int minorNo;
extern dev_t devNo,devID;
extern int devSize, regSize, noofReg,dataSize;

#ifndef CDDNAME
#define CDDNAME "myCharacterDriver"
#endif
typedef struct item
{
	void **data;
	struct item *next;
}Item;

typedef struct
{
	int devSize;
	int regSize;
	int noofReg;
	int dataSize;
	struct cdev mycdev;
	Item *item;
}Device;
extern Device *myDev;

int openMyCDD(struct inode*, struct file*);
int closeMyCDD(struct inode*, struct file*);
ssize_t readMyCDD (struct file *, char __user *, size_t, loff_t *);
ssize_t writeMyCDD (struct file *, const char __user *, size_t, loff_t *);
loff_t lseekMyCDD (struct file *, loff_t, int);

//function to trim the device content befor handling the writing 
int trimMyCDD (Device*);
Item* createScull(Device*,int);
