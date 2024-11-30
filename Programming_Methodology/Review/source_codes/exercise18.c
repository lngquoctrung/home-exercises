#include<stdio.h>
#include<stdlib.h>

// Declare constant maximum memory size of array
#define MAX_SIZE_ARRAY 1000

// Declare function
// === Support Functions ===
void init_random_array(int*, int, int, int);
void print_array(int*, int);
int find_value(int*, int, int);
int contain(int*, int, int);
// ==== Main function ====
int count_total_duplicate_elements(int*, int);

int main(){
    // Write a program to count total number of duplicate elements in an array

    // Declare array and array size
    int arr[MAX_SIZE_ARRAY];
    int arr_size, total_duplicate_elements;

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

    // Count duplicate elements
    total_duplicate_elements = count_total_duplicate_elements(arr, arr_size);
    printf("\nThe total number of duplicate elements = %d", total_duplicate_elements);
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

int find_value(int *array, int arr_size, int value){
    /*
    Find value index in array, if value's found then return index of value
    Parameters:
        *array: 1-d array
                Array store unique values
        arr_size: 'int'
                the size of array
        value: 'int'
                The value whether contains in array or not
    */
    for(int i = 0; i < arr_size; i++){
        if(array[i] == value) return i;
    }
    return -1;
}

int contain(int *array, int arr_size, int value){
    /*
    Check the value whether contains in array or not
    Parameters:
        *array: 1-d array
            The array
        arr_size: 'int'
            The size of array
        value: 'int'
            The value use to check
    */
    for(int i = 0; i < arr_size; i++){
        if(array[i] == value) return 1;
    }
    return 0;
}

// === Main function ===
int count_total_duplicate_elements(int *array, int arr_size){
    int total = 0, visited_arr_size = 0;
    int visited[MAX_SIZE_ARRAY];
    for(int i = 0; i < arr_size-1; i++){
        for(int j = i+1; j < arr_size; j++){
            // Check the value is the first duplicate or not
            if(array[i] == array[j] && !contain(visited, visited_arr_size, array[i])){
                visited[visited_arr_size] = array[i];
                visited_arr_size++;
                total++;
            }
        }
    }
    return total;
}