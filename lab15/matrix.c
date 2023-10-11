#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <math.h>
#include "matrix.h"

/**
 * @brief Creates a new matrix
 * 
 * @param rows Number of rows
 * @param cols Number of columns
 * @return matrix 
 */
matrix new_matrix(const int rows, const int cols) {
    matrix mat;
    mat.rows = rows;
    mat.cols = cols;
    assert (rows >0);
    assert (cols >0);
    mat.val = ( double *) malloc ( sizeof ( double )*rows*cols);

    for (int i=0; i <( rows*cols); i++) {
        mat.val[i] = 0.0;
    }

    return mat;
}

/**
 * @brief Frees up matrix
 * 
 * @param m Matrix
 */
void delete_matrix(matrix* m) {
    free(m->val);
}

/**
 * @brief Prints a matrix to stdout
 * 
 * @param mat Matrix
 * @param varname Matrix's Name
 */
void print_matrix_full ( const matrix * mat , char* varname ) {
    assert (mat->rows >0); assert (mat ->cols >0);
    printf ("\n %.100s =\n", & varname [1] );
    for(int i=1; i <=mat ->rows; i++ )
    {
    printf (" | ");
    for(int j=1; j <=mat ->cols; j++)
    {
    printf (" %10.3e", mgetp (mat ,i,j));
    if (j<mat ->cols) { printf (", ");}
    else { printf (" ");}
    }
    printf ("|\n");
    }
    printf ("\n");
}

/**
 * @brief Add two matrices
 * 
 * @param A Matrix A
 * @param B Matrix B
 * @return matrix 
 */
matrix matrix_add ( const matrix * A, const matrix * B) {
    const int rows = A->rows;
    const int cols = A->cols;
    assert (rows ==B->rows);
    assert (cols ==B->cols);
    matrix C = new_matrix (rows ,cols);
    for (int i=1; i <= rows; i++)
    for (int j=1; j <= cols; j++) {
        mget(C,i,j) = mgetp (A,i,j)+ mgetp (B,i,j);
    }

    return C;
}

/**
 * @brief Subtract two matrices
 * 
 * @param A Matrix A
 * @param B Matrix B
 * @return matrix 
 */
matrix matrix_sub(const matrix * A, const matrix * B) {
    const int rows = A->rows;
    const int cols = A->cols;
    assert (rows ==B->rows);
    assert (cols ==B->cols);
    matrix C = new_matrix (rows ,cols);
    for (int i=1; i <= rows; i++)
    for (int j=1; j <= cols; j++) {
        mget(C,i,j) = mgetp (A,i,j) - mgetp (B,i,j);
    }

    return C;
}

/**
 * @brief Multiply two matrices
 * 
 * @param A Matrix A
 * @param B Matrix B
 * @return matrix 
 */
matrix matrix_mult ( const matrix * A, const matrix * B) {
    const int rowsA = A->rows; const int colsA = A->cols;
    const int rowsB = B->rows; const int colsB = B->cols;
    assert ( colsA == rowsB );
    matrix C = new_matrix (rowsA , colsB );
    for (int i=1; i <= rowsA ; i++)
    for (int j=1; j <= colsB ; j++)
    for (int k=1; k <= colsA ; k++)
    {
    mget(C,i,j) += mgetp (A,i,k)* mgetp (B,k,j);
    }

    return C;
}

/**
 * @brief Transpose of a Matrix
 * 
 * @param mat Matrix
 * @return matrix
 */
matrix matrix_transpose(const matrix* A) {
    const int rows = A->rows;
    const int cols = A->cols;
    matrix C = new_matrix(cols,rows);
    for (int i=1; i <= cols; i++)
    for (int j=1; j <= rows; j++) {
        mget(C,i,j) = mgetp(A,j,i);
    }
    return C;
}

/**
 * @brief Dot product of two matrices
 * 
 * @param A Matrix A
 * @param B Matrix B
 * @return matrix 
 */
matrix matrix_dot_mult ( const matrix * A, const matrix * B) {
    const int rows = A->rows;
    const int cols = A->cols;
    assert (rows ==B->rows);
    assert (cols ==B->cols);
    matrix C = new_matrix (rows ,cols);
    for (int i=1; i <= rows; i++)
    for (int j=1; j <= cols; j++)
    {
    mget(C,i,j) = mgetp (A,i,j)* mgetp (B,i,j);
    }

    return C;
}

/**
 * @brief Create a new vector
 * 
 * @param size Size of vector (length)
 * @return vector 
 */
vector new_vector ( const int size) {
    vector vec;
    vec.size = size;
    assert (size >0);
    vec.val = ( double *) malloc ( sizeof ( double )*size);
    for (int i=0; i <( size); i++)
    { vec.val[i] = 0.0; }

    return vec;
}

/**
 * @brief Frees up vector
 * 
 * @param v Vector
 */
void delete_vector(vector* v) {
    free(v->val);
}

/**
 * @brief Prints a vector to stdout
 * 
 * @param vec Vector
 * @param varname Vector's Name
 */
void print_vector_full ( const vector * vec , char* varname ) {
    assert (vec ->size >0);
    printf ("\n");
    printf (" %.100s =\n", & varname [1] );
    printf (" | ");
    for(int i=1; i <=vec ->size; i++ )
    {
    printf (" %10.3e",vgetp (vec ,i));
    if (i<vec ->size) { printf (", ");}
    }
    printf (" |^T\n\n");
}

/**
 * @brief Add two vectors
 * 
 * @param x Vector x
 * @param y Vector y
 * @return vector 
 */
vector vector_add ( const vector * x, const vector * y) {
    const int size = x->size;
    assert (size ==y->size);
    vector z = new_vector (size);
    for (int i=1; i <= size; i++)
    {
    vget(z,i) = vgetp (x,i)+ vgetp (y,i);
    }

    return z;
}

/**
 * @brief Dot product of two vectors
 * 
 * @param x Vector x
 * @param y Vector y
 * @return double 
 */
double vector_dot_mult ( const vector * x, const vector * y) {
    const int size = x->size; assert (size ==y->size);
    double z = 0.0;
    for (int i=1; i <= size; i++)
    { z += vgetp (x,i)* vgetp (y,i); }
    return z;
}

/**
 * @brief Prints scalar to stdout
 * 
 * @param z Scalar
 * @param varname Variable name
 */
void print_scalar_full ( const double * z, char* varname ) {
    printf ("\n %.100s =\n", &varname[1]);
    printf (" %10.3e \n\n", *z);
}

/**
 * @brief Multiply a vector and matrix
 * 
 * @param A Matrix A
 * @param x Vector x
 * @return vector 
 */
vector matrix_vector_mult ( const matrix * A, const vector * x) {
    const int rows = A->rows; const int cols = A->cols;
    const int size = x->size;
    assert (cols == size);
    vector Ax = new_vector (rows);
    for (int i=1; i <= rows; i++)
    {
    double tmp = 0.0;
    for (int j=1; j <= size; j++)
    { tmp += mgetp(A,i,j)* vgetp (x,j); }
    vget(Ax ,i) = tmp;
    }

    return Ax;
}

/**
 * @brief Solve x for Ax=b
 * 
 * @param A Matrix A
 * @param b Vector b
 * @return vector 
 */
vector solve ( const matrix * A, const vector * b) {
    const int rows = A->rows; const int cols = A->cols;
    const int size = b->size;
    assert (rows == cols); assert (rows == size);
    vector x = new_vector (rows);
    for (int i=1; i <=( size -1); i++) // LOOP OVER EACH COLUMN
    {
    // Select largest pivot in current column
    int p=i;
    double maxA = -100.0e0;
    for (int j=i; j <= size; j++)
    {
    double tmp = fabs( mgetp (A,j,i));
    if ( tmp > maxA ){ p = j; maxA = tmp; }
    }

    // See if matrix is singular
    if (maxA <= 1.0e-14)
    { printf (" Cannot invert system \n"); exit (1); }
    // Pivot (aka interchange rows)
    if (p!=i)
    {
    for (int j=1; j <= size; j++)
    {
    double tmp1 = mgetp (A,i,j);
    mgetp (A,i,j) = mgetp (A,p,j); mgetp (A,p,j) = tmp1;
    }
    double tmp2 = vgetp (b,i);
    vgetp (b,i) = vgetp (b,p); vgetp (b,p) = tmp2;
    }

    // Eliminate below diagonal
    for (int j=(i+1); j <= size; j++)
    {
    double dm = mgetp (A,j,i)/ mgetp (A,i,i);
    for (int k=1; k <= size; k++)
    { mgetp (A,j,k) = mgetp (A,j,k) - dm* mgetp (A,i,k); }
    vgetp (b,j) = vgetp (b,j) - dm* vgetp (b,i);
    }
    }
    // Backward substitution
    vget(x,size) = vgetp (b,size)/ mgetp (A,size ,size);
    for (int j=1; j <=( size -1); j++)
    {
    double sum = 0.0e0;
    for (int k=( size -j+1); k <= size; k++)
    { sum = sum + mgetp (A,size -j,k)*vget(x,k); }
    vget(x,size -j) = ( vgetp (b,size -j) - sum)
    / mgetp (A,size -j,size -j);
    }

    return x;
}

/**
 * @brief Calculate the mean of a matrix
 * 
 * @param A Matrix A
 * @return double
 */
double matrix_mean(const matrix* A) {
    const int rows = A->rows;
    const int cols = A->cols;
    double mean = 0.0;
    for (int i=1; i <= rows; i++)
    for (int j=1; j <= cols; j++)
    {
        mean += mgetp(A,i,j);
    }
    mean /= (rows+cols);

    return mean;
}

/**
 * @brief Apply a scalar to a matrix
 * 
 * @param A Matrix A
 * @param scalar Scalar
 * @return matrix 
 */
matrix matrix_scale(matrix* A, double scalar) {
    const int rows = A->rows;
    const int cols = A->cols;
    matrix C = new_matrix(rows, cols);
    for (int i=1; i <= rows; i++)
    for (int j=1; j <= cols; j++)
    {
        mget(C,i,j) = mgetp(A,i,j) * scalar;
    }

    return C;
}

/**
 * @brief Normalization of a vector
 * 
 * @param v vector
 */
void normalize(vector *v) {
    double norm = 0.0;
    for (int i = 1; i <= v->size; i++) {
        norm += vgetp(v, i) * vgetp(v, i);
    }
    norm = sqrt(norm);
    for (int i = 1; i <= v->size; i++) {
        vgetp(v, i) /= norm;
    }
}

/**
 * @brief Calculate eigenvalues for matrix using power iteration method
 * 
 * @param v vector
 * @param TOL tolerence
 * @param MaxIters maximum number of iterations
 * @param A matrix
 */
void power_iteration(vector* v, double TOL, int MaxIters, matrix *A) {
    unsigned mstop = 0;
    int k = 0;
    double lambda_prev = 0.0;

    normalize(v);
    vector Av = matrix_vector_mult(A, v);
    double lambda = vector_dot_mult(v, &Av);

    while (mstop == 0) {
        k++;
        vector w = matrix_vector_mult(A,v);
        normalize(&w);
        *v = w;
        Av = matrix_vector_mult(A, v);
        lambda = vector_dot_mult(v, &Av);

        if (fabs(lambda - lambda_prev) < TOL || k == MaxIters) mstop = 1;
        lambda_prev = lambda;
    }

    // Output: lambda_k (approximation for lambda_1 after k iterations)
    printf("Eigenvalue estimation via Power Iteration Algorithm: %10.3e\n", lambda);
}

/**
 * @brief Calculate eigenvalues for matrix using shifted inverse power iteration method
 * 
 * @param mean Mean of matrix A
 * @param v vector
 * @param TOL Tolerence
 * @param MaxIters Max number of iterations
 * @param A Matrix A
 */
void shifted_inverse_power_iteration(double mean, vector* v, double TOL, int MaxIters, matrix *A) {
    unsigned mstop = 0;
    int k = 0;
    double lambda_prev = 0.0;

    normalize(v);
    vector Av = matrix_vector_mult(A, v);
    double lambda = vector_dot_mult(v, &Av);

    while (mstop == 0) {
        k++;
        matrix I = new_matrix(A->rows, A->cols);
        I = matrix_scale(&I, mean);
        matrix new_a = matrix_sub(A, &I);
        vector w = matrix_vector_mult(&new_a,v);
        normalize(&w);
        *v = w;
        Av = matrix_vector_mult(A, v);
        lambda = vector_dot_mult(v, &Av);

        if (fabs(lambda - lambda_prev) < TOL || k == MaxIters) mstop = 1;
        lambda_prev = lambda;
    }

    // Output: lambda_k (approximation for lambda_1 after k iterations)
    printf("Eigenvalue estimation via Shifted Inverse Power Iteration Algorithm: %10.3e\n", lambda);
}