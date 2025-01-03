#include"f_headers.h"
#include"f_declarations.h"
void* openDevice(void* arg)
{
	int i=0;
	char* mode;
	char ch;
#ifdef DEBUG
	printf("Application: FILE:%s-> %s:Begin\n",__FILE__,__func__);
#endif
	getchar();//to flush the break line character from the previous input
	mode=(char*)malloc(10);//reading/writing
	memset(mode,'\0',10);
jump:	printf("Application: FILE:%s-> %s:Please enter the device open mode(reading/writing)\n",__FILE__,__func__);
	while(1)
	{
		ch=getchar();
		if(ch=='\n')
			break;
		*(mode+i)=ch;
		i++;
	}
	*(mode+i)='\0';

	if(strncmp(mode,"reading",7)==0)
		fd=open((char*)arg,O_RDONLY);
	else if(strncmp(mode,"writing",7)==0)
		fd=open((char*)arg,O_WRONLY);
	else
	{
		printf("Invalid mode for open\n");
		memset(mode,'\0',10);
		i=0;
		goto jump;
	}
	//error handling for open
	if(fd==-1)
	{
		perror("open");
		(*f_fptr[1])((void*)"failure");
	}
	printf("Application: FILE:%s-> %s:fd:%d\n",__FILE__,__func__,fd);
#ifdef DEBUG
	printf("Application: FILE:%s-> %s:End\n",__FILE__,__func__);
#endif
	return (void*)&fd;
}
