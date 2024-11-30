#include<stdio.h>

int productOfDigits(int);

int main(){

    // Write a C function to calculate product of digits of any number.

    int number;

    printf("Entering the number: ");
    scanf("%d", &number);

    printf("Product = %d", productOfDigits(number));

    return 0;
}

int productOfDigits(int number){
    int digit, product = 1;

    while(number > 0){
        digit = number % 10;
        product *= digit;
        number /= 10;
    }
    return product;
}