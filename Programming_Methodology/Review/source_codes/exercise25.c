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
void add_two_matrices(int (*first_matrix)[MAX_SIZE], int (*second_matrix)[MAX_SIZE], 
                        int (*addition_matrix)[MAX_SIZE], int num_of_rows, int num_of_cols);

int main(){
    // Write program to add two matrices
    // Note: The number of rows and columns of two matrices must be same.

    // Declare matrix and matrix size
    int first_matrix[MAX_SIZE][MAX_SIZE],
        second_matrix[MAX_SIZE][MAX_SIZE],
        addition_matrix[MAX_SIZE][MAX_SIZE];
    int num_of_rows, num_of_cols;

    // Enter the matrix size
    printf("Enter the number of rows of matrix: ");
    scanf("%d", &num_of_rows);
    printf("Enter the number of columns of matrix: ");
    scanf("%d", &num_of_cols);
    // Check the size of matrix is suitable
    if(num_of_rows > MAX_SIZE || num_of_cols > MAX_SIZE){
        printf("Don't enough memory to allocate, the matrix size must not be greater 1000");
        exit(0);
    }
    
    // Initialize matrix automatically by random function
    int min = 5, max = 10;
    init_random_matrix(first_matrix, num_of_rows, num_of_cols, min, max);
    init_random_matrix(second_matrix, num_of_rows, num_of_cols, min, max);
    // Check values of matrix by printing
    printf("First matrix: \n");
    print_matrix(first_matrix, num_of_rows, num_of_cols);
    printf("Second matrix: \n");
    print_matrix(second_matrix, num_of_rows, num_of_cols);

    add_two_matrices(first_matrix, second_matrix, addition_matrix, num_of_rows, num_of_cols);

    // Result
    printf("\nAddition matrix: \n");
    print_matrix(addition_matrix, num_of_rows, num_of_cols);
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
void add_two_matrices(int (*first_matrix)[MAX_SIZE], int (*second_matrix)[MAX_SIZE], 
                        int (*addition_matrix)[MAX_SIZE], int num_of_rows, int num_of_cols){
    for(int i = 0; i < num_of_rows; i++){
        for(int j = 0; j < num_of_cols; j++){
            addition_matrix[i][j] = first_matrix[i][j] + second_matrix[i][j];
        }
    }
}