#include<stdio.h>

int main(){
    // Write a C program to check whether a number is even or odd.
    int number;
    printf("Entering the number: ");
    scanf("%d", &number);

    if(number % 2 == 0){
        printf("The number is even");
    }
    else{
        printf("The number is odd");
    }

    return 0;
}