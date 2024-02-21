#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void Decipherautokey(char ciphertext[], char key[]) {
    int i;
    int len = strlen(ciphertext);
    char decrypted[len];

    for (i = 0; i < len; i++) {
        decrypted[i] = (97 + (((ciphertext[i] - 97) - (key[i] - 97) + 26) % 26));
        if (decrypted[i] > 122) {
            decrypted[i] = (char)(97 + (decrypted[i] - 123));
        }
    }
decrypted[len]='\0';
    printf("Decrypting autokey message : %s\n", decrypted);
}
void decryptMsg(char enMsg[], int key){
    int msgLen = strlen(enMsg), i, j, k = -1, row = 0, col = 0, m = 0;
    char railMatrix[key][msgLen];
 
    for(i = 0; i < key; ++i)
        for(j = 0; j < msgLen; ++j)
            railMatrix[i][j] = '\n';
 
    for(i = 0; i < msgLen; ++i){
        railMatrix[row][col++] = '*';
 
        if(row == 0 || row == key-1)
            k= k * (-1);
 
        row = row + k;
    }
 
    for(i = 0; i < key; ++i)
        for(j = 0; j < msgLen; ++j)
            if(railMatrix[i][j] == '*')
                railMatrix[i][j] = enMsg[m++];
 
    row = col = 0;
    k = -1;
 
    printf("\nDecrypting rail-fence Message: ");
 
    for(i = 0; i < msgLen; ++i){
        printf("%c", railMatrix[row][col++]);
 
        if(row == 0 || row == key-1)
            k= k * (-1);
 
        row = row + k;
    }
}
void encryptMsg(char msg[], int key){
    int msgLen = strlen(msg), i, j,f=0, k = -1, row = 0, col = 0;
    char railMatrix[key][msgLen];
 char NMessage[msgLen];
    for(i = 0; i < key; ++i)
        for(j = 0; j < msgLen; ++j)
            railMatrix[i][j] = '\n';
 
    for(i = 0; i < msgLen; ++i){
        railMatrix[row][col++] = msg[i];
 
        if(row == 0 || row == key-1)
            k= k * (-1);
 
        row = row + k;
    }
 
    printf("\nEncrypting the autokey message by Rail-fence cipher: ");
 
    for(i = 0; i < key; ++i){
        for(j = 0; j < msgLen; ++j){
            if(railMatrix[i][j] != '\n'){
                printf("%c", railMatrix[i][j]);
                NMessage[f]=railMatrix[i][j];
                f++;
                }
        }
    }
    decryptMsg(NMessage,3);
}


void autokey(char plaintext[], char key[]) {
    int i;
    int len = strlen(plaintext);
    char cipher[len];
  

  
    for (i = 1; i < len; i++) {
        key[i] = plaintext[i - 1];
    }


    for (i = 0; i < len; i++) {
        cipher[i] = (97 + (((plaintext[i] - 97) + (key[i] - 97)) % 26));
        if (cipher[i] > 122) {
            cipher[i] = (char)(97 + (cipher[i] - 123));
        }
    }
cipher[len-1]='\0';
    printf("Encrypting message by autokey Cipher: %s\n", cipher);

       encryptMsg(cipher, 3);
 printf("\n");
    
    Decipherautokey(cipher, key);
}

int main(){
    char key1;
    char plaintext[100],key[100];
    printf("Enter the message:");
    fgets(plaintext,sizeof(plaintext),stdin);
    printf("Enter the key:");
    scanf("%c",&key1);
    key[0]=key1;

    autokey(plaintext,key);
   

    return 0;
}


