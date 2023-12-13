#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

#define M 10
#define N 10

void chunkArray(int matrix[M][N], int localMatrix[M][N], int localRows, int localCols, int rank, int size) {
    // Calculate the number of rows per process
    int rowsPerProcess = M / size;
    int remainingRows = M % size;

    // Calculate the starting row for each process
    int startRow = rank * rowsPerProcess + (rank < remainingRows ? rank : remainingRows);

    // Calculate the number of rows for each process
    localRows = rowsPerProcess + (rank < remainingRows ? 1 : 0);

    // Copy the relevant rows from the global matrix to the local matrix
    for (int i = 0; i < localRows; i++) {
        for (int j = 0; j < N; j++) {
            localMatrix[i][j] = matrix[startRow + i][j];
        }
    }
}

int main(int argc, char *argv[]) {
    MPI_Init(&argc, &argv);

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    // Define the global matrix
    int matrix[M][N];

    if (rank == 0) {
        // Initialize the global matrix in the root process
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                matrix[i][j] = i * N + j + 1;
            }
        }

        // Print the global matrix
        printf("Global Matrix:\n");
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                printf("%2d ", matrix[i][j]);
            }
            printf("\n");
        }
    }

    // Broadcast the global matrix dimensions
    MPI_Bcast(matrix, M * N, MPI_INT, 0, MPI_COMM_WORLD);

    // Allocate memory for the local matrix
    int localMatrix[M][N];
    int localRows, localCols;
    chunkArray(matrix, localMatrix, localRows, N, rank, size);

    // Print the local matrix in each process
    printf("Rank %d - Local Matrix:\n", rank);
    for (int i = 0; i < localRows; i++) {
        for (int j = 0; j < N; j++) {
            printf("%2d ", localMatrix[i][j]);
        }
        printf("\n");
    }

    MPI_Finalize();

    return 0;
}