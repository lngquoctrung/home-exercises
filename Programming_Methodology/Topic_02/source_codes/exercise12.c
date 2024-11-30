#include<stdio.h>

int main(){

    // Wrie a C program to check whether a number is Prime number or not. Validating the input, \
    in case the input isn't correct, prompt user to enter it again.

    /*
    Prime number is a number that is divisible only by 1 and itself.
    */

    int number, is_prime_number = 1;

    do{
        printf("Entering the number: ");
        scanf("%d", &number);
        if(number <= 0){
            printf("The number must be greater than 0\n");
        }
    }
    while(number <= 0);


    for(int i = 2; i < number; i++){
        if(number % i == 0){
            is_prime_number = 0;
            // Stop loop
            break;
        }
    }

    if(is_prime_number) printf("%d is Prime number", number);
    else printf("%d is not Prime number", number);

    return 0;
}