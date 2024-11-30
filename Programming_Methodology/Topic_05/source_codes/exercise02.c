#include<stdio.h>
#include<stdlib.h>
#define MAX_LENGTH 1000

// =====Support Function=====
int get_length(const char *str);
// =====Main Function=====
char* reverse_string(char *str);

int main(){
    // Input a string and print it in reverse order
    char str[MAX_LENGTH];
    printf("Enter the string: ");
    fgets(str, MAX_LENGTH, stdin);
    // Remove new line at the end of the string when using 'fgets' function
    if(str[get_length(str) - 1] == '\n')
        str[get_length(str) - 1] = '\0';
    
    char *reversed_str = reverse_string(str);
    printf("Reversed string: %s", reversed_str);
    free(reversed_str);
    return 0;
}

// =====Support Function=====
int get_length(const char *str){
    if(str[0] == '\0') return 0;
    int length = 0;
    while(str[length] != '\0'){
        length += 1;
    }
    return length;
}

// =====Main Function=====
char* reverse_string(char *str){
    int length = get_length(str);
    char *reversed_string = (char*)malloc(length * sizeof(char));
    for(int i = 0; i < length; i++){
        reversed_string[i] = str[(length - 1) - i];
    }
    // Make sure that the end character of reversed string is null
    reversed_string[length] = '\0';
    return reversed_string;
}