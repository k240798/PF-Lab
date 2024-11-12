#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to apply the Vigenère cipher
void vigenereCipher(char *plaintext, char *key, char *ciphertext) {
    int textLen = strlen(plaintext);
    int keyLen = strlen(key);
    int i, j = 0;

    for (i = 0; i < textLen; i++) {
        if (isalpha(plaintext[i])) {  // Only encrypt alphabetic characters
            char base = isupper(plaintext[i]) ? 'A' : 'a';
            ciphertext[i] = (plaintext[i] - base + toupper(key[j % keyLen]) - 'A') % 26 + base;
            j++;  // Increment key index only if character is alphabetic
        } else {
            ciphertext[i] = plaintext[i];  // Keep non-alphabetic characters unchanged
        }
    }
    ciphertext[textLen] = '\0';  // Null-terminate the string
}

int main() {
    char plaintext[100], key[100], ciphertext[100];

    printf("Enter the Plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0';  // Remove the newline character

    printf("Enter the Key: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0';  // Remove the newline character

    vigenereCipher(plaintext, key, ciphertext);

    printf("Ciphertext: %s\n", ciphertext);

    return 0;
}
