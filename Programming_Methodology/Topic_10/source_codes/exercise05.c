#include<stdio.h>
#include<string.h>
#define MAX_LENGTH 1000

int dec_to_bin(int n);

int main(){
    // Write a function that takes a string as a parameter and checks if the string is a palindrome. If so, return 1, otherwise return 0.
    int decimal_number;
    printf("Enter the decimal number: ");
    scanf("%d", &decimal_number);
    printf("%d", dec_to_bin(decimal_number));
    return 0;
}

int dec_to_bin(int decimal_number){
    if (decimal_number == 0) 
        return 0; 
    else
        return (decimal_number % 2 + 10 * 
                dec_to_bin(decimal_number / 2));
}
