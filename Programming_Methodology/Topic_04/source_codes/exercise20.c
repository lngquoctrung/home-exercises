#include<stdio.h>
#include<stdlib.h>

// Declare constant maximum memory size of matrix
#define MAX_SIZE 100

// Declare function
// === Support Functions ===
// void init_random_matrix(int matrix[][MAX_SIZE], int, int, int, int);
void init_random_matrix(int (*matrix)[MAX_SIZE], int num_of_rows, int num_of_cols, int min, int max);
void print_matrix(int (*matrix)[MAX_SIZE], int num_of_rows, int num_of_cols);
void swap(int *a, int *b);
// ==== Main function ====
void transpose(int (*matrix)[MAX_SIZE], int *num_of_rows, int *num_of_cols);

int main(){
    // Write program to find transpose of a matrix

    // Declare matrix and matrix size
    int matrix[MAX_SIZE][MAX_SIZE];
    int num_of_rows, num_of_cols;

    // Enter the matrix size
    printf("Enter the number of rows of the matrix: ");
    scanf("%d", &num_of_rows);
    printf("Enter the number of columns of thematrix: ");
    scanf("%d", &num_of_cols);

    // Check the size of matrix is suitable
    if(num_of_rows > MAX_SIZE || num_of_cols > MAX_SIZE){
        printf("Don't enough memory to allocate, the matrix size must not be greater 1000");
        exit(0);
    }

    // Initialize matrix automatically by random function
    int min = 1, max = 10;
    init_random_matrix(matrix, num_of_rows, num_of_cols, min, max);
    // Check values of matrix by printing
    printf("The matrix: \n");
    print_matrix(matrix, num_of_rows, num_of_cols);

    transpose(matrix, &num_of_rows, &num_of_cols);

    // Result
    printf("Transposed matrix: \n");
    print_matrix(matrix, num_of_rows, num_of_cols);
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

void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

// === Main function ===
void transpose(int (*matrix)[MAX_SIZE], int *num_of_rows, int *num_of_cols){
    for(int i = 0; i < *num_of_rows; i++){
        // Start at 1, if start at 0, when i = 1, Values at a[0, 1] and a[1, 0] swap again
        for(int j = 1; j < *num_of_cols; j++){
            swap(&matrix[i][j], &matrix[j][i]);
        }
    }
    swap(num_of_rows, num_of_cols);
}