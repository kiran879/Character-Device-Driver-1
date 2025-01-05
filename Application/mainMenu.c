#include"f_headers.h"
#include"f_declarations.h"
void* mainMenu(void* arg)
{
	int choice;
	char* mainMenu[]=
	{
		"Application: Main Menu",
		"1:Open the Device",
		"2:Read from the Device",
		"3:Write into the Device",
		"4:Move the pointing position in the Device",
		"5:Close the Device",
		"0:Exit from the Main Menu",
		"Please enter your choice"
	};
#ifdef DEBUG
	printf("Application: FILE:%s-> %s:Begin\n",__FILE__,__func__);
#endif
	for(int i=0;i<8;i++)
	printf("%s\n",mainMenu[i]);
	scanf("%d",&choice);

	if(choice==0)
		(*f_fptr[1])((void*)"success");//exitProgram
	else if(choice==1)
		(*f_fptr[2])((void*)arg);//openDevice
	else if(choice<6 && choice>1)
	{
		if(fd==-1)
			printf("Application: FILE:%s-> %s: No stream found to the device file, please open the device file\n",__FILE__,__func__);
		else
			(*f_fptr[choice+1])(0);//read,write,lseek,close Device
	}
	else
		printf("Application: FILE:%s-> %s: Invalid choice\n",__FILE__,__func__);
	printf("Testing fd:%d\n",fd);

#ifdef DEBUG
	printf("Application: FILE:%s-> %s:End\n",__FILE__,__func__);
#endif

	return 0;
}
