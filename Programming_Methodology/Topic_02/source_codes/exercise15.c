#include<stdio.h>

int main(){

    // Write a C program to print all Prime numbers between 1 \
    to n by using three loop structures. Validating the input, \
    in case the input isn't correct, prompt user to enter it \
    again.

    /*
    We use a parent loop to print all number from 1 to n and \
    child loop to check the number is whether is Prime number \
    or not.
    */

    int number;

    do{
        printf("Entering the number: ");
        scanf("%d", &number);
        if(number <= 0){
            printf("The number must be greater than 0.\n");
        }
    }
    while(number <= 0);

    int is_prime_number;

    // for loop
    printf("For loop: ");
    // Parent loop to print all number from 1 to n
    for(int i = 1; i <= number; i++){
        is_prime_number = 1;
        // Child loop check the number is whether Prime number or not
        for(int j = 2; j < i; j++){
            if(i % j == 0){
                is_prime_number = 0;
                break;
            }
        }
        if(is_prime_number){
            printf("%d, ", i);
        }
    }

    // while loop
    printf("\nWhile loop: ");
    int i = 1;
    while(i <= number){
        is_prime_number = 1;
        for(int j = 2; j < i; j++){
            if(i % j == 0){
                is_prime_number = 0;
                break;
            }
        }
        if(is_prime_number){
            printf("%d, ", i);
        }
        i++;
    }

    // Do-while loop
    printf("\nDo-while loop: ");
    i = 1;
    do{
        is_prime_number = 1;
        for(int j = 2; j < i; j++){
            if(i % j == 0){
                is_prime_number = 0;
                break;
            }
        }
        if(is_prime_number){
            printf("%d, ", i);
        }
        i++;
    }
    while(i <= number);
    return 0;
}