#include<stdio.h>

void convert(const int input_days);

int main(){
    // Write a C program to convert specified days into years, \
    weeks and days. (Note: ignore leap year)

    // Example: 380 days -> 1 year, 2 weeks and 1 day

    // Hint: Ignoring leap year, so we have 1 year equal 365 \
    days. We can divide by 365 to find the number of years, \
    the quotient will be the number of years and the remainder \
    will be the left days. Next, we continously use the remainder \
    from previous expression dividing by 7 to find quotient and \
    remainder, the quotient will be the number of weeks and the \
    remainder will be the left days.

    int input_days;

    printf("Entering the number of days to convert: ");
    scanf("%d", &input_days);
    
    convert(input_days);
    
    return 0;
}

void convert(const int input_days){
    int years, weeks, days;
    years = input_days / 365;
    weeks = (input_days % 365) / 7;
    days = (input_days % 365) % 7;

    printf("%d day(s) => %d year(s), %d week(s), %d day(s)", input_days, years, weeks, days);
}