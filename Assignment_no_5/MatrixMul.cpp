#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 500 

int main() {
    int A[N][N] = {{1, 2, 3},
                   {4, 5, 6},
                   {7, 8, 9}};

    int B[N][N] = {{9, 8, 7},
                   {6, 5, 4},
                   {3, 2, 1}};

    int C[N][N] = {0};
    int i, j, k;

    double st = omp_get_wtime();

    #pragma omp parallel for private(i, j, k) shared(A, B, C)
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
             for (k = 0; k < N; k++)
             {
                 C[i][j] += A[i][k] * B[k][j];
             }
        }
    }
    double end = omp_get_wtime();
    printf("Matrix-Matrix Multiplication completed in %f seconds\n", end - st);

    return 0;
}
