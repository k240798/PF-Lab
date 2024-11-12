#include <stdio.h>

#define MAX_NAME_LENGTH 50
#define MAX_DEPARTMENT_LENGTH 50

struct Employee {
    int employeeID;
    char name[MAX_NAME_LENGTH];
    char department[MAX_DEPARTMENT_LENGTH];
    float salary;
};

void inputEmployeeData(struct Employee *emp) {
    printf("Enter Employee ID: ");
    scanf("%d", &emp->employeeID);
    getchar();  

    printf("Enter Employee Name: ");
    fgets(emp->name, MAX_NAME_LENGTH, stdin);
    emp->name[strcspn(emp->name, "\n")] = '\0';

    printf("Enter Employee Department: ");
    fgets(emp->department, MAX_DEPARTMENT_LENGTH, stdin);
    emp->department[strcspn(emp->department, "\n")] = '\0';

    printf("Enter Employee Salary: ");
    scanf("%f", &emp->salary);
}

void displayEmployeeData(struct Employee emp) {
    printf("\nEmployee ID: %d\n", emp.employeeID);
    printf("Name: %s\n", emp.name);
    printf("Department: %s\n", emp.department);
    printf("Salary: %.2f\n", emp.salary);
}

int main() {
    int numEmployees;

    printf("Enter the number of employees: ");
    scanf("%d", &numEmployees);
    getchar();  

    struct Employee employees[numEmployees];

    for (int i = 0; i < numEmployees; i++) {
        printf("\nEnter details for Employee %d:\n", i + 1);
        inputEmployeeData(&employees[i]);
    }

    printf("\nEmployee Details:\n");
    for (int i = 0; i < numEmployees; i++) {
        printf("\nDetails of Employee %d:\n", i + 1);
        displayEmployeeData(employees[i]);
    }

    return 0;
}
