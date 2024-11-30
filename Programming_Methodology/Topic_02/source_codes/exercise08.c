#include<stdio.h>

int main(){

    // Write a C program to count number of digits of any number.

    int number, digit, count = 0;

    printf("Entering the number: ");
    scanf("%d", &number);

    while(number > 0){
        digit = number % 10;
        count += 1;
        number /= 10;
    }

    printf("The number of digits = %d", count);

    return 0;
}