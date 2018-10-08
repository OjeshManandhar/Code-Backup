#include <stdio.h>
#include <stdlib.h>

void msort(int *, int *, int, int);
void merge(int *, int *, int, int, int);

int main()
{
    unsigned int i, n;
    int *arr = NULL, *temp = NULL;

    printf("Enter size of array: ");
    scanf("%u", &n);

    arr = (int *)calloc(n, sizeof(int));
    temp = (int *)calloc(n, sizeof(int));

    printf("\nEnter the datas:\n");
    for (i = 0 ;i < n; i++)
    {
        printf("Enter element %u: ", i + 1);
        scanf("%d", &arr[i]);
    }

    msort(arr, temp, 0, n - 1);

    printf("\n\nThe sorted array is: ");
    for (i = 0; i < n; i++)
        printf("%d, ", arr[i]);
    printf("\b\b.\n\n");

    return 0;
}

void msort(int *x, int *temp, int left, int right)
{
    int mid;

    if (left < right)
    {
        mid = (right + left)/2;

        msort(x, temp, left, mid);
        msort(x, temp, mid + 1, right);

        merge(x, temp, left, mid + 1, right);
    }
}

void merge(int *x, int *temp, int left, int mid, int right)
{
    int i, lend, no_elem, tmpos;

    lend = mid - 1;
    tmpos = left;
    no_elem = right - left + 1;

    while ((left <= lend) && (mid <= right))
    {
        if (x[left] <= x[mid])
        {
            temp[tmpos] = x[left];
            tmpos++;
            left++;
        }
        else
        {
            temp[tmpos] = x[mid];
            tmpos++;
            mid++;
        }
    }

    while (left <= lend)
    {
        temp[tmpos] = x[left];
        left++;
        tmpos++;
    }

    while (mid <= right)
    {
        temp[tmpos] = x[mid];
        mid++;
        tmpos++;
    }

    for (i = 0; i < no_elem; i++)
    {
        x[right] = temp[right];
        right--;
    }
}
