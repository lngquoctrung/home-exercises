#include<stdio.h>

int main(){
    // Write a C program to input a character and check whether it is alphanumeric or not.
    char character;

    // Hint: We use ASCII table (American Standard Code for Information \
    Interchange) to check whether input character is alphanumeric or not.

    printf("Entering the character: ");
    scanf("%c", &character);

    // Numeric condition, 0 - 9
    if(character >= 48 && character <= 57){
        printf("The character %c is numeric", character);
    }
    // Uppercase alphabetic condition, A - Z
    else if(character >= 65 && character <= 90){
        printf("The character %c is uppercase alphabetic", character);
    }
    // Lowercase alphabetic condition, a - z
    else if(character >= 97 && character <= 122){
        printf("The character %c is lowercase alphabetic", character);
    }
    else{
        printf("The character %c is not alphanumeric", character);
    }
    return 0;
}