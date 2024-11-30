#include<stdio.h>

int main(){

    // Write a C program to find first and last digits of any number

    int number, first_digit, last_digit;

    printf("Entering the number: ");
    scanf("%d", &number);
    printf("The number is %d\n", number);

    // Get last digit
    last_digit = number % 10;
    
    // Get first digit
    while(number > 0){
        first_digit = number % 10;
        number /= 10;
    }
    printf("The first digit is %d\n", first_digit);
    printf("The last digit is %d", last_digit);

    return 0;
}