#include"f_headers.h"
#include"f_declarations.h"
void* exitProgram(void* arg)
{
#ifdef DEBUG
	printf("F_Operations: FILE:%s-> %s:Begin\n",__FILE__,__func__);
#endif
	if(strncmp((char*)arg,"success",7)==0)
		exit(EXIT_SUCCESS);
	else
		exit(EXIT_FAILURE);
#ifdef DEBUG
	printf("F_Operations: FILE:%s-> %s:End\n",__FILE__,__func__);
#endif
	return 0;
}
