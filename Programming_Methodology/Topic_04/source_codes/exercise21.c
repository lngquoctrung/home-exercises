#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// Declare constant maximum memory size of matrix
#define MAX_SIZE 100

// Declare function
// === Support Functions ===
// void init_random_matrix(int matrix[][MAX_SIZE], int, int, int, int);
void init_random_matrix(int (*matrix)[MAX_SIZE], int num_of_rows, int num_of_cols, int min, int max);
void print_matrix(int (*matrix)[MAX_SIZE], int num_of_rows, int num_of_cols);
// ==== Main function ====
float determinant(int (*matrix)[MAX_SIZE], int num_of_rows, int num_of_cols);

int main(){
    // Write program to find determinant of a matrix

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

    if(num_of_rows != num_of_cols){
        printf("The number of rows and columns must be same");
        exit(0);
    }

    // Initialize matrix automatically by random function
    int min = -10, max = 10;
    init_random_matrix(matrix, num_of_rows, num_of_cols, min, max);
    // Check values of matrix by printing
    printf("The matrix: \n");
    print_matrix(matrix, num_of_rows, num_of_cols);

    // Result
    printf("Determinant matrix = %.3f", determinant(matrix, num_of_rows, num_of_cols));
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
float determinant(int (*matrix)[MAX_SIZE], int num_of_rows, int num_of_cols){
    // Using Gauss algorithm find determinant of matrix
    /*
        The main idea of Gaussian Elinimation algorithm is changing matrix 
            to triangle matrix and multiply diagonal elements of triangle 
            matrix to find determinant of matrix
         
            1 2 3 4
        A = 0 4 5 6
            0 0 7 8
            0 0 0 9

        => det(A) = 1 * 4 * 7 * 9 = 252        
    */
    float det = 1.;                            // Product use to multiply with diagonal elements
    float copied_matrix[MAX_SIZE][MAX_SIZE];  // Create copy of original matrix to perform

    // Copy matrix
    for(int i = 0; i < num_of_rows; i++){
        for(int j = 0; j < num_of_cols; j++){
            copied_matrix[i][j] = (float)matrix[i][j];
        }
    }

    // Perform Gaussian Elimination algorithm
    for(int i = 0; i < num_of_cols; i++){
        // Find index of nonzero and largest element on main diagonal
        int max_row = i; // Assume that first element of first row is largest on main diagonal
        for(int j = i + 1; j < num_of_rows; j++)
            if(fabs(copied_matrix[j][i]) > fabs(copied_matrix[max_row][i]))
                max_row = j;
        // Swap current row with largest row
        if(max_row != i){
            float temp;
            for(int j = 0; j < num_of_cols; j++){
                temp = copied_matrix[i][j];
                copied_matrix[i][j] = copied_matrix[max_row][j];
                copied_matrix[max_row][j] = temp;
            }
            det *= -1.; // After row swap must change sign of determinant
        }

        // If any element on the main diagonal is 0, return 0
        if(copied_matrix[i][i] == 0)
            return 0;

        // Eliminate below elements on diagonal elements
        for(int j = i + 1; j < num_of_rows; j++){
            float ratio = copied_matrix[j][i] / copied_matrix[i][i];
            for(int k = i; k < num_of_cols; k++){
                copied_matrix[j][k] -= ratio * copied_matrix[i][k];
            }
        }
        // Multiply elements on main diagonal
        det *= copied_matrix[i][i];
    }
    return det;
}