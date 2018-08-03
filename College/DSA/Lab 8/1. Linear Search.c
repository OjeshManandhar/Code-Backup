#include <stdio.h>
#include <stdlib.h>

void linear_search(int *arr, unsigned int n, int key)
{
    int i, flag = 0;
    int count = 1;

    for (i = 0; i < n; i++, count++)
        if (arr[i] == key)
        {
            flag = 1;
            break;
        }

    if (flag == 1)
        printf("\n%d found after %d iterations.\n", arr[i], count);
    else
        printf("\n%d not found.\n", key);
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

    printf("\nEnter data to search: ");
    scanf("%d", &key);

    linear_search(arr, n, key);

    return 0;
}
