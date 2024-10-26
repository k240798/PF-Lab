#include <stdio.h>

#define SIZE 3

int main() {
    int scores[SIZE][SIZE];
    int rowSum[SIZE] = {0};
    int colSum[SIZE] = {0};

    // Input the 3x3 matrix
    printf("Enter the scores for 3 participants across 3 activities (3x3 matrix):\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("Score for Participant %d, Activity %d: ", i + 1, j + 1);
            scanf("%d", &scores[i][j]);
        }
    }

    // Calculate row sums and column sums
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            rowSum[i] += scores[i][j];
            colSum[j] += scores[i][j];
        }
    }

    // Display the results
    printf("\nSum of scores for each participant:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("Participant %d: %d\n", i + 1, rowSum[i]);
    }

    printf("\nSum of scores for each activity:\n");
    for (int j = 0; j < SIZE; j++) {
        printf("Activity %d: %d\n", j + 1, colSum[j]);
    }

    return 0;
}
