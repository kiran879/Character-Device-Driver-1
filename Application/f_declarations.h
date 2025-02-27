#ifndef NOF
#define NOF 8
#endif
extern int fd;
int init();
extern void* mainMenu(void*);
extern void* exitProgram(void*);
extern void* openDevice(void*);
extern void* readDevice(void*);
extern void* writeDevice(void*);
extern void* lseekDevice(void*);
extern void* closeDevice(void*);
extern void* ioctlDevice(void*);
extern void* (*f_fptr[NOF])(void*);
