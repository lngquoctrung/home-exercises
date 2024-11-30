#include<stdio.h>
#include<stdlib.h>

// Declare constant maximum memory size of array
#define MAX_SIZE_ARRAY 1000

// Declare function
// === Support Functions ===
void init_random_array(int*, int, int, int);
void print_array(int*, int);
int find_value(int*, int, int);
// ==== Main function ====
void count_duplicate_elements(int*, int);

int main(){
    // Write program to count frequency of each element in an array

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

    // Count duplicate elements
    count_duplicate_elements(arr, arr_size);
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

// === Main function ===
void count_duplicate_elements(int *array, int arr_size){
    // First row of matrix use to store unique values
    int counter[2][MAX_SIZE_ARRAY];
    int num_of_unique_values = 0, found_index;
    for(int i = 0; i < arr_size; i++){
        found_index = find_value(counter[0], num_of_unique_values, array[i]);
        // Value first appears
        if(found_index == -1){
            counter[0][num_of_unique_values] = array[i];
            counter[1][num_of_unique_values] = 1;
            num_of_unique_values++;
        }
        // Value has appeared
        else counter[1][found_index] += 1;
    }
    // Print result
    printf("\n%-*s", 15, "| Value");
    printf("%-*s", 15, "| Count");
    printf("|\n");
    for(int i = 0; i <= 30; i++){
        printf("-");
    }
    for(int i = 0; i < num_of_unique_values; i++){
        printf("\n| %-*d", 13, counter[0][i]);
        printf("| %-*d", 13, counter[1][i]);
        printf("|");
    }
}