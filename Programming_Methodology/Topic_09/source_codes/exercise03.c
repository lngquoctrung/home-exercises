#include<stdio.h>
#include<string.h>
#define MAX_LENGTH 1000
#define MAX_SIZE_ARRAY 1000

int linear_search(const int *arr, const int size, const int key);
int sentinel_search(const int *arr, const int size, const int key);

void display_menu();
void print_array(const int*, const int);

int main(){
    /*
    Write a program to illustrate a search program, the program's scenario is as follows:
        - Print to the console: "enter a filename:".
        - Read a string from the console for the filename (Notes: Storing input file in `input_data` folder).
        - Print a menu of the algorithms you implemented, having each represented by a letter or number.
        - Print to the console: "choose one of these search algorithms:".
        - Read a letter or number indicating the algorithm.
        - Print to the console: "enter a value to search for:".
        - Read an integer from the console as your target value, then print the position or print "not found".
    */
    char input_path[MAX_LENGTH] = "../input_data/", 
         file_name[MAX_LENGTH],
         buffer[MAX_LENGTH],  
         *token;
    int option, key, size = 0, arr[MAX_SIZE_ARRAY];
    FILE *open_file;
    
    // Enter the file name from console
    printf("Enter a filename: ");
    fgets(file_name, MAX_LENGTH, stdin);
    file_name[strcspn(file_name, "\n")] = 0; // Removing newline of `fgets` function
    strcat(input_path, file_name); // Getting file name path

    // Reading the array from file
    open_file = fopen(input_path, "r");
    fgets(buffer, MAX_LENGTH, open_file);
    token = strtok(buffer, ", ");
    while(token != NULL){
        sscanf(token, "%d", &arr[size++]);
        token = strtok(NULL, ", ");
    }

    // Displaying algorithm menu
    display_menu();
    // Choose a search algorithm
    scanf("%d", &option);

    // Display array
    print_array(arr, size);

    // Entering the key want to search
    printf("\nEnter a value to search for: ");
    scanf("%d", &key);

    // Choosing algorithm
    switch (option){
        case 1: // Linear Search
            if(linear_search(arr, size, key) != -1)
                printf("The position of %d in array is %d", key, linear_search(arr, size, key));
            else
                printf("Not found.");
            break;
        case 2:
            if(sentinel_search(arr, size, key) != -1)
                printf("The position of %d in array is %d", key, sentinel_search(arr, size, key));
            else
                printf("Not found.");
            break;
    }

    // Closing file
    fclose(open_file);
    return 0;
}

void display_menu(){
    printf("Search Algorithms:\n");
    for(int i = 0; i < 15; i++) printf("-");
    printf("\n");
    printf("\t1. Linear Search\n");
    printf("\t2. Sentinal Search\n");
    printf("Choose one of these search algorithms: ");
}

void print_array(const int *array, const int arr_size){
    for(int i = 0; i < arr_size; i++){
        printf("%d, ", array[i]);
    }
}

int linear_search(const int *arr, const int size, const int key){
    for(int i = 0; i < size; i++){
        if(arr[i] == key) return i;
    }
    return -1; // in case not found
}

int sentinel_search(const int *arr, const int size, const int key){
    // Performing on copy array
    int cp_arr[size];
    for(int i = 0; i < size; i++) cp_arr[i] = arr[i];

    // Last element of the array
    int last = cp_arr[size - 1];
 
    // Element to be searched is
    // placed at the last index
    cp_arr[size - 1] = key;
    int i = 0;
 
    while (cp_arr[i] != key)
        i++;
 
    // Put the last element back
    cp_arr[size - 1] = last;
 
    if ((i < size - 1) || (cp_arr[size - 1] == key))
        return i;
    return -1;
}