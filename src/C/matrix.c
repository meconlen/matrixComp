#include <inttypes.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "matrix.h"

#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>

int init_matrixSuite(void)
{
	return(0);
}

int clean_matrixSuite(void)
{
	return(0);
}

void unit_matrix2X2(void)
{
	double A[2][2] = {
		{ 1, 2 },
		{ 3, 4 }
	};
	double B[2][2] = {
		{ 5, 6 },
		{ 7, 8 }
	};
	double C[2][2];
	int rc;

	rc = dMM((double *)A, (double *)B, (double *)C, 2, 2, 2);
	CU_ASSERT(rc == 0);
	CU_ASSERT(C[0][0] == 19);
	CU_ASSERT(C[0][1] == 22);
	CU_ASSERT(C[1][0] == 43);
	CU_ASSERT(C[1][1] == 50);
//	printf("\n");
//	printMatrix((double *)C, 2, 2);
	return;
}

void unit_matrix2X3X4(void)
{
	double A[2][3] = {
		{1, 2, 3},
		{4, 5, 6}
	};
	double B[3][4] = {
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 12}
	};
	double C[2][4];
	int rc;

	rc = dMM((double *)A, (double *)B, (double *)C, 2, 3, 4);
	CU_ASSERT(rc == 0);
	CU_ASSERT(C[0][0] == 38);
	CU_ASSERT(C[0][1] == 44);
	CU_ASSERT(C[0][2] == 50);
	CU_ASSERT(C[0][3] == 56);
	CU_ASSERT(C[1][0] == 83);
	CU_ASSERT(C[1][1] == 98);
	CU_ASSERT(C[1][2] == 113);
	CU_ASSERT(C[1][3] == 128);

	// printf("\n");
	// printMatrix((double *)C, 2, 4);
	return;
}

void unit_matrix_dMMT(void)
{
	double A[2][3] = {
		{1, 2, 3},
		{4, 5, 6}
	};
	double B[3][4] = {
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 12}
	};
	double C[2][4];
	int rc;	

	rc = dMMT((double *)A, (double *)B, (double *)C, 2, 3, 4);
	CU_ASSERT(rc == 0);
	CU_ASSERT(C[0][0] == 38);
	CU_ASSERT(C[0][1] == 44);
	CU_ASSERT(C[0][2] == 50);
	CU_ASSERT(C[0][3] == 56);
	CU_ASSERT(C[1][0] == 83);
	CU_ASSERT(C[1][1] == 98);
	CU_ASSERT(C[1][2] == 113);
	CU_ASSERT(C[1][3] == 128);

	return;
}

void unit_matrix_dMMT2(void)
{
	double A[2][3] = {
		{1, 2, 3},
		{4, 5, 6}
	};
	double B[3][4] = {
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 12}
	};
	double C[2][4];
	int rc;	

	rc = dMMT2((double *)A, (double *)B, (double *)C, 2, 3, 4);
	CU_ASSERT(rc == 0);
	CU_ASSERT(C[0][0] == 38);
	CU_ASSERT(C[0][1] == 44);
	CU_ASSERT(C[0][2] == 50);
	CU_ASSERT(C[0][3] == 56);
	CU_ASSERT(C[1][0] == 83);
	CU_ASSERT(C[1][1] == 98);
	CU_ASSERT(C[1][2] == 113);
	CU_ASSERT(C[1][3] == 128);
	// printf("\n");
	// printMatrix((double *)C, 2, 4);
	return;
}

void unit_matrix_MA(void)
{
	double A[3][4] = {
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 12}
	};	
	double B[3][4] = {
		{13, 14, 15, 16},
		{17, 18, 19, 20},
		{21, 22, 23, 24}
	};
	double C[3][4];
	int rc;

	rc = MA((double *)A, (double *)B, (double *)C, 3, 4);
	CU_ASSERT(rc == 0);
	CU_ASSERT(C[0][0] == 14);
	CU_ASSERT(C[0][1] == 16);
	CU_ASSERT(C[0][2] == 18);
	CU_ASSERT(C[0][3] == 20);
	CU_ASSERT(C[1][0] == 22);
	CU_ASSERT(C[1][1] == 24);
	CU_ASSERT(C[1][2] == 26);
	CU_ASSERT(C[1][3] == 28);
	CU_ASSERT(C[2][0] == 30);
	CU_ASSERT(C[2][1] == 32);
	CU_ASSERT(C[2][2] == 34);
	CU_ASSERT(C[2][3] == 36);

}

void unit_matrix_strassenMM2n2(void)
{
	uint64_t 	x, i;

	double A[2][2] = {
		{ 1, 2 },
		{ 3, 4 }
	};
	double B[2][2] = {
		{ 5, 6 },
		{ 7, 8 }
	};
	double C[2][2];
	int rc;

	rc = strassenMM2n((double *)A, (double *)B, (double *)C, 2);
	CU_ASSERT(rc == 0);
	CU_ASSERT(C[0][0] == 19);
	CU_ASSERT(C[0][1] == 22);
	CU_ASSERT(C[1][0] == 43);
	CU_ASSERT(C[1][1] == 50);

	rc = strassenMM2n(NULL, NULL, NULL, 14);
	// printf("\n");
	// printMatrix((double *)C, 2, 2);
	CU_ASSERT(rc == -1);

}

void unit_matrix_strassenMM2n4(void)
{
	double A[4][4] = {
		{ 1, 2, 3, 4},
		{ 5, 6, 7, 8},
		{ 9, 10, 11, 12},
		{13, 14, 15, 16}
	};
	double B[4][4] = {
		{17, 18, 19, 20},
		{21, 22, 23, 24},
		{25, 26, 27, 28},
		{29, 30, 31, 32}
	};
	double C1[4][4], C2[4][4], T[4][4];
	int rc, i, j;
	dMM((double *)A, (double *)B, (double *)C1, 4, 4, 4);
	strassenMM2n((double *)A, (double *)B, (double *)C2, 4);
	for(i=0; i<4; i++) {
		for(j=0; j<4; j++) {
			CU_ASSERT(C1[i][j] == C2[i][j]);
		}
	}
	MS((double *)C1, (double *)C2, (double *)T, 4, 4);
	// printf("\n");
	// printMatrix((double *)T, 4, 4);
	return;
}

void unit_matrix_strassenMM4X4(void)
{
	double A[4][4] = {
		{ 1, 2, 3, 4},
		{ 5, 6, 7, 8},
		{ 9, 10, 11, 12},
		{13, 14, 15, 16}
	};
	double B[4][4] = {
		{17, 18, 19, 20},
		{21, 22, 23, 24},
		{25, 26, 27, 28},
		{29, 30, 31, 32}
	};
	double C1[4][4], C2[4][4], T[4][4];
	int rc, i, j;
	dMM((double *)A, (double *)B, (double *)C1, 4, 4, 4);
	strassenMM((double *)A, (double *)B, (double *)C2, 4, 4, 4);
	for(i=0; i<4; i++) {
		for(j=0; j<4; j++) {
			CU_ASSERT(C1[i][j] == C2[i][j]);
		}
	}
	MS((double *)C1, (double *)C2, (double *)T, 4, 4);
	// printf("\nC1 = \n");
	// printMatrix((double *)C1, 4, 4);
	// printf("\nC2 = \n");
	// printMatrix((double *)C2, 4, 4);
	return;
}

void unit_matrix_strassenMM5X7X9(void)
{
	double A[5][7] = {
		{ 1, 2, 3, 4, 5},
		{ 5, 6, 7, 8, 9},
		{ 9, 10, 11, 12, 13},
		{13, 14, 15, 16, 17},
		{17, 18, 19, 20, 21}
	};
	double B[7][9] = {
		{17, 18, 19, 20, 21, 22, 23, 24, 25},
		{21, 22, 23, 24, 25, 26, 27, 28, 29},
		{25, 26, 27, 28, 29, 30, 31, 32, 33},
		{29, 30, 31, 32, 33, 34, 35, 36, 37},
		{21, 22, 23, 24, 25, 26, 27, 28, 29},
		{25, 26, 27, 28, 29, 30, 31, 32, 33},
		{29, 30, 31, 32, 33, 34, 35, 36, 37}
	};
	double C1[5][9], C2[5][9], T[5][9];
	int rc, i, j;
	dMM((double *)A, (double *)B, (double *)C1, 5, 7, 9);
	strassenMM((double *)A, (double *)B, (double *)C2, 5, 7, 9);
	for(i=0; i<5; i++) {
		for(j=0; j<9; j++) {
			CU_ASSERT(C1[i][j] == C2[i][j]);
		}
	}
	MS((double *)C1, (double *)C2, (double *)T, 5, 9);
	// printf("\nC1 = \n");
	// printMatrix((double *)C1, 4, 4);
	// printf("\nC2 = \n");
	// printMatrix((double *)C2, 4, 4);
	return;
}


int dMM(double *A, double *B, double *C, uint64_t m, uint64_t n, uint64_t p)
{
	uint64_t	i, j, k;
	memset(C, 0, m*p*sizeof(double));
	for(i=0; i<m; i++) {
		for(j=0; j<p; j++) {
			for(k=0; k<n; k++) {
				C[i*p+j] += A[i*n+k] * B[k*p+j];
			}
		}
	}
	return(0);
}

/* A[m][n] * B[n][p] */
/* We wish to store B[p][n] */
/* Not transpose, but column major order */

int dMMT(double *A, double *B, double *C, uint64_t m, uint64_t n, uint64_t p)
{
	uint64_t	i, j, k;
	double 		*B2;

	B2 = malloc(sizeof(double)*n*p);
	for(i=0; i<n; i++) {
		for(j=0; j<p; j++) {
			B2[j*n+i] = B[i*p+j];
		}
	}
	memset(C, 0, m*p*sizeof(double));
	for(i=0; i<m; i++) {
		for(j=0; j<p; j++) {
			for(k=0; k<n; k++) {
				C[i*p+j] += A[i*n+k] * B2[j*n+k];
			}
		}
	}
	free(B2);
	return(0);
}

/* A[m][n] * B[n][p] */
int dMMT2(double *A, double *B, double *C, uint64_t m, uint64_t n, uint64_t p)
{
	uint64_t	i, j, k;

	memset(C, 0, m*p*sizeof(double));
	for(i=0; i<m; i++) { /* A row */
		for(j=0; j<n; j++) { /* A col, B row */
			for(k=0; k<p; k++) { /* B col */

				/* so C has m(k) rows and p(j) columns */
				/* computing on row k and column i*/
				/* C[k][j] += A[k][i] * B[i][j] */ 
				C[p*i+k] += A[n*i+j] * B[p*j+k];
			}
		}
	}
}

inline int powerOfTwo(uint64_t x)
{
	return( (x != 0) && ( ( (~x +1) & x) == x) );
}

inline int MA(double *A, double *B, double *C, uint64_t M, uint64_t N)
{
	uint64_t	m, n;
	for(m=0; m<M; m++) {
		for(n=0; n<N; n++) {
			C[m*N+n] = A[m*N+n] + B[m*N+n];
		}
	}
	return(0);
}

inline int MS(double *A, double *B, double *C, uint64_t M, uint64_t N)
{
	uint64_t	m, n;
	for(m=0; m<M; m++) {
		for(n=0; n<N; n++) {
			C[m*N+n] = A[m*N+n] - B[m*N+n];
		}
	}
	return(0);
}

int strassenMM2n(double *A, double *B, double *C, uint64_t M)
{
	double D[7];
	double *A1, *A2, *A3, *A4, *B1, *B2, *B3, *B4, *C1, *C2, *C3, *C4;
	double *D0, *D1, *D2, *D3, *D4, *D5, *D6, *D7, *T1, *T2;
	uint64_t N, i, j;


	if(! powerOfTwo(M)) return(-1);
	if(M == 2) {
		D[0] = (A[0] + A[3])*(B[0]+B[3]); 
		D[1] = (A[2] + A[3])*B[0]; 
		D[2] = (A[0])*(B[1] - B[3]); 
		D[3] = A[3]*(B[2] - B[0]); 
		D[4] = (A[0] + A[1])*B[3];
		D[5] = (A[2] - A[0])*(B[0] + B[1]); 
		D[6] = (A[1] - A[3])*(B[2] + B[3]);
		C[0] = D[0] + D[3] - D[4] + D[6];
		C[1] = D[2] + D[4];
		C[2] = D[1] + D[3];
		C[3] = D[0] - D[1] + D[2] + D[5];
		return(0);
	}

	N = M/2;
	A1 = malloc(sizeof(double)*N*N);
	A2 = malloc(sizeof(double)*N*N);
	A3 = malloc(sizeof(double)*N*N);
	A4 = malloc(sizeof(double)*N*N);
	B1 = malloc(sizeof(double)*N*N);
	B2 = malloc(sizeof(double)*N*N);
	B3 = malloc(sizeof(double)*N*N);
	B4 = malloc(sizeof(double)*N*N);
	C1 = malloc(sizeof(double)*N*N);
	C2 = malloc(sizeof(double)*N*N);
	C3 = malloc(sizeof(double)*N*N);
	C4 = malloc(sizeof(double)*N*N);
	D1 = malloc(sizeof(double)*N*N);
	D2 = malloc(sizeof(double)*N*N);
	D3 = malloc(sizeof(double)*N*N);
	D4 = malloc(sizeof(double)*N*N);
	D5 = malloc(sizeof(double)*N*N);
	D6 = malloc(sizeof(double)*N*N);
	D7 = malloc(sizeof(double)*N*N);
	T1 = malloc(sizeof(double)*N*N);
	T2 = malloc(sizeof(double)*N*N);
	for(i=0; i<N; i++) {
		for(j=0; j<N; j++) {
			A1[i*N+j] = A[(i*N*N) + j];
			A2[i*N+j] = A[(i*N*N) + (N+j)];
			A3[i*N+j] = A[((i+N)*N*N) + j];
			A4[i*N+j] = A[((i+N)*N*N) + (N+j)];
			B1[i*N+j] = B[(i*N*N) + j];
			B2[i*N+j] = B[(i*N*N) + (N+j)];
			B3[i*N+j] = B[((i+N)*N*N) + j];
			B4[i*N+j] = B[((i+N)*N*N) + (N+j)];
		}
	}
	/* D1 */
	MA(A1, A4, T1, N, N);
	MA(B1, B4, T2, N, N);
	strassenMM2n(T1, T2, D1, N);
	/* D2 */
	MA(A3, A4, T1, N, N);
	strassenMM2n(T1, B1, D2, N);
	/* D3 */
	MS(B2, B4, T1, N, N);
	strassenMM2n(A1, T1, D3, N);
	/*D4 */
	MS(B3, B1, T1, N, N);
	strassenMM2n(A4, T1, D4, N);
	/* D5 */
	MA(A1, A2, T1, N, N);
	strassenMM2n(T1, B4, D5, N);
	/* D6 */
	MS(A3, A1, T1, N, N);
	MA(B1, B2, T2, N, N);
	strassenMM2n(T1, T2, D6, N);
	/* D7 */
	MS(A2, A4, T1, N, N);
	MA(B3, B4, T2, N, N);
	strassenMM2n(T1, T2, D7, N);
	/* C1 */
	MA(D1, D4, T1, N, N);
	MA(T1, D7, T2, N, N);
	MS(T2, D5, C1, N, N);
	/* C2 */
	MA(D3, D5, C2, N, N);
	/* C3 */
	MA(D2, D4, C3, N, N);
	/* C4 */
	MS(D1, D2, T1, N, N);
	MA(D3, D6, T2, N, N);
	MA(T1, T2, C4, N, N);

	for(i=0; i<N; i++) {
		for(j=0; j<N; j++) {
			C[(i*N*N)+j] = C1[i*N+j];
			C[(i*N*N)+(j+N)] = C2[i*N+j];
			C[((i+N)*N*N)+j] = C3[i*N+j];
			C[((i+N)*N*N)+(j+N)] = C4[i*N+j];
		}
	}
	free(A1);
	free(A2);
	free(A3);
	free(A4);
	free(B1);
	free(B2);
	free(B3);
	free(B4);
	free(C1);
	free(C2);
	free(C3);
	free(C4);
	free(D1);
	free(D2);
	free(D3);
	free(D4);
	free(D5);
	free(D6);
	free(D7);
	free(T1);
	free(T2);
	return(0);
}

int strassenMM(double *A, double *B, double *C, uint64_t M, uint64_t N, uint64_t P)
{
	uint64_t	minMNP, t, partitionSize;
	uint64_t	i, j;
	double		*A11, *A12, *A21, *A22;
	double 		*B11, *B12, *B21, *B22;
	double 		*C11, *C12, *C21, *C22;
	double 		*T11a, *T12a, *T21a, *T22a;
	double 		*T11b, *T12b, *T21b, *T22b;

	t = M < N ? M : N;
	minMNP = t < P ? t : P;

	partitionSize = pow(2, floor(log2(minMNP)));
	if(M == N && N == P && P == partitionSize) {
		strassenMM2n(A, B, C, partitionSize);
		return(0);
	}

	A11 = malloc(sizeof(double)*partitionSize * partitionSize);
	A12 = malloc(sizeof(double)*partitionSize * (N - partitionSize));
	A21 = malloc(sizeof(double)*(M-partitionSize) * partitionSize);
	A22 = malloc(sizeof(double)*(M-partitionSize) * (N - partitionSize));
	B11 = malloc(sizeof(double)*partitionSize * partitionSize);
	B12 = malloc(sizeof(double)*partitionSize * (P - partitionSize));
	B21 = malloc(sizeof(double)*(N-partitionSize) * partitionSize);
	B22 = malloc(sizeof(double)*(N-partitionSize) * (P - partitionSize));
	C11 = malloc(sizeof(double)*partitionSize * partitionSize);
	C12 = malloc(sizeof(double)*partitionSize * (P - partitionSize));
	C21 = malloc(sizeof(double)*(M-partitionSize) * partitionSize);
	C22 = malloc(sizeof(double)*(M-partitionSize) * (P - partitionSize));
	T11a = malloc(sizeof(double)*partitionSize * partitionSize);
	T12a = malloc(sizeof(double)*partitionSize * (P - partitionSize));
	T21a = malloc(sizeof(double)*(M-partitionSize) * partitionSize);
	T22a = malloc(sizeof(double)*(M-partitionSize) * (P - partitionSize));
	T11b = malloc(sizeof(double)*partitionSize * partitionSize);
	T12b = malloc(sizeof(double)*partitionSize * (P - partitionSize));
	T21b = malloc(sizeof(double)*(M-partitionSize) * partitionSize);
	T22b = malloc(sizeof(double)*(M-partitionSize) * (P - partitionSize));

	strassenMM2n(A11, B11, T11a, partitionSize);
	if(N > partitionSize) {
		strassenMM(A12, B21, T11b, partitionSize, (N-partitionSize), partitionSize);
		MA(T11a, T11b, C11, partitionSize, partitionSize);
	} else {
		memcpy(C11, T11a, partitionSize * partitionSize);
	}
	if(P > partitionSize) {
		strassenMM(A11, B12, T12a, partitionSize, partitionSize, (P - partitionSize));
		strassenMM(A12, B22, T12b, partitionSize, (N-partitionSize), (P - partitionSize));
		MA(T12a, T12b, C12, partitionSize, (P - partitionSize));
	}

	if(M > partitionSize) {
		strassenMM(A21, B11, T21a, (M-partitionSize), partitionSize, partitionSize);
		strassenMM(A22, B21, T21b, (M-partitionSize), (N - partitionSize), partitionSize);
		MA(T21a, T21b, C21, (M-partitionSize), partitionSize);
	}

	if(M > partitionSize && N > partitionSize) {
		strassenMM(A21, B12, T22a, (M-partitionSize), partitionSize, (P - partitionSize));
		strassenMM(A22, B22, T22b, (M-partitionSize), (N - partitionSize), (P - partitionSize));
		MA(T22a, T22b, C22, (M-partitionSize), (P - partitionSize));
	}

	for(i=0; i<partitionSize; i++) {
		for(j=0; j<partitionSize; j++) {
			C[M*i+j] = C11[partitionSize *i + j];
		}
	}

	for(i=0; i<partitionSize; i++) {
		for(j=0; j<P - partitionSize; j++) {
			C[M*i+(partitionSize+j)] = C12[(P - partitionSize)*i+j];
		}
	}

	for(i=0; i<(M-partitionSize); i++) {
		for(j=0; j<partitionSize; j++) {
			C[(partitionSize+M)*i+j] = C21[partitionSize*i + j];
		}
	}

	for(i=0; i<(M-partitionSize); i++) {
		for(j=0; j<(P - partitionSize); j++) {
			C[(partitionSize+M)*i+(partitionSize+j)] = C22[(P - partitionSize)*i+j];
		}
	}

	free(A11);
	free(A12);
	free(A21);
	free(A22);
	free(B11);
	free(B12);
	free(B21);
	free(B22);
	free(C11);
	free(C12);
	free(C21);
	free(C22);
	free(T11a);
	free(T12a);
	free(T21a);
	free(T22a);
	free(T11b);
	free(T12b);
	free(T21b);
	free(T22b);


	return;	
}

void printMatrix(double *A, uint64_t m, uint64_t n)
{
	uint64_t	i, j;
	for(i=0; i<m; i++) {
		for(j=0; j<n; j++) {
			printf("%f\t", A[i*n+j]);
		}
		printf("\n");
	}
}
