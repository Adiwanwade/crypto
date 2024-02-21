
#include <stdio.h>
#include <stdlib.h>

struct array {
    int size;
    int *arr;
};

struct array* DAC(struct array *s, int l, int r) {
    struct array *minmax = (struct array*)malloc(sizeof(struct array));
    minmax->size = 2;
    minmax->arr = (int*)malloc(minmax->size * sizeof(int));

    int min, max;
    if (l == r) {
        minmax->arr[0] = s->arr[l];
        minmax->arr[1] = s->arr[r];
    } else if (l == r - 1) {
        if (s->arr[l] > s->arr[r]) {
            minmax->arr[0] = s->arr[r];
            minmax->arr[1] = s->arr[l];
        } else {
            minmax->arr[0] = s->arr[l];
            minmax->arr[1] = s->arr[r];
        }
    } else {
        int m = l + (r - l) / 2;

        struct array *minmax1 = DAC(s, l, m);
        struct array *minmax2 = DAC(s, m + 1, r);

        minmax->arr[0] = (minmax1->arr[0] < minmax2->arr[0]) ? minmax1->arr[0] : minmax2->arr[0];
        minmax->arr[1] = (minmax1->arr[1] > minmax2->arr[1]) ? minmax1->arr[1] : minmax2->arr[1];
    }
    return minmax;
}

int main() {
    int i = 0;
    struct array *s = (struct array*)malloc(sizeof(struct array));
    printf("Enter the size of array:");
    scanf("%d", &(s->size));
    s->arr = (int*)malloc(s->size * sizeof(int));
    printf("Enter the elements of array:\n");
    for (i = 0; i < s->size; i++) {
        scanf("%d", &(s->arr[i]));
    }

    struct array *minmax = DAC(s, 0, s->size - 1);
    printf("Minimum: %d\n", minmax->arr[0]);
    printf("Maximum: %d\n", minmax->arr[1]);

   
    free(s->arr);
    free(s);
    free(minmax->arr);
    free(minmax);

    return 0;
}
