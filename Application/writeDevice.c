#include"f_headers.h"
#include"f_declarations.h"
void* writeDevice(void* arg)
{
	char buff[10];
	int ret;
#ifdef DEBUG
	printf("F_Operations: FILE:%s-> %s:Begin\n",__FILE__,__func__);
#endif
	ret=write(fd,buff,10);
	if(ret == -1)
	{
		perror("write");
		(*f_fptr[1])((void*)"failure");
	}

#ifdef DEBUG
	printf("F_Operations: FILE:%s-> %s:End\n",__FILE__,__func__);
#endif
	return 0;
}
