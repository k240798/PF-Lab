#include <stdio.h>
#include <string.h> 
int main() {
    
    const char preset_username[] = "admin";
    const char preset_password[] = "1234";

    char entered_username[50];
    char entered_password[50];

    printf("Enter username: ");
    scanf("%s", entered_username);

    printf("Enter password: ");
    scanf("%s", entered_password);

    if (strcmp(entered_username, preset_username) == 0 && strcmp(entered_password, preset_password) == 0) {
        printf("Access granted\n");
    } else {
        printf("Access denied\n");
    }

    return 0;
}
