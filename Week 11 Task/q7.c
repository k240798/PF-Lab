#include <stdio.h>
#include <string.h>

#define MAX_DEPARTMENTS 5
#define MAX_COURSES 5

struct Course {
    int courseID;            
    char courseName[50];     
    char instructor[50];     
    int credits;             
};

struct Department {
    char departmentName[50]; 
    struct Course courses[MAX_COURSES]; 
    int numCourses;          
};

struct University {
    struct Department departments[MAX_DEPARTMENTS];
    int numDepartments;  
};

void addDepartment(struct University* uni) {
    if (uni->numDepartments >= MAX_DEPARTMENTS) {
        printf("Cannot add more departments. Max limit reached.\n");
        return;
    }

    printf("Enter department name: ");
    getchar(); 
    fgets(uni->departments[uni->numDepartments].departmentName, sizeof(uni->departments[uni->numDepartments].departmentName), stdin);
    uni->departments[uni->numDepartments].departmentName[strcspn(uni->departments[uni->numDepartments].departmentName, "\n")] = '\0';  

    uni->departments[uni->numDepartments].numCourses = 0;
    uni->numDepartments++;
    printf("Department added successfully!\n");
}

void addCourse(struct University* uni) {
    int depIndex;
    if (uni->numDepartments == 0) {
        printf("No departments available. Please add a department first.\n");
        return;
    }

    printf("Enter department index (0 to %d): ", uni->numDepartments - 1);
    scanf("%d", &depIndex);
    if (depIndex < 0 || depIndex >= uni->numDepartments) {
        printf("Invalid department index.\n");
        return;
    }

    struct Department* dep = &uni->departments[depIndex];
    if (dep->numCourses >= MAX_COURSES) {
        printf("Cannot add more courses. Max limit reached.\n");
        return;
    }

    printf("Enter course ID: ");
    scanf("%d", &dep->courses[dep->numCourses].courseID);
    getchar(); 

    printf("Enter course name: ");
    fgets(dep->courses[dep->numCourses].courseName, sizeof(dep->courses[dep->numCourses].courseName), stdin);
    dep->courses[dep->numCourses].courseName[strcspn(dep->courses[dep->numCourses].courseName, "\n")] = '\0'; 

    printf("Enter instructor name: ");
    fgets(dep->courses[dep->numCourses].instructor, sizeof(dep->courses[dep->numCourses].instructor), stdin);
    dep->courses[dep->numCourses].instructor[strcspn(dep->courses[dep->numCourses].instructor, "\n")] = '\0'; 

    printf("Enter number of credits: ");
    scanf("%d", &dep->courses[dep->numCourses].credits);

    dep->numCourses++;
    printf("Course added successfully!\n");
}

void displayUniversity(struct University* uni) {
    if (uni->numDepartments == 0) {
        printf("No departments to display.\n");
        return;
    }

    printf("\nUniversity Details:\n");
    for (int i = 0; i < uni->numDepartments; i++) {
        printf("\nDepartment: %s\n", uni->departments[i].departmentName);
        printf("Courses in this department:\n");
        for (int j = 0; j < uni->departments[i].numCourses; j++) {
            printf("Course ID: %d\n", uni->departments[i].courses[j].courseID);
            printf("Course Name: %s\n", uni->departments[i].courses[j].courseName);
            printf("Instructor: %s\n", uni->departments[i].courses[j].instructor);
            printf("Credits: %d\n", uni->departments[i].courses[j].credits);
            printf("-------------------------------\n");
        }
    }
}

void calculateTotalCredits(struct University* uni) {
    int depIndex;
    printf("Enter department index (0 to %d): ", uni->numDepartments - 1);
    scanf("%d", &depIndex);
    if (depIndex < 0 || depIndex >= uni->numDepartments) {
        printf("Invalid department index.\n");
        return;
    }

    int totalCredits = 0;
    for (int i = 0; i < uni->departments[depIndex].numCourses; i++) {
        totalCredits += uni->departments[depIndex].courses[i].credits;
    }

    printf("Total credits in department '%s': %d\n", uni->departments[depIndex].departmentName, totalCredits);
}

int main() {
    struct University uni = {0}; 

    int choice;
    while (1) {
        printf("\nUniversity Course Enrollment System\n");
        printf("1. Add Department\n");
        printf("2. Add Course\n");
        printf("3. Display All Departments and Courses\n");
        printf("4. Calculate Total Credits for a Department\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addDepartment(&uni);
                break;
            case 2:
                addCourse(&uni);
                break;
            case 3:
                displayUniversity(&uni);
                break;
            case 4:
                calculateTotalCredits(&uni);
                break;
            case 5:
                printf("Exiting system...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
