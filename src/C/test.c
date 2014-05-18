#include <stdio.h>
#include <stdlib.h>
#include <CUnit/Basic.h>

int main(int argc, char *argv[], char *envp[])
{
	if(CU_initialize_registry() != CUE_SUCCESS) goto error0;
	return(0);
error0:
	fprintf(stderr, "test setup error\n");
	exit(-1);
}
