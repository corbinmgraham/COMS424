#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "matrix.h"
#ifdef _OPENMP
#include <omp.h>
#endif

// #define print_var_name(var) (#var)

/*
Develop source codes (with OpenMP) for computing matrix-vector product
(w = Av) for the following matrix and vector, where A is a matrix of size N × K ,
and v is the K × 1 vector:

A = [a_ij], a_ij = 1 / (i + j -1), i = 1...N, j = 1...K

v_i = 1/i : i = 1...K

w(i) = \Sum_j=1^K (1/(i+j-1))(1/j)
*/

void help(int argc, char* argv[]) {
    printf("Incorrect usage: ");
    for(int i = 0; i < argc; i++) {
        printf("%s ", argv[i]);
    }
    printf("\n");
    printf("Correct usage: %s [N:int] [K:int]\n", argv[0]);
}

void print_sys_info() {
    int num_threads_available;
    #pragma omp parallel
    {
        num_threads_available = omp_get_num_threads();
    }
    printf("Core count: %d\n", omp_get_num_procs());
    printf("Thread count: %d\n", num_threads_available);
}

int main(int argc, char* argv[]) {

    // #pragma omp parallel for num_threads(thread_count)
    // if(argc < 3) help(argc, argv);
    print_sys_info();

    return 0;
}