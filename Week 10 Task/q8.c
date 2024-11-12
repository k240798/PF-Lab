#include <stdio.h>

void printArray(int arr[], int size) {
    if (size == 0) {
        return;
    }

    printf("%d ", arr[0]);

    printArray(arr + 1, size - 1); 
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]);  

    printf("Array elements: ");
    printArray(arr, size);
    
    return 0;
}
