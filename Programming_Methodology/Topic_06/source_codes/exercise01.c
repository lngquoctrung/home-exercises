#include<stdio.h>
#include<math.h>

int check_prime_number(int n, int div);
int is_prime_number(int n);

int main(){
    // Define a recursive function that check whether a number is prime.
    int number;

    // Enter the number
    do{
        printf("Enter the number: ");
        scanf("%d", &number);
    }
    while(number <= 0);

    // Display result
    if(is_prime_number(number))
        printf("The number is prime number");
    else
        printf("The number is not prime number");

    return 0;
}

int check_prime_number(int n, int div){
    // If `n` is divisible by any of the factors of `n` from 2 
    // to the second degree, then it is not a prime number.
    if(n % div == 0 || div == 1)
        return 0;

    // Common divisor variable `div` is equal to 2, which means that
    // `n` is not divisible by any common divisors from 2 to `sqrt` of n
    // => `n` is prime number.
    return div == 2 ? 1 : check_prime_number(n, div - 1);
}

int is_prime_number(int n){
    // 2 always is Prime number
    return n == 2 ? 1 : check_prime_number(n, sqrt(n));
}