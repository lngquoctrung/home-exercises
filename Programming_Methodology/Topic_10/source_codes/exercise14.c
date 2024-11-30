#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// Declare constant maximum memory size of array
#define MAX_SIZE_ARRAY 1000

// Declare function
// === Support Functions ===
void init_random_array(int*, int, int, int);
void print_array(int*, int);
// ==== Main function ====
int countDuplicate(int a[], int n, int k);

int main(){
    // Write a function with the following declaration int countDuplicate(int a[], int n, int k). The source code implementation is required to count and return the number of occurrences of the value k in the array a[].

    // Declare array and array size
    int arr[MAX_SIZE_ARRAY];
    int arr_size, k;

    // Enter the array size
    printf("Enter the array size: ");
    scanf("%d", &arr_size);
    // Check the size of array is suitable
    if(arr_size > MAX_SIZE_ARRAY){
        printf("Don't enough memory to allocate, the array size must not be greater 1000");
        exit(0);
    }

    printf("Enter the value to count: ");
    scanf("%d", &k);
    
    // Initialize array automatically by random function
    int min = 5, max = 30;
    init_random_array(arr, arr_size, min, max);
    // Check values of array by printing
    printf("Arr: ");
    print_array(arr, arr_size);

    // Print sum result all numbers of an integer array
    printf("\nRhe number of occurrences of the value %d in the array a[] = %d", k, countDuplicate(arr, arr_size, k));
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
int countDuplicate(int a[], int n, int k){
    int count = 0;
    for(int i = 0; i < n; i++)
        if(a[i] == k)
            count++;
    return count;
}