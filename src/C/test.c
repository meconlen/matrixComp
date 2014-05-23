#include <stdio.h>
#include <stdlib.h>
#include <CUnit/Basic.h>

#include "matrix.h"


int main(int argc, char *argv[], char *envp[])
{
	CU_pSuite	matrixSuite;

	if(CU_initialize_registry() != CUE_SUCCESS) goto error0;

	if((matrixSuite = CU_add_suite("matrixSuite", init_matrixSuite, clean_matrixSuite)) == NULL) goto error1;
	// if((CU_add_test(matrixSuite, "matrix2X2()", unit_matrix2X2)) == NULL) goto error1;
	// if((CU_add_test(matrixSuite, "matrix2X3X4()", unit_matrix2X3X4)) == NULL) goto error1;
	// if((CU_add_test(matrixSuite, "matrix_dMMT()", unit_matrix_dMMT)) == NULL) goto error1;
	// if((CU_add_test(matrixSuite, "matrix_dMMT2()", unit_matrix_dMMT2)) == NULL) goto error1;
	// if((CU_add_test(matrixSuite, "matrix_MA()", unit_matrix_MA)) == NULL) goto error1;
	// if((CU_add_test(matrixSuite, "matrix_strassenMM2n2()", unit_matrix_strassenMM2n2)) == NULL) goto error1;
	// if((CU_add_test(matrixSuite, "matrix_strassenMM2n4()", unit_matrix_strassenMM2n4)) == NULL) goto error1;
	// if((CU_add_test(matrixSuite, "matrix_strassenMM1X1()", unit_matrix_strassenMM1X1)) == NULL) goto error1;
	// if((CU_add_test(matrixSuite, "matrix_strassenMM4X4()", unit_matrix_strassenMM4X4)) == NULL) goto error1;
//	if((CU_add_test(matrixSuite, "matrix_strassenMM5X7X9()", unit_matrix_strassenMM5X7X9)) == NULL) goto error1;
	if((CU_add_test(matrixSuite, "matrix_strassenMMVariable()", unit_matrix_strassenMMVariable)) == NULL) goto error1;
	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	return(0);
error1:
	fprintf(stderr, "matrixSuite setup error\n");
	CU_cleanup_registry();
	exit(CU_get_error());

error0:
	fprintf(stderr, "test setup error\n");
	exit(CU_get_error());
}

