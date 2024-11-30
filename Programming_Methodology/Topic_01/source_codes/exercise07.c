#include<stdio.h>

int main(){
    // Write a C program to check wether a year is a leap year or not.

    // Hint: Leap year contains 366 days, which comes once every four years.
    /*
    Every leap year corresponds to these facts:
        - A century year is a year ending with 00. A century year \
            is a leap year only if it is divisible by 400.
        - A leap year (except a century year) can be identified if \
            it is exactly divisible by 4.
        - A century year should be divisible by 4 and 100 both.
        - A non-century year should be divisible only by 4.
    */

    int year, is_leap_year;

    printf("Entering the year: ");
    scanf("%d", &year);

    // If leap year is divisible by 4
    if(year % 4 == 0){
        is_leap_year = 1;
        // Checking whether year is century year or not
        if(year % 100 == 0){
            // If year is century year then leap year is divisible by 400
            if(year % 400 == 0){
                is_leap_year = 1;
            }
            else{
                is_leap_year = 0;
            }
        }
    }
    else{
        is_leap_year = 0;
    }
    if(is_leap_year){
        printf("%d is a leap year", year);
    }
    else{
        printf("%d is not a leap year", year);
    }

    return 0;
}