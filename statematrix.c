#include <stdio.h>
#include <stdlib.h>

struct twoarray {
    int row;
    int col;
    int **arr;
};

int main() {
    int i, j;

   
    struct twoarray *s = (struct twoarray *)malloc(sizeof(struct twoarray));

    printf("Enter the number of rows:");
    scanf("%d", &(s->row));

    printf("Enter the number of Columns:");
    scanf("%d", &(s->col));

    printf("Enter the elements of State matrix:\n");
    s->arr = (int **)malloc(sizeof(int *) * (s->row));
    for (i = 0; i < s->row; i++) {
        s->arr[i] = (int *)malloc(s->col * sizeof(int));
        if (s->arr[i] == NULL) {
            printf("Memory allocation failed!");
            return -1;
        }
    }

    for (i = 0; i < s->row; i++) {
        for (j = 0; j < s->col; j++) {
            scanf("%d", &(s->arr[i][j]));
        }
    }

   
    struct twoarray *transpose = (struct twoarray *)malloc(sizeof(struct twoarray));
    transpose->row = s->col;
    transpose->col = s->row;

    transpose->arr = (int **)malloc(sizeof(int *) * (transpose->row));
    for (i = 0; i < transpose->row; i++) {
        transpose->arr[i] = (int *)malloc(transpose->col * sizeof(int));
        if (transpose->arr[i] == NULL) {
            printf("Memory allocation failed!");
            return -1;
        }
    }

   
    for (i = 0; i < s->row; ++i) {
        for (j = 0; j < s->col; ++j) {
            transpose->arr[j][i] = s->arr[i][j];
        }
    }

    
    for (i = 0; i < transpose->row; ++i) {
        for (j = 0; j < transpose->col; ++j) {
            printf("%d\t", transpose->arr[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < s->row; i++) {
        free(s->arr[i]);
    }
    free(s->arr);
    free(s);

    for (i = 0; i < transpose->row; i++) {
        free(transpose->arr[i]);
    }
    free(transpose->arr);
    free(transpose);

    return 0;
}
