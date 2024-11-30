#include<stdio.h>
#include<stdlib.h>

// Declare constant maximum memory size of array
#define MAX_SIZE_ARRAY 1000

// Declare function
// === Support Functions ===
void init_random_array(int*, int, int, int);
void print_array(int*, int);
// ==== Main function ====
int sum_even_nums(int*, int);

int main(){
    // Write function to sum all even numbers of an integer array

    // Declare array and array size
    int arr[MAX_SIZE_ARRAY];
    int arr_size;

    // Enter the array size
    printf("Enter the array size: ");
    scanf("%d", &arr_size);
    // Check the size of array is suitable
    if(arr_size > MAX_SIZE_ARRAY){
        printf("Don't enough memory to allocate, the array size must not be greater 1000");
        exit(0);
    }
    
    // Initialize array automatically by random function
    int min = 1, max = 20;
    init_random_array(arr, arr_size, min, max);
    // Check values of array by printing
    printf("Arr: ");
    print_array(arr, arr_size);

    // Print sum result all even numbers of an integer array
    printf("\nThe result of sum all even numbers of array = %d", sum_even_nums(arr, arr_size));
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
int sum_even_nums(int *array, int arr_size){
    int even_sum = 0;
    for(int i = 0; i < arr_size; i++){
        if(array[i]%2 == 0){
            even_sum += array[i];
        }
    }
    return even_sum;
}