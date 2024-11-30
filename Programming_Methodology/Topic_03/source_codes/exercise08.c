#include<stdio.h>

int countNumberOfDigits(int);

int main(){

    // Write a C function to count number of digits of any number.

    int number;

    printf("Entering the number: ");
    scanf("%d", &number);

    printf("The number of digits = %d", countNumberOfDigits(number));

    return 0;
}

int countNumberOfDigits(int number){
    int digit, count = 0;

    while(number > 0){
        digit = number % 10;
        count += 1;
        number /= 10;
    }
    return count;
}