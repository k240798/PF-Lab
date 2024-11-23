#include <stdio.h>
#include <stdlib.h>

void display_file_with_line_numbers(const char *filename) {
    FILE *file = fopen(filename, "r");      
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }

    char line[256];  
    int line_number = 1;

    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%d: %s", line_number, line);
        line_number++;
    }

    fclose(file);  
}

int main() {
    char filename[100];

    printf("Enter the filename to read: ");
    scanf("%99s", filename); 

    display_file_with_line_numbers(filename);

    return 0;
}
