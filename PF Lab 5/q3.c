#include <stdio.h>

int main() {
    float percentage;
    char grade;

    printf("Enter the percentage: ");
    scanf("%f", &percentage);

    grade = (percentage >= 90) ? 'A' :
            (percentage >= 80) ? 'B' :
            (percentage >= 70) ? 'C' :
            (percentage >= 60) ? 'D' : 'F';

    printf("The letter grade is: %c\n", grade);

    return 0;
}
