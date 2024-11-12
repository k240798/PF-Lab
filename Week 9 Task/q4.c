#include <stdio.h>
#include <string.h> 

int main() {
    char students[5][50] = {
        "Alice",
        "Harry",
        "Charlie",
        "Diana",
        "Eve"
    };

    char input_name[50];

    printf("Enter the name to search: ");
    scanf("%49s", input_name);  

    int found = 0;

    for (int i = 0; i < 5; i++) {
        if (strcmp(students[i], input_name) == 0) {
            found = 1;
            break;
        }
    }

    if (found) {
        printf("Found\n");
    } else {
        printf("Not Found\n");
    }

    return 0;
}
