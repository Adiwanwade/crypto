#include <stdio.h>
#include <stdlib.h>

struct array
{
    int size;
    int *arr;
};

struct array *encrypt(struct array *s, int Iv, int key)
{
    struct array *r = (struct array *)malloc(sizeof(struct array));
    r->size = s->size;
    r->arr = (int *)malloc(r->size * sizeof(int));
    int pc = Iv;

    for (int i = 0; i < s->size; i++)
    {
        r->arr[i] = (s->arr[i] + pc + key) % 25;
        pc = r->arr[i];
    }
    return r;
}

struct array *decrypt(struct array *s, int Iv, int key)
{
    struct array *r = (struct array *)malloc(sizeof(struct array));
    r->size = s->size;
    r->arr = (int *)malloc(r->size * sizeof(int));
    int pc = Iv;

    for (int i = 0; i < s->size; i++)
    {
        r->arr[i] = (s->arr[i] - pc - key + 25) % 25;
        pc = s->arr[i];
    }
    return r;
}

int main()
{
    struct array *s = (struct array *)malloc(sizeof(struct array));
    s->size = 2;
    s->arr = (int *)malloc(s->size * sizeof(int));
    s->arr[0] = 0;
    s->arr[1] = 1;
    int key = 10;

    struct array *r1 = encrypt(s, 2, key);
    struct array *r2 = decrypt(r1, 2, key);

    printf("The encrypted:\n");
    for (int i = 0; i < r1->size; i++)
    {
        printf("%d ", r1->arr[i]);
    }

    printf("\nThe Decrypted:\n");
    for (int i = 0; i < r2->size; i++)
    {
        printf("%d ", r2->arr[i]);
    }

    // Free allocated memory
    free(s->arr);
    free(s);
    free(r1->arr);
    free(r1);
    free(r2->arr);
    free(r2);

    return 0;
}
