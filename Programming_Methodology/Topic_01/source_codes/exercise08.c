#include<stdio.h>

int main(){
    // Write a C program to find maximum between two numbers.

    int first_number, second_number;

    printf("Entering the first number: ");
    scanf("%d", &first_number);
    printf("Entering the second number: ");
    scanf("%d", &second_number);

    // Ternary operator
    // Syntax: <condition> ? <value if true> : <value if false>;
    int maximum_number = first_number >= second_number ? first_number : second_number;

    printf("The maximum number is %d", maximum_number);

    return 0;
}