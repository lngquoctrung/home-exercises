#include<stdio.h>

int factorial(int n);

int main(){
    /*
    Write a recursive function to calculate the factorial of a non-negative number n. Given the definition of factorial according to the following formula:
         |-  1,           x <= 1
    n! = |
         |-  n . (n - 1), n >= 1
    */
    int n;
    printf("Entering the number: ");
    scanf("%d", &n);

    printf("%d! = %d", n, factorial(n));
    return 0;
}

int factorial(int n){
    if(n == 0 || n == 1) return 1;
    return n * factorial(n - 1);
}