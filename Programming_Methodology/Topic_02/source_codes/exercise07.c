#include<stdio.h>

int main(){

    // Write a C program to calculate product of digits of any number.

    int number, digit, product = 1;

    printf("Entering the number: ");
    scanf("%d", &number);

    while(number > 0){
        digit = number % 10;
        product *= digit;
        number /= 10;
    }

    printf("Product = %d", product);

    return 0;
}