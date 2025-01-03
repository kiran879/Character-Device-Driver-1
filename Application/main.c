#include"f_headers.h"
#include"f_declarations.h"
int fd;
int init();
void* mainMenu(void*);
void* exitProgram(void*);
void* openDevice(void*);
void* readDevice(void*);
void* writeDevice(void*);
void* lseekDevice(void*);
void* closeDevice(void*);
void* (*f_fptr[NOF])(void*);

int main(int argc,char* argv[])
{
#ifdef DEBUG
	printf("Application: FILE:%s-> %s:Begin\n",__FILE__,__func__);
#endif
	init();
	if(argc!=2)
	{
		printf("Application: FILE:%s-> %s: Insufficient command line arguments\n",__FILE__,__func__);
		(*f_fptr[1])((void*)"failure");//exitProgram
	}
	while(1)
	(*f_fptr[0])((void*)argv[1]);//mainMenu

#ifdef DEBUG
	printf("Application: FILE:%s-> %s:End\n",__FILE__,__func__);
#endif

	return 0;
}
