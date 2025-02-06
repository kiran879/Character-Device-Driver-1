#include"f_headers.h"
#include"f_declarations.h"
void* lseekDevice(void* arg)
{
	char origin[10];
	int offset,ret;
#ifdef DEBUG
	printf("F_Operations: FILE:%s-> %s:Begin\n",__FILE__,__func__);
#endif
jump:	memset(origin,'\0',10);
	printf("Please enter the origin(SEEK_SET/SEEK_CUR/SEEK_END)\n");
	getchar();
	fgets(origin,10,stdin);
	printf("Please enter offset size\n");
	scanf("%d",&offset);
	//printf("origin:%s\n",origin);
	if(strncmp(origin,"SEEK_SET",8)==0)
		ret=lseek(fd,offset,SEEK_SET);
	else if(strncmp(origin,"SEEK_CUR",8)==0)
		ret=lseek(fd,offset,SEEK_CUR);
	else if(strncmp(origin,"SEEK_END",8)==0)
		ret=lseek(fd,offset,SEEK_END);
	else
	{
		printf("Error: Invalid origin\n");
		goto jump;
	}
	if(ret==-1)
	{
		perror("lseek");
		(*f_fptr[1])((void*)"failure");
	}
#ifdef DEBUG
	printf("F_Operations: FILE:%s-> %s:End\n",__FILE__,__func__);
#endif
	return 0;
}
