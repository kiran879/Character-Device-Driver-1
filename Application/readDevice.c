#include"f_headers.h"
#include"f_declarations.h"
void* readDevice(void* arg)
{
	char buff[10];
#ifdef DEBUG
	printf("F_Operations: FILE:%s-> %s:Begin\n",__FILE__,__func__);
#endif
	read(fd,buff,5);
#ifdef DEBUG
	printf("F_Operations: FILE:%s-> %s:End\n",__FILE__,__func__);
#endif
	return 0;
}
