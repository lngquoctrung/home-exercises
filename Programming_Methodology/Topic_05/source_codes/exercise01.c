#include<stdio.h>
#include<string.h>
#define MAX_LENGTH 1000

int get_length(const char* str);

int main(){
    // Input a string and return the string's length
    char str[MAX_LENGTH];

    printf("Enter the string: ");
    fgets(str, MAX_LENGTH, stdin);
    // Remove 

    // Get length of string
    printf("The string is: %s", str);

    // ====Without library====
    printf("The length of string by 'get_length' function is %d\n", get_length(str));

    // ====Using library====
    printf("The length of string by 'strlen' function is %d", strlen(str) - 1); // exclude new line character

    return 0;
}

int get_length(const char* str){
    if(str[0] == '\0') return 0;

    int length = 0;
    while(str[length] != '\0'){
        length = length + 1;
    }
    return length - 1; // exclude new line character
}