#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned int i, size;
    int *a = NULL, *b = NULL, *sum = NULL;

    printf("Enter size of array: ");
    scanf("%u", &size);

    a = (int *)calloc(size, sizeof(int));
    b = (int *)calloc(size, sizeof(int));
    sum = (int *)calloc(size, sizeof(int));

    printf("\nEnter elements for 1st array:\n");
    for (i = 0; i < size; i++)
    {
        printf("Enter element %u: ", i + 1);
        scanf("%d", &a[i]);

        sum[i] = a[i];
    }

    printf("\nEnter elements for 2nd array:\n");
    for (i = 0; i < size; i++)
    {
        printf("Enter element %u: ", i + 1);
        scanf("%d", &b[i]);

        sum[i] += b[i];
    }

    printf("\nSum of the elements are:\n");
    for (i = 0; i < size; i++)
        printf("%d + %d = %d\n", a[i], b[i], sum[i]);

    free(a);
    free(b);
    free(sum);

    return 0;
}
