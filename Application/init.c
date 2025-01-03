#include"f_headers.h"
#include"f_declarations.h"
int init()
{
#ifdef DEBUG
	printf("F_Operations: FILE:%s-> %s:Begin\n",__FILE__,__func__);
#endif
	fd=-1;
	f_fptr[0]=mainMenu;
	f_fptr[1]=exitProgram;
	f_fptr[2]=openDevice;
	f_fptr[3]=readDevice;
	f_fptr[4]=writeDevice;
	f_fptr[5]=lseekDevice;
	f_fptr[6]=closeDevice;

#ifdef DEBUG
	printf("F_Operations: FILE:%s-> %s:End\n",__FILE__,__func__);
#endif

	return 0;
}
