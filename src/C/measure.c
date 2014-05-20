#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/time.h>
#include <sys/resource.h>


#include "matrix.h"


int main(int argc, char *argv[], char *envp[])
{
	double 			*A, *B, *C;
	double 			elapsed = 0, totalElapsed = 0;
	double 			gflops = 0;
	int 			i, j, k;
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
		if(debug > 0) fprintf(stderr, "Starting size = %d\n", size);
		totalElapsed = 0;
		for(j=0; j<count; j++) {
			if(debug > 0) fprintf(stderr, "Computing matrix count = %d\n", j);
			A = calloc(size * size, sizeof(double));
			B = calloc(size * size, sizeof(double));
			C = calloc(size * size, sizeof(double));
			for(k=0; k<size * size; k++) {
				A[k] = drand48();
				B[k] = drand48();
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

			elapsed =  ruEnd.ru_utime.tv_sec;
			elapsed += (double)ruEnd.ru_utime.tv_usec / 10e6;
			elapsed -= ruStart.ru_utime.tv_sec;
			elapsed -= (double)ruStart.ru_utime.tv_usec / 10e6;
			totalElapsed += elapsed;
			if(debug > 0) {
				fprintf(stderr, "size = %d, alg = %d, start = %f, end = %f, elapsed = %f, Gops = %f\n",
					size, algorithm, 
					ruStart.ru_utime.tv_sec + (double)(ruStart.ru_utime.tv_usec)/10e6,
					ruEnd.ru_utime.tv_sec + (double)(ruEnd.ru_utime.tv_usec)/10e6,
					elapsed, (double)2.0*size*size*size/10e9
				);
			}
			free(A);
			free(B);
			free(C);		
		}
		gflops = (((double)2.0*size*size*size*count)/10e9)/totalElapsed;
		printf("%u %u %f\n", size, count, gflops);
	}
	return(0);
error0:
	fprintf(stderr, "Usage: %s -n N\n", argv[0]);
	fprintf(stderr, "N = matrix size\n");
	exit(-1);
}
