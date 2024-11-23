#include <stdio.h>
#include <string.h>

struct Employee {
    char name[50];
    char dob[20]; 
    int empID;
    char department[30];
    float salary;
};

void addEmployee(struct Employee employees[], int *employeeCount) {
    if (*employeeCount >= 5) {
        printf("Cannot add more employees. The maximum limit is 5.\n");
        return;
    }

    printf("Enter employee details:\n");
    printf("Name: ");
    getchar(); 
    fgets(employees[*employeeCount].name, sizeof(employees[*employeeCount].name), stdin);
    employees[*employeeCount].name[strcspn(employees[*employeeCount].name, "\n")] = '\0';

    printf("Date of Birth (DD/MM/YYYY): ");
    fgets(employees[*employeeCount].dob, sizeof(employees[*employeeCount].dob), stdin);
    employees[*employeeCount].dob[strcspn(employees[*employeeCount].dob, "\n")] = '\0'; 

    printf("Employee ID: ");
    scanf("%d", &employees[*employeeCount].empID);

    printf("Department: ");
    getchar();  
    fgets(employees[*employeeCount].department, sizeof(employees[*employeeCount].department), stdin);
    employees[*employeeCount].department[strcspn(employees[*employeeCount].department, "\n")] = '\0';

    printf("Salary: ");
    scanf("%f", &employees[*employeeCount].salary);

    (*employeeCount)++;
    printf("Employee added successfully!\n");
}

void deleteEmployee(struct Employee employees[], int *employeeCount, int empID) {
    int found = 0;
    for (int i = 0; i < *employeeCount; i++) {
        if (employees[i].empID == empID) {
            for (int j = i; j < *employeeCount - 1; j++) {
                employees[j] = employees[j + 1];
            }
            (*employeeCount)--;
            found = 1;
            printf("Employee with ID %d has been deleted.\n", empID);
            break;
        }
    }
    if (!found) {
        printf("Employee with ID %d not found.\n", empID);
    }
}

void displayEmployees(struct Employee employees[], int employeeCount) {
    if (employeeCount == 0) {
        printf("No employees to display.\n");
        return;
    }

    printf("\nEmployee Details:\n");
    printf("---------------------------------------------------------\n");
    for (int i = 0; i < employeeCount; i++) {
        printf("Name: %s\n", employees[i].name);
        printf("Date of Birth: %s\n", employees[i].dob);
        printf("Employee ID: %d\n", employees[i].empID);
        printf("Department: %s\n", employees[i].department);
        printf("Salary: %.2f\n", employees[i].salary);
        printf("---------------------------------------------------------\n");
    }
}

int main() {
    struct Employee employees[5];  
    int employeeCount = 0;  
    int choice, empID;

    while (1) {
        printf("\nEmployee Management System\n");
        printf("1. Add an Employee\n");
        printf("2. Delete an Employee\n");
        printf("3. Display All Employees\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEmployee(employees, &employeeCount);
                break;
            case 2:
                printf("Enter Employee ID to delete: ");
                scanf("%d", &empID);
                deleteEmployee(employees, &employeeCount, empID);
                break;
            case 3:
                displayEmployees(employees, employeeCount);
                break;
            case 4:
                printf("Exiting the system...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
