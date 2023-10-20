#include <stdio.h>
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

void help(char* name) {
    printf("Correct usage: %s [N:long>1] [K:long>1]\n", name);
}

void print_sys_info() {
    int num_threads_available = omp_get_max_threads();
    printf("Core count: %d\n", omp_get_num_procs());
    printf("Thread count: %d\n", num_threads_available);
}

void compute_thread(const int* N, const int* K, const int* thread_count) {
    const double time1 = omp_get_wtime();
    #pragma omp parallel for num_threads(*thread_count)
    for(int i = 1; i < *N; i++) {
        #pragma omp parallel for num_threads(*thread_count)
        for(int j = 1; j < *K; j++) {
            double A = 1 / (i + j -1);
            double v = 1/j;
            double w = A*v;
        }
    }
    const double time2 = omp_get_wtime();
    printf("on %d threads: %.10f seconds\n", *thread_count, (time2-time1));
}

void compute(const int* N, const int* K) {
    printf("Computing w=Av for size N=%d, K=%d:\n", *N, *K);
    for(int thread = 1; thread <= omp_get_max_threads(); thread++) {
        compute_thread(N, K, &thread);
    }
}

int main(int argc, char* argv[]) {

    // omp_set_num_threads(omp_get_num_procs());

    if (argc != 3) { help(argv[0]); return -1; }
    const int N = strtol(argv[1], NULL, 10);
    const int K = strtol(argv[2], NULL, 10);
    if (N < 1 || K < 1) { help(argv[0]); return -1; }

    print_sys_info();
    compute(&N, &K);

    return 0;
}