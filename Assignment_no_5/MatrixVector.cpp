#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 3   

int main() {
    int A[N][N] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int x[N] = {1, 2, 3};

    int y[N] = {0};

    int i, j;

    double st = omp_get_wtime();

    #pragma omp parallel for private(i, j) shared(A, x, y)
    for (i = 0; i < N; i++) {
        y[i] = 0;
        for (j = 0; j < N; j++) {
            y[i] += A[i][j] * x[j];
        }
    }

    double end = omp_get_wtime();
    printf("Matrix-Vector Multiplication completed in %f seconds\n", end - st);
    printf("Result Vector y:\n");
    for (i = 0; i < N; i++) {
        printf("%d ", y[i]);
    }
    printf("\n");

    return 0;
}
