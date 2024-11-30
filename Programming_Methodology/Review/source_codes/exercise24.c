#include<stdio.h>
#include<stdlib.h>

// Declare constant maximum memory size of array
#define MAX_SIZE_ARRAY 1000

// Declare function
// === Support Functions ===
void init_random_array(int*, int, int, int);
void print_array(int*, int);
// ==== Main function ====
void sort(int*, int);

int main(){
    // Write program to sort array elements in ascending order

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
    int min = 5, max = 10;
    init_random_array(arr, arr_size, min, max);
    // Check values of array by printing
    printf("Original array: ");
    print_array(arr, arr_size);

    sort(arr, arr_size);

    // Sorted array
    printf("\nSorted array: ");
    print_array(arr, arr_size);
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
void sort(int *array, int arr_size){
    int temp;
    for(int i = 0; i < arr_size - 1; i++){
        for(int j = i + 1; j < arr_size; j++){
            if(array[i] > array[j]){
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}