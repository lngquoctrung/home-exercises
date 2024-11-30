#include<stdio.h>
#include<stdlib.h>

// Declare constant maximum memory size of array
#define MAX_SIZE_ARRAY 1000

// Declare function
// === Support Functions ===
void init_random_array(int *arr, const int size, const int min, const int max);
void print_array(const int *arr, const int size);
// ==== Main function ====
void selection_sort(int *arr, const int size);

int main(){
    // Implement the selection sort algorithm for sorting a list is descending order

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

    // Sorting array
    selection_sort(arr, arr_size);

    // Sorted array
    printf("\nSorted array: ");
    print_array(arr, arr_size);
    return 0;
}

// Define functions
// === Support function ===
void init_random_array(int *array, const int arr_size, const int min, const int max){
    for(int i = 0; i < arr_size; i++){
        array[i] = rand() % (max - min + 1) + min;
    }
}

void print_array(const int *array, const int arr_size){
    for(int i = 0; i < arr_size; i++){
        printf("%d, ", array[i]);
    }
}

// === Main function ===
void selection_sort(int *arr, const int size){
    int i, start, max_index, temp;
    for(start = 0; start < size - 1; start++){
        // find the index of minimum element
        max_index = start;
        for(i = start + 1; i < size; i++){
            if(arr[i] > arr[max_index]) max_index = i;
        }

        // swap minimum element with element at start index
        temp = arr[start];
        arr[start] = arr[max_index];
        arr[max_index] = temp;
    }
}