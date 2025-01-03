extern int NoD;
extern int majorNo;
extern int minorNo;
extern dev_t devNo,devID;
extern int devSize, regSize, noofReg,dataSize;

#ifndef CDDNAME
#define CDDNAME "myCharacterDriver"
#endif
typedef struct
{
	int devSize;
	int regSize;
	int noofReg;
	int dataSize;
	struct cdev mycdev;
}Device;
extern Device *myDev;

int openMyCDD(struct inode*, struct file*);
int closeMyCDD(struct inode*, struct file*);
