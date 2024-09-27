#include<stdio.h>

int main () {
    /*Question 2:
    Check if a triangle is valid based on its three angles, where the sum must be exactly 180 degrees and all
    angles must be positive.*/
    float angle1, angle2, angle3, sum;
    printf("Enter the first angle: ");
    scanf("%f", &angle1);
    
    printf("Enter the second angle: ");
    scanf("%f", &angle2);
    
    printf("Enter the third angle: ");
    scanf("%f", &angle3);

    if (angle1 > 0 && angle2 >0 && angle3 > 0) {
        sum = angle1 + angle2 + angle3;
        if (sum == 180) {
            printf("It is a triangle");
        }
        else {
            printf("Not a triangle because sum of angles is not equal to 180");
        }
    }
    else {
        printf("One or more angles entered are negative.");
    }

}