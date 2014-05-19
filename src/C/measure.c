#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/time.h>
#include <sys/resource.h>


#include "matrix.h"

#define SIZE 500

int main(int argc, char *argv[], char *envp[])
{
	double 	*A, *B, *C;
	double elapsed;
	int 		i;
	uint64_t	n;
	char 		c;

	struct rusage 	ruStart, ruEnd;

	while((c = getopt(argc, argv, "n:")) != -1)
		switch(c) {
			case 'n': 
				n = atoll(optarg);
				break;
			default:
				goto error0;
		}


	A = calloc(n*n, sizeof(double));
	B = calloc(n*n, sizeof(double));
	C = calloc(n*n, sizeof(double));

	for(i=0; i<n*n; i++) {
		A[i] = drand48();
		B[i] = drand48();
	}
	if(n < 10) { 
		printf("A = \n");
		printMatrix(A, n, n);
		printf("\nB = \n");
		printMatrix(B, n, n);
	}
	getrusage(RUSAGE_SELF, &ruStart);
	dMM(A, B, C, n, n, n);
	getrusage(RUSAGE_SELF, &ruEnd);
	if(SIZE < 10) {
		printf("\nC = \n");
		printMatrix(C, n, n);
	}
	elapsed =  ruEnd.ru_utime.tv_sec;
	elapsed += (double)ruEnd.ru_utime.tv_usec / 1000000;
	elapsed -= ruStart.ru_utime.tv_sec;
	elapsed -= (double)ruStart.ru_utime.tv_usec / 1000000;

	printf("time = %f\n", elapsed);
	printf("Operations = %d\n", 2*n*n*n);
	printf("GLFOPS = %f\n", (2.0*n*n*n)/1000000000 / elapsed);

	return(0);
error0:
	fprintf(stderr, "Usage: %s -n N\n", argv[0]);
	fprintf(stderr, "N = matrix size\n");
	exit(-1);
}
