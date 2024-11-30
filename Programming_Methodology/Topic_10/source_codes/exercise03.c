#include<stdio.h>

const int MAX_VALID_YR = 9999; 
const int MIN_VALID_YR = 1800; 

int isLeap(int year);
int isValidDate(int d, int m, int y);

int main(){
    // Write a program that allows the user to enter date, month, year information, and then checks whether the information is valid or not.
    int date, month, year;
    printf("Enter the date: ");
    scanf("%d", &date);
    printf("Enter the month: ");
    scanf("%d", &month);
    printf("Enter the year: ");
    scanf("%d", &year);

    isValidDate(date, month, year) ? printf("Yes") : printf("No");
    return 0;
}
  
// Returns true if  
// given year is valid. 
int isLeap(int year){ 
    // Return true if year  
    // is a multiple of 4 and 
    // not multiple of 100. 
    // OR year is multiple of 400. 
    return (((year % 4 == 0) &&  
            (year % 100 != 0)) || 
            (year % 400 == 0)); 
} 
  
// Returns true if given 
// year is valid or not. 
int isValidDate(int d, int m, int y){ 
    // If year, month and day  
    // are not in given range 
    if (y > MAX_VALID_YR || y < MIN_VALID_YR) 
        return 0; 
    if (m < 1 || m > 12) 
        return 0; 
    if (d < 1 || d > 31) 
        return 0; 
  
    // Handle February month  
    // with leap year 
    if (m == 2){ 
        if (isLeap(y)) 
            return (d <= 29); 
        else
            return (d <= 28); 
    } 
  
    // Months of April, June,  
    // Sept and Nov must have  
    // number of days less than 
    // or equal to 30. 
    if (m == 4 || m == 6 || 
        m == 9 || m == 11) 
        return (d <= 30); 
  
    return 1; 
} 