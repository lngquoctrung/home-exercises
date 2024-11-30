#include<stdio.h>

void findFirstAndLastDigits(int);

int main(){

    // Write a C function to find first and last digits of any number

    int number;

    printf("Entering the number: ");
    scanf("%d", &number);
    printf("The number is %d\n", number);

    findFirstAndLastDigits(number);

    return 0;
}

void findFirstAndLastDigits(int number){
    int first_digit, last_digit;
    // Get last digit
    last_digit = number % 10;
    
    // Get first digit
    while(number > 0){
        first_digit = number % 10;
        number /= 10;
    }
    printf("The first digit is %d\n", first_digit);
    printf("The last digit is %d", last_digit);
}