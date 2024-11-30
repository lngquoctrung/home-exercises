#include<stdio.h>
#include<stdlib.h>

// Declare constant maximum memory size of array
#define MAX_SIZE_ARRAY 1000

// Declare function
// === Support Functions ===
void init_random_array(int*, int, int, int);
void print_array(int*, int);
// ==== Main function ====
int find_min_value(int*, int);

int main(){
    // Write a function to find the smallest number in an integer array.

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
    int min = 5, max = 30;
    init_random_array(arr, arr_size, min, max);
    // Check values of array by printing
    printf("Arr: ");
    print_array(arr, arr_size);

    // Find minimum number of integer array
    printf("\nThe minimum number of array is %d", find_min_value(arr, arr_size));
    return 0;
}

// Define functions
// === Support function ===
void init_random_array(int *array, int arr_size, int min, int max){
    
    for(int i = 0; i < arr_size; i++){
        array[i] = rand() % (max - min + 1) + min;
    }
}

void print_array(int *array, int arr_size){
    for(int i = 0; i < arr_size; i++){
        printf("%d, ", array[i]);
    }
}

// === Main function ===
int find_min_value(int *array, int arr_size){
    int min = array[0];
    for(int i = 0; i < arr_size; i++){
        if(array[i] < min){
            min = array[i];
        }
    }
    return min;
}