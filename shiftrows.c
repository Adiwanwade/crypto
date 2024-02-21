#include <stdio.h>
void shifting( int a[4][4]) {
    int temp;
    temp = a[1][0];
    a[1][0] = a[1][1];
    a[1][1] = a[1][2];
    a[1][2] = a[1][3];
    a[1][3] = temp;

    temp = a[2][0];
    a[2][0] = a[2][2];
    a[2][2] = temp;
    temp = a[2][1];
    a[2][1] = a[2][3];
    a[2][3] = temp;
    
    temp = a[3][0];
    a[3][0] = a[3][3];
    a[3][3] = a[3][2];
    a[3][2] = a[3][1];
    a[3][1] = temp;
}

void print(int a[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matrix[4][4] = {
        {16, 15,45 ,4 },
        {5,65,74 ,81 },
        {95, 210, 161,192 },
        {136,149 ,155 ,167 }
    };

    printf("Original matrix:\n");
    print(matrix);

    shifting(matrix);

    printf("\n matrix after ShiftRows transformation:\n");
    print(matrix);

    return 0;
}