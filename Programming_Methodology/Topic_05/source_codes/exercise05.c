#include<stdio.h>
#include<stdlib.h>
#define MAX_LENGTH 100

// =====Support Function=====
void input(char str[MAX_LENGTH], const char *text);
int get_length(const char *str);

// =====Main Function=====
void concatenate(char *str_1, const char *str_2);

int main(){
    // Input two string s1 and s2, concatenating s2 to s1. (Note: don't use string.h library)
    char str_1[MAX_LENGTH], 
         str_2[MAX_LENGTH];

    input(str_1, "Enter the first string: ");
    input(str_2, "Enter the second string: ");

    printf("String 1: \"%s\"\n", str_1);
    printf("String 2: \"%s\"\n", str_2);

    // Call function
    concatenate(str_1, str_2);

    printf("String 1 after concatenated: \"%s\"\n", str_1);
    printf("Length of string 1: %d", get_length(str_1));

    return 0;
}

// =====Support Function=====
int get_length(const char *str){
    int length = 0;
    while(str[length] != '\0')
        length++;
    return length;
}

void input(char str[MAX_LENGTH], const char *text){
    // Get input
    printf("%s", text);
    fgets(str, MAX_LENGTH, stdin);

    // Remove newline when using 'fgets' function
    if(str[get_length(str) - 1] == '\n')
        str[get_length(str) - 1] = '\0';
}

// =====Main Function=====
void concatenate(char *str_1, const char *str_2){
    // Check the length of two strings do not exceeding maximum length
    if(get_length(str_1) + get_length(str_2) > MAX_LENGTH){
        printf("Do not enough memory to concatetenate.");
        exit(1);
    }
    int str_1_length = get_length(str_1),
        length = get_length(str_1) + get_length(str_2) + 1; // Addition 1 is `space` character between two strings.
    str_1[str_1_length] = ' ';
    for(int i = 0; i < get_length(str_2); i++){
        str_1[str_1_length + i + 1] = str_2[i];
    }
    str_1[length] = '\0'; // Make sure the end of string is `null`
}