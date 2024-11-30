#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_LENGTH 1000

// =====Main Function=====
char** split(char *str, char);

int main(){
    // Input a string represent a full name, split and print the first name and the last name
    // Note: Assume the full name is followed the international name rule.
    // For example: John Peter Wick -> John is first name or cognomen - Wick is last name or surname - Peter is middle name
    // Thus, if the input is Vietnamese name like as "Nguyen Van A" which must change to "A Van Nguyen"
    char full_name[MAX_LENGTH];
    char **splitted_name;

    printf("Enter the full name: ");
    fgets(full_name, MAX_LENGTH, stdin);

    // Remove newline when using 'fgets' function
    if(full_name[strlen(full_name) - 1] == '\n')
        full_name[strlen(full_name) - 1] = '\0';
    
    // Split full name
    splitted_name = split(full_name, ' ');

    // Determine the number of elements of dynamic array
    int size = 0;
    while(splitted_name[size] != NULL) size++;

    if(size > 0) {
        printf("First name: %s\n", splitted_name[0]);
        printf("Last name: %s", splitted_name[size-1]);
    }

    // Release memory of dynamic arrays
    for(int i = 0; splitted_name[i] != NULL; i++)
        free(splitted_name[i]);
    free(splitted_name);

    return 0;
}

// =====Main Function=====
char** split(char *str, char separator){
    int length = strlen(str), 
        num_of_words = 0, 
        word_index = 0, 
        word_start = 0;

    char **word_array;

    // Returns 'null' if string is empty
    if(str[0] == '\0') 
        return NULL;

    // Count the number of delimiters to determine the number of words to split
    // For example: John Peter Wick => 2 spaces => 3 words
    for(int i = 0; i < length; i++)
        if(str[i] == separator)
            num_of_words++;
    num_of_words++;


    word_array = (char**)malloc((num_of_words + 1) * sizeof(char*)); // Add 1 to determine the number of elements of dynamic array
    // Memory allocation failed
    if(word_array == NULL)
        return NULL;

    // Store token into array
    for(int i = 0; i <= length; i++){
        if(str[i] == separator || str[i] == '\0'){
            // Count length of word
            int word_length = (i - word_start) + 1;
            // Allocate memory to store word
            word_array[word_index] = (char*)malloc(word_length * sizeof(char*));

            // Release memory when memory allocation failed
            if(word_array[word_index] == NULL){
                for(int j = 0; j < word_index; j++){
                    free(word_array[word_index]);
                }
                free(word_array);
                return NULL;
            }

            // Store word to array
            /*
            When you pass an array to a function, you are actually passing the address of the first element in the array. 
                So if you pass the address of the n-th element to a function, you can start from the n-th element in the function. 
                The code below helps you check that:
            #include <stdio.h>
            #include<string.h>

            void print_array(int *array){
                for(int i = 0; i < 3; i++){
                    printf("%d\t", array[i]);
                }
            }

            int main(){
                int a[] = {1, 2, 3, 4, 5};
                print_array(&a[0]);
                printf("\n");
                print_array(&a[1]);
                return 0;
            }
            */
            // Copy n-characters from original string
            strncpy(word_array[word_index], &str[word_start], word_length);
            // Make sure that the end of string is 'null'
            word_array[word_index][word_length] = '\0';
            word_index++;
            word_start = i + 1;
        }
    }
    // Assign 'NULL' value for the last element of dynamic array to determine size of array
    word_array[num_of_words] = NULL;
    return word_array;
}