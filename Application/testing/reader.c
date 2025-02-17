#include"../f_headers.h"
//#include"f_declarations.h"
int main()
{
	int fd, ret;
	char buff[100];
#ifdef DEBUG
	printf("F_Operations: FILE:%s-> %s:Begin\n",__FILE__,__func__);
#endif
	memset(buff,'\0',100);
	fd=open("../../myDevice",O_RDONLY);
	if(fd==-1)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}
	ret=read(fd,buff,100);
	if(ret==-1)
	{
		perror("read");
		exit(EXIT_FAILURE);
	}
	printf("no.of bytes read:%d\n",ret);
	printf("Data read fromt he device: %s\n",buff);
#ifdef DEBUG
	printf("F_Operations: FILE:%s-> %s:End\n",__FILE__,__func__);
#endif
	return 0;
}
