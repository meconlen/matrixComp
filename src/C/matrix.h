#ifndef MATRIX_H
#define MATRIX_H

#include <config.h>
#include <stdint.h>

/* matrixSuite setup and teardown */

int init_matrixSuite(void);
int clean_matrixSuite(void);

/* matrixSuite tests */

void unit_matrix2X2(void);
void unit_matrix2X3X4(void);
void unit_matrix_dMMT(void);
void unit_matrix_dMMT2(void);
void unit_matrix_MA(void);
void unit_matrix_strassenMM2n2(void);
void unit_matrix_strassenMM2n4(void);
void unit_matrix_strassenMM1X1(void);
void unit_matrix_strassenMM4X4(void);
void unit_matrix_strassenMM5X7X9(void);
void unit_matrix_strassenMMVariable(void);

/* matrix multiplication */
/* C=A*B */
/* Where A is m x n, B is n x p and C is m x p */
/* C is not assumed to be zero filled */
/* A, B and C are row major ordered */
/* That is A[m][n] * B[n][p] = C[m][p] */

int dMM(double *A, double *B, double *C, uint64_t m, uint64_t n, uint64_t p);
int dMMT(double *A, double *B, double *C, uint64_t m, uint64_t n, uint64_t p);
int dMMT2(double *A, double *B, double *C, uint64_t m, uint64_t n, uint64_t p);
int dMMT2r(double *restrict A, double *restrict B, double *restrict C, uint64_t m, uint64_t n, uint64_t p);
int MA(double *A, double *B, double *C, uint64_t M, uint64_t N);
int MS(double *A, double *B, double *C, uint64_t M, uint64_t N);
int powerOfTwo(uint64_t x);
int strassenMM2n(double *A, double *B, double *C, uint64_t M);
int strassenMM(double *A, double *B, double *C, uint64_t M, uint64_t N, uint64_t P);

void printMatrix(double *A, uint64_t m, uint64_t n);

#endif