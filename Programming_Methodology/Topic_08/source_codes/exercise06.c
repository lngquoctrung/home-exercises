#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX_LENGTH 1000

// Declare the structure of employee
struct Employee{
    int id;
    char name[MAX_LENGTH];
    int sex; // male is 0 and female is 1
    int birthyear;
    char phone_number[MAX_LENGTH];
    int salary;
};

// =====Support functions=====
// The function return dynamic array of structures
struct Employee* init_employees(int size);
void to_string(struct Employee employee);
void print_all(const struct Employee *employees, const int size);
void swap(struct Employee *employee01, struct Employee *employee02);

// =====Main functions=====
void birthyear_sort(struct Employee *employees, const int size);

int main(){
    // Sort the employee array in ascending order of birthyear
    
    int size;
    printf("Enter the number of employees: ");
    scanf("%d", &size);

    // Create employee array
    struct Employee *employees = init_employees(size);
    print_all(employees, size);

    // Display result
    birthyear_sort(employees, size);
    printf("\nSorted list: \n");
    print_all(employees, size);

    // Release memory
    free(employees);
    return 0;
}

// =====Main function=====
void birthyear_sort(struct Employee *employees, const int size){
    int min_index;
    for(int i = 0; i < size - 1; i++){
        min_index = i;
        for(int j = min_index + 1; j < size; j++){
            if(employees[min_index].birthyear > employees[j].birthyear)
                min_index = j;
        }
        swap(&employees[i], &employees[min_index]);
    }
}

void swap(struct Employee *employee01, struct Employee *employee02){
    struct Employee temp = *employee01;
    *employee01 = *employee02;
    *employee02 = temp;
}

// =====Support functions=====
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
        employees[i].sex = rand() % 2; // Random from 0 . 1
        employees[i].birthyear = rand() % (2011 - 1980) + 1980; // Random from 1980 - 2010
        for(int j = 0; j < 10; j++)
            employees[i].phone_number[j] = digits[rand() % 10];
        employees[i].phone_number[10] = '\0';
        employees[i].salary = rand() % (10000 - 1999) + 2000;  // Random from 2000 . 10000
    }
        
    return employees;
}

void to_string(struct Employee employee){
    char string[MAX_LENGTH];
    snprintf(string, MAX_LENGTH, 
            "Employee{Id=%d, name='%s', sex='%s', birthyear=%d, phone_number='%s', salary=%d}\n", 
            employee.id, employee.name, 
            employee.sex ? "Female" : "Male", employee.birthyear, 
            employee.phone_number, employee.salary);
    printf("%s", string);
}

void print_all(const struct Employee *employees, const int size){
    for(int i = 0; i < size; i++){
        to_string(employees[i]);
    }
}