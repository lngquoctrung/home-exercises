#include<stdio.h>
#include<math.h>

int main(){
    // Write a C program to return an absolute value of a number.

    // Hint: We can check whether a input number is negative \
    or not, if the input number is negative, we can multiply \
    with -1 to get the absolute number. Besides, we have many \
    other ways to solve this problem, a simplest way is using \
    abs function from library math.h

    int number;
    printf("Entering a number: ");
    scanf("%d", &number);
    printf("|%d| = %d", number, abs(number));
    return 0;
}