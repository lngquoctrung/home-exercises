#include<stdio.h>

void printTableOfNumber(int);

int main(){
    // Write a C function to print table of any number

    int number;

    printf("Entering the number: ");
    scanf("%d", &number);

    printTableOfNumber(number);

    return 0;
}

// The function only has print function so it is void type
void printTableOfNumber(int number){
    for(int i = 1; i <= 10; i++){
        printf("%d x %d = %d\n", number, i, number * i);
    }
}