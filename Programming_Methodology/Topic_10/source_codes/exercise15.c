#include<stdio.h>
#include<stdlib.h>

// Declare constant maximum memory size of array
#define MAX_SIZE_ARRAY 1000

// Declare function
// === Support Functions ===
void init_random_array(int *arr, const int size, const int min, const int max);
void print_array(const int *arr, const int size);
// ==== Main function ====
int search(int a[], int n, int k);

int main(){
    // Write a function to search for a value k in an array of integers, declaring the function as follows: int search(int a[], int n, int k). The result returned is the position of the value k in the array.

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
    printf("The position of %d in array is %d", key, search(arr, arr_size, key));
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
int search(int a[], int n, int k){
    for(int i = 0; i < n; i++){
        if(a[i] == k) return i;
    }
    return -1; // in case not found
}