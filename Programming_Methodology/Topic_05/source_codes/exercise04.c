#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX_LENGTH 1000

// =====Support Function=====
char* strim(char *str);
char* to_lower_case(char *str);
char* to_capitalize_first_letter(char *str);

// =====Main Function=====
char* normalize(char *str);

int main(){
    // Input a string and normalize it (strim the space before, insidem and afterm to lower each token except the first). 
    // For example, with the input "  PrOgRaMmInG   MeThOd  ". the output will be "Programming Method" 23 21 1
    char str[MAX_LENGTH];

    printf("Enter the string: ");
    fgets(str, MAX_LENGTH, stdin);

    // Remove newline when using 'fgets' function
    if(str[strlen(str) - 1] == '\n')
        str[strlen(str) - 1] = '\0';

    // Original string
    printf("Original string: \"%s\"\n", str);

    // Normalize string
    char *normalized_string = normalize(str);
    printf("Normalized string: \"%s\"", normalized_string);
    free(normalized_string);
    return 0;
}

// =====Support Function=====
char* strim(char *str){
    // Remove front and back spaces
    int str_length,
        space_before_index = 0,
        space_after_index = strlen(str) - 1;

    // Determine length of string
    while(str[space_before_index] == ' ')
        space_before_index++;
    while(str[space_after_index] == ' ')
        space_after_index--;
    str_length = (space_after_index - space_before_index) + 1;

    // Copy the string between the front and back spaces
    char *rmved_space_str = (char*)malloc(str_length * sizeof(char*));
    if(rmved_space_str == NULL)
        return NULL;
    strncpy(rmved_space_str, &str[space_before_index], str_length);
    rmved_space_str[str_length] = '\0'; // End of string must be null

    // Remove middle spaces
    for(int i = 0; i < str_length; i++){
        if(rmved_space_str[i] == ' ' && rmved_space_str[i + 1] == ' '){
            for(int j = i; j < str_length; j++)
                rmved_space_str[j] = rmved_space_str[j + 1];
            str_length--;
            i--;
        }
    }

    return rmved_space_str;
}

char* to_lower_case(char* str){
    for(int i = 0; i < strlen(str); i++)
        str[i] = tolower(str[i]);
    return str;
}

char* to_capitalize_first_letter(char* str){
    str[0] = toupper(str[0]); // Capitalize the first letter
    for(int i = 1; i < strlen(str); i++)
        if(str[i] == ' ')
            str[i + 1] = toupper(str[i + 1]); // Capitalize the first letters after the spaces
    return str;
}

// =====Main Function=====
char* normalize(char *str){
    char *normalized_str = strim(str);
    normalized_str = to_lower_case(normalized_str);
    normalized_str = to_capitalize_first_letter(normalized_str);
    return normalized_str;
}