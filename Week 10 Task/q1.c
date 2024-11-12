
#include <stdio.h>
#include <string.h>

void reverseString(char *str, int index) {
    int len = strlen(str);
    if (index >= len / 2) {
        return;
    }
    char temp = str[index];
    str[index] = str[len - index - 1];
    str[len - index - 1] = temp;
    reverseString(str, index + 1);
}

int main() {
    char str[100];
    printf("Enter a sentence: ");
    fgets(str, 100, stdin); 

    reverseString(str, 0);
    printf("%s\n", str); 

    return 0;
}
