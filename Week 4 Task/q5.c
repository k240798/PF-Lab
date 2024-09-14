#include<stdio.h>

    /* Question 5:
    Write a C program to display greetings based on the time in a 24-hour format. If the time is:
     Between 6 and 11 (inclusive of 6 but not 12): Greet with “Good Morning”.
     Between 12 and 17 (inclusive of 12 but not 18): Greet with “Good Afternoon”.
     Between 18 and 23 (inclusive of 18 but not 24): Greet with “Good Evening”.
     Between 0 and 5: Greet with “Good Night” */
int main() {
    int time;

    printf("Enter the hour of the day it is right now (in 24-hour format): ");
    scanf("%d", &time);

    if (time < 0 || time > 23) {
        printf("Invalid time! Please enter a time between 0 and 23. Thank you!");
    }
    else {
        if (time >= 0 && time < 6) {
            printf("Good Night\n");
        }
        else if (time >= 6 && time < 12) {
            printf("Good Morning\n");
        }
        else if (time >= 12 && time < 18) {
            printf("Good Afternoon\n");
        }
        else if (time >= 18 && time < 24) {
            printf("Good Evening\n");
        }
    }
    return 0;
}