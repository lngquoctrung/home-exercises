#include<stdio.h>

int function(int n);

int main(){
    /*
    Write a recursive function to calculate the factorial of a non-negative number n. Given the definition of factorial according to the following formula:
           |-  4,                     x = 0
    f(x) = |-  7,                     x = 1
           |-  4.f(x - 1) + f(x - 2), x >= 1
    */
    int x;
    printf("Entering the number: ");
    scanf("%d", &x);

    printf("f(%d) = %d", x, function(x));
    return 0;
}

int function(int x){
    if(x == 0) return 4;
    if(x == 1) return 7;
    return 4 * function(x - 1) - function(x - 2);
}