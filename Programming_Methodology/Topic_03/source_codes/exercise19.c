#include<stdio.h>

int factorialOfNumber(int);

int main(){
    /*
    Write a C program to compute the Factorial of n. Validating the input, in case the input 
        isn't correct, prompt user to enter it again
            n! = 1 * 2 * 3 * ... * n (n >= 0)
    */

    int n;

    do{
        printf("Entering the number: ");
        scanf("%d", &n);
        if(n <= 0){
            printf("The number must be greater than 0.\n");
        }
    }
    while(n < 0);

    printf("%d! = %d", n, factorialOfNumber(n));
    return 0;
}

int factorialOfNumber(int number){
    int product = 1;
    for(int i = 1; i <= number; i++){
        product *= i;
    }
    return product;
}