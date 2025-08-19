#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define R 3   
#define C 3

int main() {
    int A[R][C] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int scalar = 5;
    int i, j;

    double st = omp_get_wtime();

    #pragma omp parallel for private(i, j) shared(A, scalar)
    for (i = 0; i < R; i++) {
        for (j = 0; j < C; j++) {
            A[i][j] *= scalar;
        }
    }

    double end = omp_get_wtime();
    printf("Matrix-Scalar Multiplication completed in %f seconds\n", end - st);

    printf("Result Matrix A:\n");
    for (i = 0; i < R; i++) {
        for (j = 0; j < C; j++) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }

    return 0;
}
