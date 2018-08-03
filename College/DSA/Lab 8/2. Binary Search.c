#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    int *A = (int *)a;
    int *B = (int *)b;
    return *A - *B;
}

void binary_search(int *arr, int beg, int end, int item)
{
    int mid;
    int count = 1;

    mid = (beg + end)/2;

    while ((beg <= end) && (item != arr[mid]))
    {
        if (item < arr[mid])
            end = mid - 1;
        else
            beg = mid + 1;

        mid = (beg + end)/2;

        count++;
    }

    if (item == arr[mid])
        printf("\n%d found after %d iterations.\n", arr[mid], count);
    else
        printf("\n%d not found.\n", item);
}

int main()
{
    unsigned int i, n;
    int key;
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

    qsort(arr, n, sizeof(int), compare);

    printf("\n\nThe sorted array is: ");
    for (i = 0; i < n; i++)
        printf("%d, ", arr[i]);
    printf("\b\b.\n\n");

    printf("Enter data to search: ");
    scanf("%d", &key);

    binary_search(arr, 0, n - 1, key);

    return 0;
}
