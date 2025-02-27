#include"f_headers.h"
#include"f_declarations.h"
void* ioctlDevice(void* arg)
{
	int ret,choice;
#ifdef DEBUG
	printf("Application: FILE:%s-> %s:Begin\n",__FILE__,__func__);
#endif

jump:	printf("IOCTL MENU\n");
	printf("1:RESET THE DEVICE\n");
	printf("0:EXIT FROM IOCTL\n");
	printf("Please enter the choice\n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 0:
			return 0;
		case 1:
			ret=ioctl(fd,DEVRESET);
			if(ret==-1)
			{
				perror("open");
				(*f_fptr[1])((void*)"failure");
			}
			break;
		default:
			printf("Invalid choice!\n");

	}
	goto jump;
	printf("Application: FILE:%s-> %s:fd:%d\n",__FILE__,__func__,fd);
#ifdef DEBUG
	printf("Application: FILE:%s-> %s:End\n",__FILE__,__func__);
#endif
	return (void*)&fd;
}
