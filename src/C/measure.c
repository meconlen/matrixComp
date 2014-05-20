#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/time.h>
#include <sys/resource.h>


#include "matrix.h"


int main(int argc, char *argv[], char *envp[])
{
	double 			*A, *B, *C;
	double 			elapsed;
	double 			gflops = 0;
	int 			i, j;
	unsigned int	start = 1, end = 1, skip = 1, count = 1;
	unsigned int	size = 1, algorithm = 1, debug = 0;
	char 			c;

	struct rusage 	ruStart, ruEnd;

	while((c = getopt(argc, argv, "c:s:e:j:a:d:")) != -1)
		switch(c) {
			case 's': 
				start = atoll(optarg);
				break;
			case 'e': 
				end = atoll(optarg);
				break;
			case 'j': 
				skip = atoll(optarg);
				break;
			case 'c':
				count = atoll(optarg);
				break;
			case 'a':
				algorithm = atoll(optarg);
				break;
			case 'd':
				debug = atoll(optarg);
				break;
			default:
				goto error0;
		}
	fprintf(stderr, "start = %d, end = %d, skip = %d, count = %d\n",
		start, end, skip, count);
	for(size=start; size<=end; size+=skip) {
		for(j=0; j<count; j++) {
			A = calloc(size * size, sizeof(double));
			B = calloc(size * size, sizeof(double));
			C = calloc(size * size, sizeof(double));
			for(j=0; j<size * size; j++) {
				A[j] = drand48();
				B[j] = drand48();
			}
			getrusage(RUSAGE_SELF, &ruStart);
			switch(algorithm) {
				case 1:
					dMM(A, B, C, size, size, size);
					break;
				case 2:
					dMMT(A, B, C, size, size, size);
					break;
			}

			getrusage(RUSAGE_SELF, &ruEnd);
			if(debug > 0) {
				fprintf(stderr, "size = %d, alg = %d, start = %f, end = %f\n",
					size, algorithm, 
					ruStart.ru_utime.tv_sec + (double)(ruStart.ru_utime.tv_usec)/1000000,
					ruEnd.ru_utime.tv_sec + (double)(ruEnd.ru_utime.tv_usec)/1000000
				);
			}
			elapsed =  ruEnd.ru_utime.tv_sec;
			elapsed += (double)ruEnd.ru_utime.tv_usec / 1000000;
			elapsed -= ruStart.ru_utime.tv_sec;
			elapsed -= (double)ruStart.ru_utime.tv_usec / 1000000;
			gflops += ((2.0*size*size*size)/1000000000)/elapsed;
			free(A);
			free(B);
			free(C);		
		}
		gflops /= count;
		printf("%u %u %f\n", size, count, gflops);
	}
	return(0);
error0:
	fprintf(stderr, "Usage: %s -n N\n", argv[0]);
	fprintf(stderr, "N = matrix size\n");
	exit(-1);
}
