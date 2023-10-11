#include <stdlib.h>
#include <stdio.h>
#include <time.h>
// #include "matrix.h"
#include <assert.h>
#include "trimatrix.h"

/**
 * @brief Main entrance to program
 * 
 * @return int Error Value
 */
int main() {
    // Make the random state repeatable
    srand(1);

    // Input the matrix dimensions
    int N=0;
    printf("Input N: ");
    scanf("%i", &N);
    assert(N > 1);

    // Create a random symmetric matrix
    matrix A = new_matrix(N,N);

    // Initialize Cells
    for(int i=1; i <=N; i++)
    for(int j=1; j <=i; j++)
    {
        double tmp = ((double)rand()) / ((double)RAND_MAX);
        tmp = (double) ((int)(10000.0 * tmp)) / 10000.0;
        mget(A,i,j) = tmp;
    }

    // Mirror cells
    for(int i=1; i <= (N-1); i++)
    for(int j=(i+1); j <= N; j++)
    { mget(A,i,j) = mget(A,j,i); }

    for(int i=1; i <= N; i++)
    for(int j=1; j <= N; j++)
    { if(i == j) mget(A,i,j) = 1; }

    // Hessenberg reduction to tridiagonal form
    trimatrix T = new_trimatrix(N);
    void Hessenberg(const matrix* A, trimatrix* T);
    Hessenberg(&A ,&T);
    printf("\n");
    printf("Original Matrix:\n");
    print_matrix(&A);
    printf("Reduction to Tridiagonal Form:\n");
    print_trimatrix(&T);

    // QR Algorithm to find eigenvalues of T
    // which are the same as the eigenvalues of A
    void QRA(trimatrix* T);
    QRA(&T);
    printf("After QR Algorithm:\n");
    print_trimatrix(&T);

    return 0;
}