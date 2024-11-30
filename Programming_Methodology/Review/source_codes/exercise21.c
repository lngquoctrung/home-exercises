#include<stdio.h>
#include<stdlib.h>

// Declare constant maximum memory size of array
#define MAX_SIZE_ARRAY 1000

// Declare function
// === Support Functions ===
void init_random_array(int*, int, int, int);
void print_array(int*, int);
// ==== Main function ====
void merge_two_arrays(int*, int*, int*, int, int, int);

int main(){
    // Write program to merge two array to third array

    // Declare array and array size
    int first_arr[MAX_SIZE_ARRAY], 
        second_arr[MAX_SIZE_ARRAY],
        merged_arr[MAX_SIZE_ARRAY];
    int first_arr_size,
        second_arr_size,
        merged_arr_size;

    // Enter the array size
    printf("Enter the first array size: ");
    scanf("%d", &first_arr_size);
    printf("Enter the second array size: ");
    scanf("%d", &second_arr_size);
    merged_arr_size = first_arr_size + second_arr_size;
    // Check the size of each array is suitable
    if(first_arr_size > MAX_SIZE_ARRAY || second_arr_size > MAX_SIZE_ARRAY || merged_arr_size > MAX_SIZE_ARRAY){
        printf("Don't enough memory to allocate, the array size must not be greater 1000");
        exit(0);
    }
    
    // Initialize array automatically by random function
    int min = 5, max = 10;
    // First array
    init_random_array(first_arr, first_arr_size, min, max);
    // Second aray
    init_random_array(second_arr, second_arr_size, min, max);
    // Check values of array by printing
    printf("First array: ");
    print_array(first_arr, first_arr_size);
    printf("\nSecond array: ");
    print_array(second_arr, second_arr_size);

    // Count duplicate elements
    merge_two_arrays(first_arr, second_arr, merged_arr, first_arr_size, second_arr_size, merged_arr_size);

    // Result
    printf("\nMerge array: ");
    print_array(merged_arr, merged_arr_size);
    return 0;
}

// Define functions
// === Support function ===
void init_random_array(int *array, int arr_size, int min, int max){
    /*
    Initialize random values ​​for array of given size in the range from min to max
    Parameters:
        array: 1-d array with 'int' data type
                the array use to store random values
        arr_size: 'int'
                the size of array
        min: 'int'
                the minimum value in the range you want to random
        max: 'int'
                the maximum value in the range you want to random
    */
    for(int i = 0; i < arr_size; i++){
        array[i] = rand() % (max - min + 1) + min;
    }
}

void print_array(int *array, int arr_size){
    /*
    Print values of array
    Parameters:
        array: 1-d array with 'int' data type
                The array is printed
        arr_size: 'int'
                the size of array      
    */
    for(int i = 0; i < arr_size; i++){
        printf("%d, ", array[i]);
    }
}

// === Main function ===
void merge_two_arrays(int *first_array, int *second_array, int *third_array, 
                        int first_arr_size, int second_arr_size, int third_arr_size){
    for(int i = 0; i < first_arr_size; i++){
        third_array[i] = first_array[i];
    }
    for (int i = 0; i < second_arr_size; i++){
        third_array[i + first_arr_size] = second_array[i];
    }
    
}