#include <stdio.h>
#include <string.h>


void encryptColumnarTransposition(char plaintext[], char key[]) {
    int len = strlen(plaintext);
    int keyLen = strlen(key);

   
    int order[keyLen];
    for (int i = 0; i < keyLen; i++) {
        order[i] = i;
    }

    
    for (int i = 0; i < keyLen - 1; i++) {
        for (int j = 0; j < keyLen - i - 1; j++) {
            if (key[j] > key[j + 1]) {
               
                char temp = key[j];
                key[j] = key[j + 1];
                key[j + 1] = temp;

             
                int tempOrder = order[j];
                order[j] = order[j + 1];
                order[j + 1] = tempOrder;
            }
        }
    }


    int rows = len / keyLen;
    if (len % keyLen != 0) {
        rows++;
    }

    char matrix[rows][keyLen];

   
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < keyLen; j++) {
            matrix[i][j] = '\0';
        }
    }

   
    int index = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < keyLen; j++) {
            if (index < len) {
                matrix[i][order[j]] = plaintext[index++];
            } else {
                break;
            }
        }
    }

   
    printf("Encrypted Message: ");
    for (int j = 0; j < keyLen; j++) {
        for (int i = 0; i < rows; i++) {
            if (matrix[i][j] != '\0') {
                printf("%c", matrix[i][j]);
            }
        }
    }
    printf("\n");
}

int main() {
    char plaintext[100], key[100];

   
    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);

   
    plaintext[strcspn(plaintext, "\n")] = '\0';

    printf("Enter the key: ");
    fgets(key, sizeof(key), stdin);

   
    key[strcspn(key, "\n")] = '\0';

   
    encryptColumnarTransposition(plaintext, key);

    return 0;
}
