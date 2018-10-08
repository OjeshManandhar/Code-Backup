#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

int main()
{
    unsigned int i, j, n, pos;
    int *arr = NULL;

    printf("Enter size of array: ");
    scanf("%u", &n);

    arr = (int *)calloc(n, sizeof(int));

    printf("\nEnter the datas:\n");
    for (i = 0 ;i < n; i++)
    {
        printf("Enter element %u: ", i + 1);
        scanf("%d", &arr[i]);
    }

    for (i = n - 1; i > 0; i--)
    {
        pos = 0;
        for (j = 0; j <= i; j++)
            if (arr[pos] < arr[j])
                pos = j;

        if (i != pos)
            swap(&arr[i], &arr[pos]);
    }

    printf("\n\nThe sorted array is: ");
    for (i = 0; i < n; i++)
        printf("%d, ", arr[i]);
    printf("\b\b.\n\n");

    return 0;
}
