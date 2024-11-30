#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_LENGTH 100

// =====Support Function=====
void input(char str[MAX_LENGTH], const char *text);

// =====Main Function=====
void remove_string(char *str, const int n, const int position);

int main(){
    // Input a string and two integer numbers, named `n` and `position`. The delete `n` characters from `position` of input string.
    char str[MAX_LENGTH];
    int n, position;

    // Enter two strings
    input(str, "Enter the string: ");
    printf("Enter the number of characters to remove: ");
    scanf("%d", &n);
    printf("Enter the starting position to remove: ");
    scanf("%d", &position);

    // Call function and display result
    remove_string(str, n, position);
    printf("The string after removed: %s", str);

    return 0;
}

void input(char str[MAX_LENGTH], const char *text){
    // Get input
    printf("%s", text);
    fgets(str, MAX_LENGTH, stdin);

    // Remove newline when using 'fgets' function
    if(str[strlen(str) - 1] == '\n')
        str[strlen(str) - 1] = '\0';
}

// =====Main Function=====
void remove_string(char *str, const int n, const int position){
    /*
    Copies "numBytes" bytes from address "from" to address "to"
    void * memmove(void *to, const void *from, size_t numBytes);
    */
    memmove(&str[position], &str[position + n], strlen(str) - n);
}