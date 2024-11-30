#include<stdio.h>

int main(){

    // Write a C program to print table of any number

    int number;

    printf("Entering the number: ");
    scanf("%d", &number);
    
    for(int i = 1; i <= 10; i++){
        printf("%d x %d = %d\n", number, i, number * i);
    }

    return 0;
}