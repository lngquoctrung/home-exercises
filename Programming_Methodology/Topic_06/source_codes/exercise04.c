#include<stdio.h>
#include<math.h>

int exponential_function(int x, int n);

int main(){
    // Define a recursive function to compute x^n.
    int x, number;

    // Enter x and exponent values
    do{
        printf("Enter the x value: ");
        scanf("%d", &x);
        printf("Enter the exponent value: ");
        scanf("%d", &number);
    }
    while(x < 0 || number < 0);

    // Display result
    printf("%d^%d = %d", x, number, exponential_function(x, number));

    return 0;
}

int exponential_function(int x, int n){
    if(n == 1) return x; // Base case
    return x * exponential_function(x, n - 1);
}