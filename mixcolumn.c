#include <stdio.h>
void Multiply(int mat1[][4], int mat2[], int re2[]) {
for (int i = 0; i < 4; i++) {
re2[i] = 0;
for (int j = 0; j < 4; j++) {
re2[i] += mat1[i][j] * mat2[j];
}
}
}

void print(int mat[], int rows, int cols) {
for (int i = 0; i < rows; i++) {
for (int j = 0; j < cols; j++) {
printf("%d ", mat[i * cols + j]);
}
printf("\n");
}
}

int main() {
    int mat1[4][4] = {
        {2, 3, 1, 1},
        {1, 2, 3, 1},
        {1, 1, 2, 3},
        {3, 1, 1,2}
    };
    int mat2[4] = {9, 5, 5, 1};
    int re2[4];

    printf("Matrix 1:\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", mat1[i][j]);
        }
        printf("\n");
    }

    printf("\nMatrix 2:\n");
    print(mat2, 4, 1);

    Multiply(mat1, mat2, re2);

    printf("\nResult Matrix:\n");
    for (int i = 0; i < 4; i++) {
        printf("%d\n", re2[i]);
    }

    return 0;
}