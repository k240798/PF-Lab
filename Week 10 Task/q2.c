#include <stdio.h>

void printPercentage(int value, int percentage) {
    if (percentage > 100) {
        return;
    }
    printf("%d Percent = %.2f\n", percentage, value * (percentage / 100.0));
    printPercentage(value, percentage + 1);
}

int main() {
    int value;
    printf("Enter a value to split in percentage: ");
    scanf("%d", &value);

    printPercentage(value, 1); 

    return 0;
}
