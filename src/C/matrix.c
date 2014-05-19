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

int dMMb(double *A, double *B, double *C, uint64_t m, uint64_t n, uint64_t p)
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

int dMM2(double *A, double *B, double *C, uint64_t m, uint64_t n, uint64_t p)
{
	uint64_t	i, j, k;
	uint64_t	rowA, rowB, rowC, colA, colB, colC;
	uint64_t	indexA, indexB, indexC;
	memset(C, 0, m*p*sizeof(double));
	for(i=0; i<m; i++) {
		rowC = i*p;
		rowA = i*n;
		for(j=0; j<p; j++) {
			indexC = rowC + j;
			for(k=0; k<n; k++) {
				rowB = k*p; indexB = rowB+j;
				indexA = rowA+k;
				C[indexC] += A[indexA] * B[indexB];
			}
		}
	}
	return(0);
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
