#include <stdio.h>
#include <string.h>

// Function to perform columnar transposition encryption
void encryptColumnarTransposition(char plaintext[], int key) {
    int len = strlen(plaintext);
    int rows = len / key;
    if (len % key != 0) {
        rows++;
    }

    char matrix[rows][key];

    // Initialize matrix with null characters
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < key; j++) {
            matrix[i][j] = '\0';
        }
    }

    // Fill the matrix with the plaintext
    int index = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < key; j++) {
            if (index < len) {
                matrix[i][j] = plaintext[index++];
            } else {
                break;
            }
        }
    }

    // Print the encrypted message by reading the matrix column-wise
    printf("Encrypted Message: ");
    for (int j = 0; j < key; j++) {
        for (int i = 0; i < rows; i++) {
            if (matrix[i][j] != '\0') {
                printf("%c", matrix[i][j]);
            }
        }
    }
    printf("\n");
}

int main() {
    char plaintext[100];
    int key;

    // Input plaintext and key from user
    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    // Remove the newline character from the input
    plaintext[strcspn(plaintext, "\n")] = '\0';

    printf("Enter the key: ");
    scanf("%d", &key);

    // Perform encryption
    encryptColumnarTransposition(plaintext, key);

    return 0;
}
