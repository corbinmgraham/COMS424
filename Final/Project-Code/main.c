#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <mpi.h>

#include <math.h>
#include <time.h>

// set the max size for an image
#define M 502
#define N 502

// #include "encrypt.h"

// Generated from keygen
// p = 149; q = 197, n = p*q
int g = 46822; // Random 16-bit number
int n = 48443; // 16-bit prime product
int n2 = 2346724249; // n-squared
int l = 24000; // lambda
int u = 3390; // Inversion of L(g,l)

// Image
int img[M][N][3];

/**
 * @brief Encrypt a number
 * 
 * @param m positive integer
 * @return int 
 */
int encrypt(int m) {
    int r = 1 + (random() % (n-2));
    int result = (int) pow(g,m) % n2;
    int x = (int) pow(r,n) % n2;
    result = (result * x) % n2;
    return (int) result;
}

/**
 * @brief Decrypt a number
 * 
 * @param c Encrypted value
 * @return int 
 */
int decrypt(int c) {
    int p = (int) ((((((int) pow(c,l) % n2) -1) / n) * u) % n);
    return p;
}

/**
 * @brief Modify an encrypted number
 * 
 * @param c Encrypted value
 * @param m Modify amount
 * @return int 
 */
int modify(int c, int m) {
    return (int) (c * encrypt(m)) % n2;
}

void get_image_from_file() {
    FILE *file = fopen("img_demo.3dimage", "r");

    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }

    int row = 0, col = 0;
    int r, g, b;

    while (fscanf(file, "%d,%d,%d,", &r, &g, &b) == 1) {
        img[row][col][0] = r;
        img[row][col][1] = g;
        img[row][col][2] = b;

        col++;

        // Move to the next row if we reach the maximum columns
        if (col == M) {
            col = 0;
            row++;
        }

        // Break if we reach the maximum rows
        if (row == N) {
            break;
        }
    }

    fclose(file);
}

void save_image_to_file() {
    FILE *file = fopen("img_demo_modified.3dimage", "w");

    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }

    for(int row = 0; row < M; row++) {
        for(int col = 0; col < N; col++) {
            fprintf(file, "%d,%d,%d,", img[row][col][0], img[row][col][1], img[row][col][2]);
        }
    }

    fclose(file);
}

void display_image() {
    for(int row = 0; row < M; row++) {
        for(int col = 0; col < N; col++) {
            printf("%d,%d,%d,", img[row][col][0], img[row][col][1], img[row][col][2]);
        }
    }
}

void tmp_img_gen() {
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            for(int z = 0; z < 3; z++) {
                img[i][j][z] = 1;
            }
        }
    }
}

/**
 * @brief Get the input object
 * 
 * @param argc 
 * @param argv 
 * @param my_rank 
 * @param comm_sz 
 * @param a 
 * @param b 
 * @param N 
 */
void chunk_image()
{
    // void usage(const char * prog_name);
    // if(my_rank == 0) {
    //     if(argc != 4) { usage(argv [0]); }

    //     *a = strtod(argv [1], NULL);
    //     *b = strtod(argv [2], NULL);
    //     *N = strtol(argv [3], NULL, 10);
    //     if(*N <=0) { usage(argv [0]); }
    //     if(*N% comm_sz !=0) { usage(argv [0]); }
    //     for(int i=1; i< comm_sz; i++) {
    //         MPI_Send(a, 1, MPI_DOUBLE, i, 0, MPI_COMM_WORLD);
    //         MPI_Send(b, 1, MPI_DOUBLE, i, 0, MPI_COMM_WORLD);
    //         MPI_Send(N, 1, MPI_INT, i, 0, MPI_COMM_WORLD);
    //     }
    // }
    // else {
    //     MPI_Recv(a, 1, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD, 
    //     MPI_STATUS_IGNORE);
    //     MPI_Recv(b, 1, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD, 
    //     MPI_STATUS_IGNORE);
    //     MPI_Recv(N, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, 
    //     MPI_STATUS_IGNORE);
    // }
}

/**
 * @brief Entry for Program
 * 
 * @param argc Number of arguments
 * @param argv Argument array
 * @return int 
 */
int main(int argc, char* argv [])
{
    // Set the random to 1 for reproducibility
    srand(1);

    // tmp_img_gen();
    // display_image();
    
    
    // modify(10,10);
    // printf("Success %d", decrypt(encrypt(10)));

    // Setup MPI code
    int comm_sz, my_rank;
    MPI_Init(NULL, NULL);
    MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

    // Get start time
    double time_start;
    if(my_rank == 0)
    { time_start = MPI_Wtime(); }

    // Run local chunk

    chunk_image();

    // const double h =(b-a)/((double)N);
    // const int local_N = N/ comm_sz;
    // const double local_a = a +((double)(my_rank * local_N))*h;
    // const double local_b = local_a +((double) local_N)*h;
    // double CompTrap(const double a, const double b, 
    // const int N, const double h);
    // double local_T = CompTrap(local_a, local_b, local_N, h);

    // Add local results to the global result on Processor 0
    // if(my_rank != 0) {
    //     MPI_Send(&local_T, 1, MPI_DOUBLE, 0, 0, 
    //     MPI_COMM_WORLD);
    // } else {
    //     global_T = local_T;
    //     for(int i=1; i< comm_sz; i++) {
    //         MPI_Recv(&local_T, 1, MPI_DOUBLE, i, 0, 
    //         MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    //         global_T += local_T;
    //     }
    //     const double Tex = exp(b)-exp(a);
    //     error = fabs(Tex - global_T)/fabs(Tex);
    // }

    // Print Results
    if(my_rank == 0) {
        double time_end = MPI_Wtime();
        double time_elapsed = time_end - time_start;
        printf( "Number of Processors = %2i\n"
                "Elapsed Time = %20.13e\n",
                comm_sz, time_elapsed);
    }

    // End program
    MPI_Finalize();
    return 0;
}