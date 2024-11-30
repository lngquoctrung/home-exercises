#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_LENGTH 100

// =====Support Function=====
void input(char str[MAX_LENGTH], const char *text);

// =====Main Function=====
void insert_string(char *str_1, const char *str_2, const int position);

int main(){
    // Input two strings s1, s2 and position. The insert s2 to s1 from this position.
    char str_1[MAX_LENGTH], 
         str_2[MAX_LENGTH];
    int position;

    // Enter two strings
    input(str_1, "Enter the first string: ");
    input(str_2, "Enter the second string: ");
    printf("Enter the position: ");
    scanf("%d", &position);

    // Call function and display result
    insert_string(str_1, str_2, position);
    printf("The string 1 after inserted: %s", str_1);

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
void insert_string(char *str_1, const char *str_2, const int position){
    char temp[MAX_LENGTH];
    // Store all back characters of the position want to insert
    strncpy(temp, &str_1[position], strlen(&str_1[position]));
    // Replace by str_2
    strncpy(&str_1[position], str_2, strlen(str_2));
    // Assign all back characters to after str_2
    strncpy(&str_1[strlen(str_2) + position], temp, strlen(temp));
}