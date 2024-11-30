#include<stdio.h>

int isPerfectNumber(int);

int main(){

    // Write a C function to check whether a number is Perfect number or not.

    int number;

    printf("Entering the number: ");
    scanf("%d", &number);

    /*
    A perfect number is a positive integer that is equal to the sum of its positive proper divisors, that is, divisors excluding the number itself.

    6 is perfect number, because 6 have 4 proper divisors is 1, 2, 3 and 6. The sum of proper divisors of 6 is equal 6.
    */

    if(isPerfectNumber(number)) printf("%d is Perfect number", number);
    else printf("%d is not Perfect number", number);

    return 0;
}

int isPerfectNumber(int number){
    int sum_of_proper_divisors = 0;
    // Finding and adding proper divisors of the number
    for(int i = 1; i < number; i++){
        // Checking i is whether proper divisor of number or not.
        if(number % i == 0){
            sum_of_proper_divisors += i;
        }
    }
    if(number != sum_of_proper_divisors) return 0;
    return 1;
}