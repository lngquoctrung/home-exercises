#include<stdio.h>
#include<math.h>

typedef struct Point{
    int x;
    int y;
    void (*to_string)(struct Point *point);
} Point;

void to_string(Point *point);
float distance(Point A, Point B);

int main(){
    // In the Oxy coordinate system, given two points A and B with real 
    //   coordinates. Calculate the distance between two points A and B, 
    //   knowing that, d = sqrt((xA - XB)^2 + (yA - yB)^2)
    Point A, B;
    A.to_string = to_string;
    B.to_string = to_string;
    printf("Enter the x-axis value of point A: ");
    scanf("%d", &A.x);
    printf("Enter the y-axis value of point A: ");
    scanf("%d", &A.y);
    printf("Enter the x-axis value of point B: ");
    scanf("%d", &B.x);
    printf("Enter the y-axis value of point B: ");
    scanf("%d", &B.y);

    A.to_string(&A);
    B.to_string(&B);

    printf("The distance of two points A and B = %f", distance(A, B));

    return 0;
}

void to_string(Point *point){
    char display_str[1000];
    snprintf(display_str, 1000, "Point: (%d, %d)", point->x, point->y);
    puts(display_str);
}

float distance(Point A, Point B){
    return sqrt(pow((A.x - B.x), 2) + pow((A.y - B.y), 2));
}
