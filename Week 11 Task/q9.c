#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEPARTMENTS 5
#define MAX_COURSES 5
#define MAX_STUDENTS 10
#define MAX_NAME_LEN 100

struct Instructor {
    int instructor_id;
    char instructor_name[MAX_NAME_LEN];
    char department[MAX_NAME_LEN]; 
};

struct Student {
    int student_id;
    char student_name[MAX_NAME_LEN];
};

struct Course {
    int course_id;
    char course_name[MAX_NAME_LEN];
    int credits;
    struct Instructor instructor;  
    struct Student students[MAX_STUDENTS];  
    int student_count;  
};

struct Department {
    int dept_id;
    char dept_name[MAX_NAME_LEN];
    struct Course courses[MAX_COURSES];  
    int course_count;  
};

void initializeDepartment(struct Department* dept, int id, const char* name) {
    dept->dept_id = id;
    strcpy(dept->dept_name, name);
    dept->course_count = 0;
}

void initializeCourse(struct Course* course, int id, const char* name, int credits, struct Instructor instructor) {
    course->course_id = id;
    strcpy(course->course_name, name);
    course->credits = credits;
    course->instructor = instructor;
    course->student_count = 0;
}

void initializeInstructor(struct Instructor* instructor, int id, const char* name, const char* dept_name) {
    instructor->instructor_id = id;
    strcpy(instructor->instructor_name, name);
    strcpy(instructor->department, dept_name);
}

void initializeStudent(struct Student* student, int id, const char* name) {
    student->student_id = id;
    strcpy(student->student_name, name);
}

void enrollStudent(struct Course* course, struct Student student) {
    if (course->student_count < MAX_STUDENTS) {
        course->students[course->student_count] = student;
        course->student_count++;
        printf("Student %s (ID: %d) enrolled in course %s (ID: %d)\n", student.student_name, 
        student.student_id, course->course_name, course->course_id);
    } else {
        printf("Course is full! Cannot enroll student %s in course %s.\n", student.student_name, course->course_name);
    }
}

void displayUniversityDetails(struct Department departments[], int dept_count) {
    for (int i = 0; i < dept_count; i++) {
        printf("\nDepartment ID: %d, Department Name: %s\n", departments[i].dept_id, departments[i].dept_name);
        for (int j = 0; j < departments[i].course_count; j++) {
            printf("\tCourse ID: %d, Course Name: %s, Credits: %d\n", departments[i].courses[j].course_id, 
            departments[i].courses[j].course_name, departments[i].courses[j].credits);

            printf("\tInstructor: %s (ID: %d) from Department: %s\n", departments[i].courses[j].instructor.instructor_name,
             departments[i].courses[j].instructor.instructor_id, departments[i].courses[j].instructor.department);
            printf("\tEnrolled Students:\n");
            for (int k = 0; k < departments[i].courses[j].student_count; k++) {
                printf("\t\tStudent Name: %s, Student ID: %d\n", departments[i].courses[j].students[k].student_name,
                 departments[i].courses[j].students[k].student_id);
            }
        }
    }
}

int main() {
    struct Department departments[MAX_DEPARTMENTS];
    int dept_count = 0;

    struct Instructor instructor1;
    initializeInstructor(&instructor1, 101, "Dr. Arif Lohar", "Computer Science");

    struct Course course1;
    initializeCourse(&course1, 201, "Data Structures", 3, instructor1);

    struct Student student1, student2;
    initializeStudent(&student1, 301, "Amir");
    initializeStudent(&student2, 302, "Liaquat");

    enrollStudent(&course1, student1);
    enrollStudent(&course1, student2);

    initializeDepartment(&departments[dept_count], 1, "Computer Science");
    departments[dept_count].courses[departments[dept_count].course_count++] = course1;
    dept_count++;

    displayUniversityDetails(departments, dept_count);

    return 0;
}
