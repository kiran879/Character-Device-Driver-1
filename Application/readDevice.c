#include"f_headers.h"
#include"f_declarations.h"
void* readDevice(void* arg)
{
	int ret;
	char buff[100];
#ifdef DEBUG
	printf("F_Operations: FILE:%s-> %s:Begin\n",__FILE__,__func__);
#endif
	memset(buff,'\0',100);
	ret=read(fd,buff,100);
	if(ret==-1)
	{
		perror("read");
		(*f_fptr[1])((void*)"failure");
	}
	printf("no.of bytes read:%d\n",ret);
	printf("Data read fromt he device: %s\n",buff);
#ifdef DEBUG
	printf("F_Operations: FILE:%s-> %s:End\n",__FILE__,__func__);
#endif
	return 0;
}
