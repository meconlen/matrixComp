#include <stdlib.h>

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

void unit_matrixFoo(void)
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

	rc = dMM(A, B, C, 2, 2, 2);
	CU_ASSERT(rc == 0);
	CU_ASSERT(C[0][0] == 19);
	CU_ASSERT(C[0][1] == 22);
	CU_ASSERT(C[1][0] == 43);
	CU_ASSERT(C[1][1] == 50);
	return;
}

int dMM(double **A, double **B, double **C, uint64_t m, uint64_t n, uint64_t p)
{
	uint64_t	i, j;
	return(-2);
}
