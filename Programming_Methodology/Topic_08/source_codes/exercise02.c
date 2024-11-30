#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX_LENGTH 100

// Declare the structure of employee
struct Employee{
    int id;
    char name[MAX_LENGTH];
    int sex; // male is 0 and female is 1
    int birthyear;
    char phone_number[MAX_LENGTH];
    int salary;
};

// The function return dynamic array of structures
struct Employee* init_employees(int size);
void display_info(struct Employee employee);

int main(){
    // Define an array contains 10 employees
    
    // Create employee array
    struct Employee *employees;

    /*
    Using the loop function to generate manually information 
        for 10 employees as following code:
    struct Employee employees[10];
    for(int i = 0; i < 10; i++){
        employees[i] = create_employee();
    }

    However, to save time, I will declare a function that automatically creates
        a dynamic/static array to return 10 employees.
    */
    employees = init_employees(10);

    // Display information of first employee
    printf("Employee 0: \n");
    display_info(employees[0]);

    printf("\nEmployee 1: \n");
    display_info(employees[1]);

    // Release memory
    free(employees);
    return 0;
}

struct Employee* init_employees(const int size){
    // Declaring first and last names to generate full names
    char *first_names[10] = {"James", "Michael", 
                            "Robert", "Thomas", 
                            "Richard", "Susan", 
                            "Elizabeth", "Jessica", 
                            "Charles", "Daniel"};
    char *last_names[10] = {"Smith", "Brown", 
                            "Miller", "Johnson", 
                            "Jones", "Davis", 
                            "Williams", "Garcia", 
                            "Martinez", "Wilson"};
    char digits[10] = "0123456789";
    struct Employee *employees = malloc(size * sizeof(struct Employee));
    if(employees == NULL){
        printf("Don't have enough memory to allocate");
        exit(1);
    }

    // The function of `snprinft`: https://cplusplus.com/reference/cstdio/snprintf/
    for(int i = 0; i < size; i++){
        employees[i].id = i;
        snprintf(employees[i].name, MAX_LENGTH, "%s %s", 
                 first_names[rand() % 10], 
                 last_names[rand() % 10]); // Combine first and last names
        employees[i].sex = rand() % 2; // Random from 0 -> 1
        employees[i].birthyear = rand() % (2011 - 1980) + 1980; // Random from 1980 - 2010
        for(int j = 0; j < 10; j++)
            employees[i].phone_number[j] = digits[rand() % 10];
        employees[i].phone_number[10] = '\0';
        employees[i].salary = rand() % (10000 - 1999) + 2000;  // Random from 2000 -> 10000
    }
        
    return employees;
}

void display_info(struct Employee employee){
    printf("Id: %d\n", employee.id);
    printf("Name: %s\n", employee.name);
    if(employee.sex)
        printf("Gender: Female\n");
    else
        printf("Gender: Male\n");
    printf("Birthyear: %d\n", employee.birthyear);
    printf("Phone number: %s\n", employee.phone_number);
    printf("Salary: %d\n", employee.salary);
}