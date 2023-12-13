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

/**
 * @brief Read the image from a file
 * 
 */
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

/**
 * @brief Save the image to a file
 * 
 */
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

/**
 * @brief Display the image
 * 
 */
void display_image() {
    for(int row = 0; row < M; row++) {
        for(int col = 0; col < N; col++) {
            printf("%d,%d,%d,", img[row][col][0], img[row][col][1], img[row][col][2]);
        }
    }
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

    get_image_from_file();

    // Setup MPI code
    int comm_sz, my_rank;
    MPI_Init(NULL, NULL);
    MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

    // Get start time
    double time_start;
    if(my_rank == 0)
    { time_start = MPI_Wtime(); }

    // Calculate the number of rows per process
    int process_rows = M / comm_sz;
    int remainingRows = M % comm_sz;

    // Calculate the starting row for each process
    int start_row = my_rank * process_rows + (my_rank < remainingRows ? my_rank : remainingRows);

    // Calculate the number of rows for each process
    int local_rows = process_rows + (my_rank < remainingRows ? 1 : 0);

    // Allocate memory for the local matrix
    int local_img[local_rows][N][3];

    // move values to local image
    for (int i = 0; i < local_rows; i++) {
        for (int j = 0; j < N; j++) {
            local_img[i][j][0] = img[start_row + i][j][0];
            local_img[i][j][1] = img[start_row + i][j][1];
            local_img[i][j][2] = img[start_row + i][j][2];
        }
    }

    // encrypt local image chunk
    for (int i = 0; i < local_rows; i++) {
        for (int j = 0; j < N; j++) {
            local_img[i][j][0] = encrypt(local_img[i][j][0]);
            local_img[i][j][1] = encrypt(local_img[i][j][1]);
            local_img[i][j][2] = encrypt(local_img[i][j][2]);
        }
    }

    // modify local image chunk
    for (int i = 0; i < local_rows; i++) {
        for (int j = 0; j < N; j++) {
            local_img[i][j][0] = modify(local_img[i][j][0], 10);
            local_img[i][j][1] = modify(local_img[i][j][1], 10);
            local_img[i][j][2] = modify(local_img[i][j][2], 10);
        }
    }

    // Recombine chunks and decrypt
    MPI_Gather(local_img, local_rows * N, MPI_INT, img, local_rows * N, MPI_INT, 0, MPI_COMM_WORLD);

    printf("----------\n");
    printf("Local Rank: %d\n", my_rank);
    printf("Local Size: %.2f%%\n", (double) ((process_rows/M) * 100));
    printf("----------\n");

    // Print Results
    if(my_rank == 0) {
        double time_end = MPI_Wtime();
        double time_elapsed = time_end - time_start;
        printf( "Number of Processors = %2i\n"
                "Elapsed Time = %20.13e\n",
                comm_sz, time_elapsed);
        save_image_to_file();
    }

    // End program
    MPI_Finalize();
    return 0;
}