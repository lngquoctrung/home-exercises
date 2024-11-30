#include<stdio.h>

int main(){
    // Write a C program to compute the perimeter and area of \
    a rectangle with a height provided by user

    // Attention: The requirement only asks a height provided \
    by user, so we can define a width as a fixed value and not \
    a constant.

    int width = 10, height, perimeter, area;

    printf("Entering the height of rectangle: ");
    scanf("%d", &height);

    // Perimeter
    perimeter = 2 * (width + height);
    printf("Perimeter: 2 * (%d + %d) = %d\n", width, height, perimeter);

    // Area
    area = width * height;
    printf("Area: %d * %d = %d", width, height, area);

    return 0;
}