#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "matrix.h"

/*
int main() {
    // Matrices
    matrix A = new_matrix(5,5);
    matrix B = new_matrix(5,5);

    for(int i=1; i <=5; i++) {
        for(int j=1; j <=5; j++) {
            mget(A,i,j) = -1.0*(i==j)
            + 2.0*(i -1==j) + 2.0*(j -1==i);
            mget(B,i,j) = 2.0*(i==j)
            + 1.0*(i -1==j) + 1.0*(j -1==i);
        }
    }

    // Print matrices
    print_matrix(&A);
    print_matrix(&B);
    // Add/ Subtract / Multiply matrices
    matrix Csum = matrix_add(&A ,&B); print_matrix(& Csum);
    // matrix Cdiff = matrix_sub(&A ,&B); print_matrix(& Cdiff);
    matrix Cprod = matrix_mult(&A ,&B); print_matrix(& Cprod);
    matrix Cdot = matrix_dot_mult(&A ,&B); print_matrix(& Cdot);
    // Vectors
    vector x = new_vector(5);
    vector y = new_vector(5);

    vget(x ,1) = 1.0; vget(y ,1) = 1.0;
    vget(x ,2) = 0.0; vget(y ,2) = 2.0;
    vget(x ,3) = 1.0; vget(y ,3) = 3.0;
    vget(x ,4) = 0.0; vget(y ,4) = 4.0;
    vget(x ,5) = 1.0; vget(y ,5) = 5.0;

    // Print vectors
    print_vector(&x);
    print_vector(&y);
    // Add/ Subtract / Multiply vectors
    vector zsum = vector_add(&x ,&y); print_vector(& zsum);
    // vector zdiff = vector_sub(&x ,&y); print_vector(& zdiff);
    double zdot = vector_dot_mult(&x ,&y); print_scalar(& zdot);
    // Matrix vector multiply
    vector Ax = matrix_vector_mult(&A ,&x);
    print_vector(& Ax);

    // Linear solve via Gaussian elimination
    vector soln = solve(&A ,&y);
    print_vector(& soln);
    return 0;
}
*/




int main() {

    srand(1);

    // Include documentation on each function 
    int N = 0;
    printf("Input N size: ");
    scanf("%d", &N);
    matrix L = new_matrix(N,N);

    // Randomize
    for(int i=1; i <= N; i++) {
        for(int j=1; j <= N; j++) {
            if(i == j) mget(L,i,j) = 1;
            else mget(L,i,j) = ((double)(rand() % 100) / 99);
        }
    }

    matrix L_T = matrix_transpose(&L);
    matrix A = matrix_dot_mult(&L, &L_T);
    vector b = new_vector(N);

    print_matrix(&L);
    print_matrix(&L_T);

    for(int i = 1; i <= N; i++) {
        vget(b,i) = ((double)(rand() % 100) / 99);
    }

    print_matrix(&A);
    print_vector(&b);

    vector result = solve(&A, &b);
    print_vector(&result);

    // Input Size N from terminal using scanf

    // Generate Lower-Triangular L^NxN matrix(L)
    /*
        L =(1
                ...
                    1) Diagonal
    */

    // A = LL^T

    // Generate random between 0 and 1: rand() % 100 / 99
    return 0;
}