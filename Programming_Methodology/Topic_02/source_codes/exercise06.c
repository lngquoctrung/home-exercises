#include<stdio.h>

int main(){

    // Write a C program to calculate sum of digits of any number

    int number, digit, sum = 0;

    printf("Entering the number: ");
    scanf("%d", &number);

    while(number > 0){
        digit = number % 10;
        sum += digit;
        number /= 10;
    }

    printf("Sum = %d", sum);

    return 0;
}