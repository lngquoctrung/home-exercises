#include<stdio.h>

int isPrimeNumber(int);

int main(){
    // Write a C function to check whether a number is Prime number or not. Validating the input, \
    in case the input isn't correct, prompt user to enter it again

    int number;

    do{
        printf("Entering the number: ");
        scanf("%d", &number);
        if(number <= 0){
            printf("The number must be greater than 0\n");
        }
    }
    while(number <= 0);
    if(isPrimeNumber(number)) printf("%d is Prime number", number);
    else printf("%d is not Prime number", number);
    return 0;
}

int isPrimeNumber(int number){
    for(int i = 2; i < number; i++){
        if(number % i == 0){
            return 0;
        }
    }
    return 1;
}