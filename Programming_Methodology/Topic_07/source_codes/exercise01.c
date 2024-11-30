#include<stdio.h>
#include<stdlib.h>

// Declare constant maximum memory size of array
#define MAX_SIZE_ARRAY 1000

// Declare function
// === Support Functions ===
void init_random_array(int *arr, const int size, const int min, const int max);
void print_array(const int *arr, const int size);
// ==== Main function ====
int sequential_search(const int *arr, const int size, const int key);

int main(){
    // Implement the sequential search algorithm

    // Declare array and array size
    int arr[MAX_SIZE_ARRAY];
    int arr_size, key;

    // Enter the array size
    printf("Enter the array size: ");
    scanf("%d", &arr_size);
    // Check the size of array is suitable
    if(arr_size > MAX_SIZE_ARRAY){
        printf("Don't enough memory to allocate, the array size must not be greater 1000");
        exit(0);
    }

    // Initialize array automatically by random function
    int min = 5, max = 30;
    init_random_array(arr, arr_size, min, max);
    // Check values of array by printing
    printf("Arr: ");
    print_array(arr, arr_size);

    printf("\nEnter the value to find: ");
    scanf("%d", &key);

    // Find position of number in array by sequential search
    printf("The position of %d in array is %d", key, sequential_search(arr, arr_size, key));
    return 0;
}

// Define functions
// === Support function ===
void init_random_array(int *array, const int arr_size, const int min, const int max){
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

void print_array(const int *array, const int arr_size){
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
int sequential_search(const int* arr, const int size, const int key){
    for(int i = 0; i < size; i++){
        if(arr[i] == key) return i;
    }
    return -1; // in case not found
}