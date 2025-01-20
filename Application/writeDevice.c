#include"f_headers.h"
#include"f_declarations.h"
void* writeDevice(void* arg)
{
	char buff[]="In this world where you are, just be kind and spread love";
	int ret;
#ifdef DEBUG
	printf("F_Operations: FILE:%s-> %s:Begin\n",__FILE__,__func__);
#endif
	printf("testing : strlen- %d,string:%s\n",strlen(buff),buff);
	ret=write(fd,buff,strlen(buff));
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
