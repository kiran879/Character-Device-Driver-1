#include"f_headers.h"
#include"f_declarations.h"
void* closeDevice(void* arg)
{
#ifdef DEBUG
	printf("F_Operations: FILE:%s-> %s:Begin\n",__FILE__,__func__);
#endif
	if(fd== -1)
	{
		printf("Application:FILE:%s:%s: Error Invalid file descriptor to close\n",__FILE__,__func__);
		return arg;
	}
	close(fd);
	fd=-1;
	//printf("Device File closed successfully, fd:%d\n",fd);
#ifdef DEBUG
	printf("F_Operations: FILE:%s-> %s:End\n",__FILE__,__func__);
#endif
	return 0;
}
