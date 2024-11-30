#include<stdio.h>

int main(){
    /*
    Write a C program to compute the Factorial of n. Validating the input, in case the input 
        isn't correct, prompt user to enter it again
            n! = 1 * 2 * 3 * ... * n (n >= 0)
    */

    int n, product = 1;

    do{
        printf("Entering the number: ");
        scanf("%d", &n);
        if(n <= 0){
            printf("The number must be greater than 0.\n");
        }
    }
    while(n < 0);

    for(int i = 1; i <= n; i++){
        product *= i;
    }

    printf("%d! = %d", n, product);
    return 0;
}