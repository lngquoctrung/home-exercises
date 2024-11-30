#include<stdio.h>
#include<string.h>
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

// The function create and display information of a employee
struct Employee create_employee();
void display_info(struct Employee employee);

int main(){
    // Define an Employee structure contains the following properties: id, name, sex, birthyear, phone number, salary
    
    // Create employee
    struct Employee employee_01 = create_employee();
    // Display information of employee
    display_info(employee_01);
    
    return 0;
}

struct Employee create_employee(){
    struct Employee employee;
    // Entering the Id
    printf("Enter the Id of employee: ");
    scanf("%d", &employee.id);
    getchar();      // Ignore newline character after using scanf
    
    // Entering the name
    printf("Enter the name of employee: ");
    fgets(employee.name, MAX_LENGTH, stdin);
    // strcpn function returns the length of str_1 that does not contain str_2
    // str_1 = "ABCDFG0012", str_2 = "01" => strscpn(str_1, str_2) = 7
    // str_1 = "ABCD\n", str_2 = "\n" => strscpn(str_1, str_2) => 4 (The position of newline character in str_1)
    employee.name[strcspn(employee.name, "\n")] = 0;  // Removing newline of fgets function
    
    // Entering the gender
    printf("Enter the gender of employee: ");
    scanf("%d", &employee.sex);
    
    // Entering the birthyear
    printf("Enter the birthyear of employee: ");
    scanf("%d", &employee.birthyear);
    getchar();
    
    // Entering the phone number
    printf("Enter the phone number of employee: ");
    fgets(employee.phone_number, MAX_LENGTH, stdin);
    employee.phone_number[strcspn(employee.phone_number, "\n")] = 0;  // Removing newline of fgets function
    
    // Entering the salary
    printf("Enter the salary of employee: ");
    scanf("%d", &employee.salary);

    return employee;
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