#include<stdio.h>
#include<stdlib.h>

// Declare constant maximum memory size of matrix
#define MAX_SIZE 100

// Declare function
// === Support Functions ===
// void init_random_matrix(int matrix[][MAX_SIZE], int, int, int, int);
void init_random_matrix(int (*matrix)[MAX_SIZE], int num_of_rows, int num_of_cols, int min, int max);
void print_matrix(int (*matrix)[MAX_SIZE], int num_of_rows, int num_of_cols);
// ==== Main function ====
void multiply_two_matrices(int (*first_matrix)[MAX_SIZE], int (*second_matrix)[MAX_SIZE], 
                        int (*multiplication_matrix)[MAX_SIZE], int rows_of_first_matrix, 
                        int cols_of_first_matrix, int cols_of_second_matrix);

int main(){
    // Write program to multiply two matrices
    /*
    Note: The number of cols of the first matrix must be equal to the number 
        of rows of second matrix
        If matrix m x n multiplies with matrix n x k, then matrix result will be m x k
    */

    // Declare matrix and matrix size
    int first_matrix[MAX_SIZE][MAX_SIZE],
        second_matrix[MAX_SIZE][MAX_SIZE],
        multiplication_matrix[MAX_SIZE][MAX_SIZE];
    int rows_of_first_matrix, cols_of_first_matrix, 
        rows_of_second_matrix, cols_of_second_matrix;

    // Enter the matrix size
    printf("Enter the number of rows of the first matrix: ");
    scanf("%d", &rows_of_first_matrix);
    printf("Enter the number of columns of the first matrix: ");
    scanf("%d", &cols_of_first_matrix);

    printf("Enter the number of rows of the second matrix: ");
    scanf("%d", &rows_of_second_matrix);
    printf("Enter the number of columns of the second matrix: ");
    scanf("%d", &cols_of_second_matrix);

    // Check the size of matrix is suitable
    if(rows_of_first_matrix > MAX_SIZE || cols_of_first_matrix > MAX_SIZE || 
        rows_of_second_matrix > MAX_SIZE || cols_of_second_matrix > MAX_SIZE){
        printf("Don't enough memory to allocate, the matrix size must not be greater 1000");
        exit(0);
    }
    
    // The number of cols of the first matrix must be equal to the number of rows of second matrix
    if(cols_of_first_matrix != rows_of_second_matrix){
        printf("The number of cols of the first matrix must be equal to the number of rows of second matrix");
        exit(0);
    }

    // Initialize matrix automatically by random function
    int min = 5, max = 10;
    init_random_matrix(first_matrix, rows_of_first_matrix, cols_of_first_matrix, min, max);
    init_random_matrix(second_matrix, rows_of_second_matrix, cols_of_second_matrix, min, max);
    // Check values of matrix by printing
    printf("First matrix: \n");
    print_matrix(first_matrix, rows_of_first_matrix, cols_of_first_matrix);
    printf("Second matrix: \n");
    print_matrix(second_matrix, rows_of_second_matrix, cols_of_second_matrix);

    multiply_two_matrices(first_matrix, second_matrix, multiplication_matrix, 
                            rows_of_first_matrix, cols_of_first_matrix, cols_of_second_matrix);

    // Result
    printf("\nAddition matrix: \n");
    print_matrix(multiplication_matrix, rows_of_first_matrix, cols_of_second_matrix);
    return 0;
}

// Define functions
// === Support function ===
void init_random_matrix(int (*matrix)[MAX_SIZE], int num_of_rows, int num_of_cols, int min, int max){
    /*
    Initialize random values ​​for matrix of given size in the range from min to max
    Parameters:
        matrix: 1-d matrix with 'int' data type
                the matrix use to store random values
        arr_size: 'int'
                the size of matrix
        min: 'int'
                the minimum value in the range you want to random
        max: 'int'
                the maximum value in the range you want to random
    */
    for(int i = 0; i < num_of_rows; i++){
        for(int j = 0; j < num_of_cols; j++){
            matrix[i][j] = rand() % (max - min + 1) + min;
        }
    }
}

void print_matrix(int (*matrix)[MAX_SIZE], int num_of_rows, int num_of_cols){
    /*
    Print values of matrix
    Parameters:
        matrix: 1-d matrix with 'int' data type
                The matrix is printed
        arr_size: 'int'
                the size of matrix      
    */
    for(int i = 0; i < num_of_rows; i++){
        for(int j = 0; j < num_of_cols; j++){
            printf("%d, ", matrix[i][j]);
        }
        printf("\n");
    }
}

// === Main function ===
void multiply_two_matrices(int (*first_matrix)[MAX_SIZE], int (*second_matrix)[MAX_SIZE], 
                        int (*multiplication_matrix)[MAX_SIZE], int rows_of_first_matrix, 
                        int cols_of_first_matrix, int cols_of_second_matrix){
    /*
    For example:
    A = [
        [1, 2, 3],
        [4, 5, 6]
    ]
    B = [
        [7, 8],
        [9, 10],
        [11, 12]
    ]
                           [ 7               
    C[0, 0] = [1, 2, 3] x    8   = 1x7 + 2x9 + 3x11             
                             9 ]

                           [ 8               
    C[0, 1] = [1, 2, 3] x    10   = 1x8 + 2x10 + 3x12             
                             12 ]
    
    ...

    => C = [
            [1x7 + 2x9 + 3x11, 1x8 + 2x10 + 3x12],
            [4x7 + 5x9 + 6x11, 4x8 + 5x11 + 6x12]
           ]
    */
    int sum = 0;
    for(int i = 0; i < rows_of_first_matrix; i++){
        for(int j = 0; j < cols_of_second_matrix; j++){
            sum = 0;
            for(int t = 0; t < cols_of_first_matrix; t++){
                sum += first_matrix[i][t] * second_matrix[t][j];
            }
            multiplication_matrix[i][j] = sum;
        }
    }
}