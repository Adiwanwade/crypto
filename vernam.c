#include <stdio.h>
#include <string.h>

void vernamEncrypt(char plaintext[], char key[])
{
    int len = strlen(plaintext);

    if (strlen(key) != len)
    {
        printf("Error: Key length must be the same as plaintext length.\n");
        return;
    }

    char ciphertext[len + 1];

    for (int i = 0; i < len; i++)
    {

        ciphertext[i] = (97 + ((((int)plaintext[i] - 97) + ((int)key[i]) - 97) % 25));
        if (ciphertext[i] > 122)
        {
            ciphertext[i] = (char)(97 + (ciphertext[i] - 122));
        }
    }

    ciphertext[len] = '\0';

    printf("Encrypted Message: %s\n", ciphertext);
}

int main()
{
    char plaintext[100], key[100];

    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    plaintext[strcspn(plaintext, "\n")] = '\0';

    printf("Enter the key: ");
    fgets(key, sizeof(key), stdin);

    key[strcspn(key, "\n")] = '\0';

    vernamEncrypt(plaintext, key);

    return 0;
}
