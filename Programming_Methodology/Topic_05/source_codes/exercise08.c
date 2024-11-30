#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_LENGTH 100

// =====Support Function=====
void input(char str[MAX_LENGTH], const char *text);

// =====Main Function=====
int find_word(char *str, const char* word);

int main(){
    // Input a string and check whether a word appears or not. If yes, return the first postion.
    char str[MAX_LENGTH], word[MAX_LENGTH];

    // Enter string and word to find
    input(str, "Enter the string: ");
    input(word, "Enter the word: ");

    // Call function and display result
    int position = find_word(str, word);
    printf("The position of word in string is %d", position);

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
int find_word(char *str, const char* word){
    for(int i = 0; i < strlen(str); i++)
        // Compare n-characters of string with n-characters of word
        if(strncmp(&str[i], word, strlen(word)) == 0)
            return i;
    return -1;
}