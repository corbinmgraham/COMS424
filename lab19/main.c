#include <stdio.h>
#include "matrix.h"
#include <math.h>
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

void coarsegrain(const vector* x, const int* N, const int* thread_count) {
    const double time1 = omp_get_wtime();
    double norm = 0.0;

    #pragma omp parallel num_threads(*thread_count)
    {
        const int my_rank = omp_get_thread_num ();

        const int N_per_thread = *N / *thread_count;
        const int istart = my_rank * N_per_thread + 1;
        const int iend = (my_rank + 1) * N_per_thread;

        double norm_thread = 0.0;
        for (int i = istart; i <= iend; i++)
        { norm_thread += fabs(vgetp(x,i)); }

        #pragma omp critical
        norm += norm_thread;

        #pragma omp barrier // needed here

        for (int i = istart; i <= iend; i++)
        { vgetp(x,i) = vgetp(x,i) / norm; }
    }

    const double time2 = omp_get_wtime();
    printf("on %d threads: %.10f seconds\n", *thread_count, (time2-time1));
}

void finegrain(const vector* x, const int* N) {
    printf("Fine grain computation ");
    const double time1 = omp_get_wtime();
    double norm = 0.0;

    #pragma omp parallel for reduction(+:norm)
    for (int i=1; i <= *N; i++)
    { norm += fabs(vgetp(x,i)); }

    #pragma omp parallel for
    for (int i=1; i <= *N; i++)
    { vgetp(x,i) = vgetp(x,i)/norm; }

    const double time2 = omp_get_wtime();
    printf("in %.10f seconds\n", (time2-time1));
}

void help(char* name) {
    printf("Correct usage: %s [N:long>1]\n", name);
}

void print_sys_info() {
    int num_threads_available = omp_get_max_threads();
    printf("Core count: %d\n", omp_get_num_procs());
    printf("Thread count: %d\n", num_threads_available);
}

void compute(const vector* x, const int* N) {
    printf("Computing x=x/||x||_2 for size N=%d:\n", *N);
    finegrain(x, N);
    printf("Course grain computation:\n");
    for(int thread = 1; thread <= omp_get_max_threads(); thread++) {
        coarsegrain(x, N, &thread);
    }
}

int main(int argc, char* argv[]) {

    // omp_set_num_threads(omp_get_num_procs());

    if (argc != 2) { help(argv[0]); return -1; }
    const int N = strtol(argv[1], NULL, 10);
    if (N < 1) { help(argv[0]); return -1; }


    vector x = new_vector(N);

    print_sys_info();
    compute(&x, &N);

    return 0;
}