#include<stdio.h>

int main(){
    // Write a C program to print all Perfect numbers between 1 \
    to n by using three loop structures. Validating the input, in \
    case the input isn't correct, prompt user to enter it again.

    int n, sum_of_proper_divisors;

    do{
        printf("Entering the number: ");
        scanf("%d", &n);
        if(n <= 0){
            printf("The number must be greater than 0.\n");
        }
    }
    while(n <= 0);

    // for loop
    printf("For loop: ");
    // The loop from 1 to n
    for(int i = 1; i <= n; i++){
        sum_of_proper_divisors = 0;
        for(int j = 1; j < i; j++){
            // Checking j is whether proper divisor of number or not.
            if(i % j == 0){
                sum_of_proper_divisors += j;
            }
        }

        if(i == sum_of_proper_divisors) printf("%d, ", i);
    }

    // while loop
    printf("\nWhile loop: ");
    int i = 1;
    while(i <= n){
        sum_of_proper_divisors = 0;
        for(int j = 1; j < i; j++){
            // Checking j is whether proper divisor of number or not.
            if(i % j == 0){
                sum_of_proper_divisors += j;
            }
        }

        if(i == sum_of_proper_divisors) printf("%d, ", i);
        i++;
    }


    // do-while loop
    printf("\nDo-while loop: ");
    i = 1;
    do{
        sum_of_proper_divisors = 0;
        for(int j = 1; j < i; j++){
            // Checking j is whether proper divisor of number or not.
            if(i % j == 0){
                sum_of_proper_divisors += j;
            }
        }

        if(i == sum_of_proper_divisors) printf("%d, ", i);
        i++;
    }
    while(i <= n);
    return 0;
}