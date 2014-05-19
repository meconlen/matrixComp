#include <stdio.h>
#include <stdlib.h>

#include <sys/time.h>
#include <sys/resource.h>


#include "matrix.h"

#define SIZE 500

int main(int argc, char *argv[], char *envp[])
{
	double 	*A, *B, *C;
	double elapsed;
	int 	i;
	char 	c;


	struct rusage 	ruStart, ruEnd;

	


	A = calloc(SIZE*SIZE, sizeof(double));
	B = calloc(SIZE*SIZE, sizeof(double));
	C = calloc(SIZE*SIZE, sizeof(double));

	for(i=0; i<SIZE*SIZE; i++) {
		A[i] = drand48();
		B[i] = drand48();
	}
	if(SIZE < 10) { 
		printf("A = \n");
		printMatrix(A, SIZE, SIZE);
		printf("\nB = \n");
		printMatrix(B, SIZE, SIZE);
	}
	getrusage(RUSAGE_SELF, &ruStart);
	dMM(A, B, C, SIZE, SIZE, SIZE);
	getrusage(RUSAGE_SELF, &ruEnd);
	if(SIZE < 10) {
		printf("\nC = \n");
		printMatrix(C, SIZE, SIZE);
	}
	elapsed =  ruEnd.ru_utime.tv_sec;
	elapsed += (double)ruEnd.ru_utime.tv_usec / 1000000;
	elapsed -= ruStart.ru_utime.tv_sec;
	elapsed -= (double)ruStart.ru_utime.tv_usec / 1000000;

	printf("time = %f\n", elapsed);
	printf("Operations = %d\n", 2*SIZE*SIZE*SIZE);
	printf("GLFOPS = %f\n", (2.0*SIZE*SIZE*SIZE)/1000000000 / elapsed);

	return(0);
}
