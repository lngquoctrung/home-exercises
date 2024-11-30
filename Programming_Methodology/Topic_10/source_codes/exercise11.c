#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// Declare constant maximum memory size of array
#define MAX_SIZE_ARRAY 1000

// Declare function
// === Support Functions ===
void init_random_array(int*, int, int, int);
void print_array(int*, int);
int is_prime_num(int n);
// ==== Main function ====
int sum_prime_nums(int*, int);

int main(){
    // Write a function with two parameters, an array of positive integers and the number of elements n. The function returns the sum of the prime numbers in the array.

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

    // Print sum result all numbers of an integer array
    printf("\nThe result of sum all prime numbers of array = %d", sum_prime_nums(arr, arr_size));
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

int is_prime_num(int n){
    for(int i = 2; i < sqrt(n); i++)
        if(n % i == 0) return 0;
    return 1;
}

// === Main function ===
int sum_prime_nums(int *array, int arr_size){
    int sum = 0;
    for(int i = 0; i < arr_size; i++)
        if(is_prime_num(array[i]))
            sum += array[i];
    return sum;
}