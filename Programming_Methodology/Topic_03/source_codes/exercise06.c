#include<stdio.h>

int sumOfDigits(int);

int main(){

    // Write a C function to calculate sum of digits of any number

    int number;

    printf("Entering the number: ");
    scanf("%d", &number);


    printf("Sum = %d", sumOfDigits(number));

    return 0;
}

int sumOfDigits(int number){
    int digit, sum = 0;
    while(number > 0){
        digit = number % 10;
        sum += digit;
        number /= 10;
    }
    return sum;
}