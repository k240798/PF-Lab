#include <stdio.h>

#define SIZE 4

void inputMatrix(int matrix[SIZE][SIZE]);
void sortColumns(int matrix[SIZE][SIZE]);
void printMatrix(int matrix[SIZE][SIZE]);

int main() {
    int matrix[SIZE][SIZE];

    // Input the matrix
    printf("Enter the scores for a 4x4 matrix (4 rounds and 3 teams, with an extra row for total):\n");
    inputMatrix(matrix);

    // Sort each column in ascending order
    sortColumns(matrix);

    // Display the sorted matrix
    printf("\nMatrix with each column sorted in ascending order:\n");
    printMatrix(matrix);

    return 0;
}

// Function to input a 4x4 matrix
void inputMatrix(int matrix[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("Enter score for team %d in round %d: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to sort each column of the matrix in ascending order
void sortColumns(int matrix[SIZE][SIZE]) {
    for (int j = 0; j < SIZE; j++) {  // Loop over each column
        for (int i = 0; i < SIZE - 1; i++) {
            for (int k = i + 1; k < SIZE; k++) {
                if (matrix[i][j] > matrix[k][j]) {
                    // Swap elements to sort the column
                    int temp = matrix[i][j];
                    matrix[i][j] = matrix[k][j];
                    matrix[k][j] = temp;
                }
            }
        }
    }
}

// Function to print the matrix
void printMatrix(int matrix[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
