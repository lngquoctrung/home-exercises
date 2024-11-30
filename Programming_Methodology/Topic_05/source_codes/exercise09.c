#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_LENGTH 100

// =====Support Function=====
void input(char str[MAX_LENGTH], const char *text);

// =====Main Function=====
int find_string(const *str_1, const char* str_2);

int main(){
    // Input a string and check whether a word appears or not. If yes, return the first postion.
    char str_1[MAX_LENGTH], 
         str_2[MAX_LENGTH];

    // Enter two strings
    input(str_1, "Enter the first string: ");
    input(str_2, "Enter the second string: ");

    // Call function and display result
    int position = find_string(str_1, str_2);
    printf("The position of string 2 in string 1 is %d", position);

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
int find_string(const *str_1, const char* str_2){
    for(int i = 0; i < strlen(str_1); i++)
        // Compare n-characters of string with n-characters of word
        if(strncmp(&str_1[i], str_2, strlen(str_2)) == 0)
            return i;
    return -1;
}