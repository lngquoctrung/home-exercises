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
int are_equal(int (*first_matrix)[MAX_SIZE], int (*second_matrix)[MAX_SIZE], 
                    int rows_of_first_matrix, int cols_of_first_matrix, 
                    int rows_of_second_matrix, int cols_of_second_matrix);

int main(){
    // Write program to check whether two matrices are equal or not

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

    // Initialize matrix automatically by random function
    int min = 5, max = 10;
    init_random_matrix(first_matrix, rows_of_first_matrix, cols_of_first_matrix, min, max);
    //srand(1); // Keep value each random
    init_random_matrix(second_matrix, rows_of_second_matrix, cols_of_second_matrix, min, max);
    // Check values of matrix by printing
    printf("First matrix: \n");
    print_matrix(first_matrix, rows_of_first_matrix, cols_of_first_matrix);
    printf("Second matrix: \n");
    print_matrix(second_matrix, rows_of_second_matrix, cols_of_second_matrix);

    // Result
    if(are_equal(first_matrix, second_matrix, rows_of_first_matrix, cols_of_first_matrix, rows_of_second_matrix, cols_of_second_matrix)){
        printf("\nFirst matrix and second matrix are equal");
    }
    else{
        printf("\nFirst matrix and second matrix are not equal");
    }
    
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
int are_equal(int (*first_matrix)[MAX_SIZE], int (*second_matrix)[MAX_SIZE], 
                        int rows_of_first_matrix, int cols_of_first_matrix, 
                        int rows_of_second_matrix, int cols_of_second_matrix){
    // The size of two matrices must be same
    if(rows_of_first_matrix != rows_of_second_matrix || cols_of_first_matrix != cols_of_second_matrix)
        return 0;
    
    // Check elements
    for(int i = 0; i < rows_of_first_matrix; i++){
        for(int j = 0; j < cols_of_first_matrix; j++){
            if(first_matrix[i][j] != second_matrix[i][j])
                return 0;
        }
    }
    return 1;
}