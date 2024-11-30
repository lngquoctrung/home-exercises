#include<stdio.h>
#include<string.h>
#define MAX_LENGTH 1000

int is_palindrome(char *str);

int main(){
    // Write a function that takes a string as a parameter and checks if the string is a palindrome. If so, return 1, otherwise return 0.
    char str[MAX_LENGTH];
    printf("Enter the string: ");
    fgets(str, MAX_LENGTH, stdin);
    // Removing newline at the end of string
    str[strcspn(str, "\n")] = 0;
    is_palindrome(str) ? printf("Yes") : printf("No");
    
    return 0;
}

int is_palindrome(char *str){
    for(int i = 0; i < strlen(str) / 2; i++)
        if(str[strlen(str) - i - 1] != str[i])
            return 0;
    return 1;
}
