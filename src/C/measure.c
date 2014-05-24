#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#ifdef TIME_WITH_SYS_TIME
	# include <sys/time.h>
	# include <time.h>
#else
	#ifdef HAVE_SYS_TIME_H
		#include <sys/time.h>
	#else
		#include <time.h>
	#endif
#endif

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

	struct timespec 	startTime, endTime;
	struct rusage 		ruStart, ruEnd;

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
#ifdef HAVE_CLOCK_GETTIME
			clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &startTime);
#else
			getrusage(RUSAGE_SELF, &ruStart);
			startTime.tv_sec = ruStart.ru_utime.tv_sec + ruStart.ru_stime.tv_sec;
			startTime.tv_nsec = (ruStart.ru_utime.tv_usec + ruStart.ru_stime.tv_usec)*1000;
#endif
			switch(algorithm) {
				case 1:
					dMM(A, B, C, size, size, size);
					break;
				case 2:
					dMMT(A, B, C, size, size, size);
					break;
				case 3:
					dMMT2(A, B, C, size, size, size);
					break;
				case 4:
					dMMT2r(A, B, C, size, size, size);
					break;
				case 5:
					strassenMM(A, B, C, size, size, size);
					break;
				default:
					goto error1;
			}

#ifdef HAVE_CLOCK_GETTIME
			clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &endTime);
#else
			getrusage(RUSAGE_SELF, &ruEnd);
			endTime.tv_sec = ruEnd.ru_utime.tv_sec + ruEnd.ru_stime.tv_sec;
			endTime.tv_nsec = (ruEnd.ru_utime.tv_usec + ruEnd.ru_stime.tv_usec) * 1000;
#endif
			elapsed =  endTime.tv_sec;
			elapsed += (double)endTime.tv_nsec / 10e9;
			elapsed -= startTime.tv_sec;
			elapsed -= (double)startTime.tv_nsec / 10e9;
			totalElapsed += elapsed;
			if(debug > 0) {
				fprintf(stderr, "size = %d, alg = %d, start = %f, end = %f, elapsed = %f, Gops = %f\n",
					size, algorithm, 
					startTime.tv_sec + (double)(startTime.tv_nsec)/1e9,
					endTime.tv_sec + (double)(endTime.tv_nsec)/1e9,
					elapsed, ((double)2.0*size*size*size-size*size)/10e9
				);
			}
			free(A);
			free(B);
			free(C);		
		}
		gflops = ((((double)2.0*size*size*size-size*size))/10e9)/totalElapsed;
		printf("%u %u %f\n", size, count, gflops);
	}
	return(0);
error1:
	fprintf(stderr, "Unknown algorithm\n");
	exit(-1);
error0:
	fprintf(stderr, "Usage: %s -n N\n", argv[0]);
	fprintf(stderr, "N = matrix size\n");
	exit(-1);
}
