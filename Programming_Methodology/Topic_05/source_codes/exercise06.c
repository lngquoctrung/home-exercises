#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_LENGTH 100

// =====Support Function=====
void input(char str[MAX_LENGTH], const char *text);

// =====Main Function=====
int find(char *str, const char character);

int main(){
    // Input a string and check whether a character appear or not. If yes, return the first position.
    char str[MAX_LENGTH], character;

    // Enter string and character
    input(str, "Enter the string: ");

    printf("Enter the charater: ");
    scanf("%c", &character);

    // Display result
    printf("The position of character in string is %d", find(str, character));

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
int find(char *str, const char character){
    for(int i = 0; i < strlen(str); i++)
        if(str[i] == character)
            return i;
    return -1; // Not found case
}