#include<stdio.h>
#include<math.h>

int factorial(int n);

int main(){
    // Define a recursive function to compute factorial of n.
    int number;

    // Enter the number
    do{
        printf("Enter the number: ");
        scanf("%d", &number);
    }
    while(number < 0);

    // Display result
    printf("%d! = %d", number, factorial(number));

    return 0;
}

int factorial(int n){
    if(n == 0) return 1; // Base case
    return n * factorial(n - 1);
}