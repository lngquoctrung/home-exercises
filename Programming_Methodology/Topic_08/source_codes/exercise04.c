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

// =====Main functions=====
int find_employee(const struct Employee *employees, const int size, const int id);

int main(){
    // Find an employee by providing his/her id
    
    int size, id;
    printf("Enter the number of employees: ");
    scanf("%d", &size);

    printf("Enter the Id to find (< %d): ", size);
    scanf("%d", &id);

    // Create employee array
    struct Employee *employees = init_employees(size);
    print_all(employees, size);

    // Display result
    int found_index = find_employee(employees, size, id);
    if(found_index != -1){
        printf("\n");
        to_string(employees[found_index]);
    }
    else
        printf("\nNot found");

    // Release memory
    free(employees);
    return 0;
}

// =====Main function=====
int find_employee(const struct Employee *employees, const int size, const int id){
    for(int i = 0; i < size; i++)
        if(employees[i].id == id)
            return i;
    return -1; // Not found
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