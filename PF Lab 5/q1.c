#include <stdio.h>

int main() {
    /*Question 1:
    Create a program that checks if a person is eligible to vote based on their age and citizenship status.*/
    char paki;
    int age;
    
    printf("Are you a Paki? (Y/N)");
    scanf("%c", &paki);

    printf("Enter your age: ");
    scanf("%d", &age);

    if (paki == 'Y') {
        if (age >= 18) {
            printf("You are eligible to vote.");
        }
    }
    else {
        printf("You are not eligible to vote.");
    }

    return 0;
}