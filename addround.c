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

    printf("Enter the elements of input matrix:\n");
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


    struct twoarray *s1 = (struct twoarray *)malloc(sizeof(struct twoarray));

    printf("Enter the number of rows:");
    scanf("%d", &(s1->row));

    printf("Enter the number of Columns:");
    scanf("%d", &(s1->col));

    printf("Enter the elements of key matrix:\n");
    s1->arr = (int **)malloc(sizeof(int *) * (s1->row));
    for (i = 0; i < s1->row; i++) {
        s1->arr[i] = (int *)malloc(s1->col * sizeof(int));
        if (s1->arr[i] == NULL) {
            printf("Memory allocation failed!");
            return -1;
        }
    }

    for (i = 0; i < s1->row; i++) {
        for (j = 0; j < s1->col; j++) {
            scanf("%d", &(s1->arr[i][j]));
        }
    }
   
    struct twoarray *output = (struct twoarray *)malloc(sizeof(struct twoarray));
    output->row = s->col;
    output->col = s->row;

    output->arr = (int **)malloc(sizeof(int *) * (output->row));
    for (i = 0; i < output->row; i++) {
        output->arr[i] = (int *)malloc(output->col * sizeof(int));
        if (output->arr[i] == NULL) {
            printf("Memory allocation failed!");
            return -1;
        }
    }

   
    for (i = 0; i < s->row; ++i) {
        for (j = 0; j < s->col; ++j) {
            output->arr[j][i] = (s->arr[i][j])^(s1->arr[i][j]);
        }
    }

    
    for (i = 0; i < output->row; ++i) {
        for (j = 0; j < output->col; ++j) {
            printf("%d\t", output->arr[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < s->row; i++) {
        free(s->arr[i]);
    }
    free(s->arr);
    free(s);

    for (i = 0; i < output->row; i++) {
        free(output->arr[i]);
    }
    free(output->arr);
    free(output);

    return 0;
}
