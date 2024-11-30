#include<stdio.h>

int function(int n);

int main(){
    /*
    Write a recursive function to calculate the factorial of a non-negative number n. Given the definition of factorial according to the following formula:
           |-  3,                     x = 0
    f(x) = |-  5,                     x = 1
           |-  f(x - 1) + 2.f(x - 2), x >= 1
    */
    int x;
    printf("Entering the number: ");
    scanf("%d", &x);

    printf("f(%d) = %d", x, function(x));
    return 0;
}

int function(int x){
    if(x == 0) return 3;
    if(x == 1) return 5;
    return function(x - 1) + 2 * function(x - 2);
}