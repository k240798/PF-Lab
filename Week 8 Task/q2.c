#include <stdio.h>
#define SIZE 4

int main() {
    int grades[SIZE][SIZE];

    // Input the 4x4 matrix
    printf("Enter the grades for 4 students across 4 subjects (4x4 matrix):\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("Grade for Student %d, Subject %d: ", i + 1, j + 1);
            scanf("%d", &grades[i][j]);
        }
    }

    // Replace negative grades with zero
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (grades[i][j] < 0) {
                grades[i][j] = 0;
            }
        }
    }

    // Display the updated matrix
    printf("\nUpdated grades matrix (negative grades replaced with zero):\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", grades[i][j]);
        }
        printf("\n");
    }

    return 0;
}
