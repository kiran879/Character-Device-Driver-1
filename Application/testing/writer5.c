#include"../f_headers.h"
//#include"f_declarations.h"

int main()
{
	char buff[]="this is writer5";
	int fd,ret;
#ifdef DEBUG
	printf("F_Operations: FILE:%s-> %s:Begin\n",__FILE__,__func__);
#endif
	printf("testing : strlen- %d,string:%s\n",strlen(buff),buff);
	fd=open("../../myDevice",O_WRONLY);
	if(fd==-1)
	{
		perror("read");
		exit(EXIT_FAILURE);
	}
	ret=write(fd,buff,strlen(buff));
	if(ret == -1)
	{
		perror("write");
		exit(EXIT_FAILURE);
	}
	printf("No.of bytes successfully written are:%d\n",ret);
#ifdef DEBUG
	printf("F_Operations: FILE:%s-> %s:End\n",__FILE__,__func__);
#endif
	return 0;
}
