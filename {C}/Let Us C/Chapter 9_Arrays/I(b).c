#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("This is a program to check if arr[0]=arr[n-1], arr[1]=arr[n-2] and so on.\n");
    int n;
    printf("Enter the number of elements of your array (n): ");
    scanf("%d",&n);
    int arr[n],i;
    for(i=0;i<n;i++)
    {
        printf("Enter element no. %d: ",i+1);
        scanf("%d",&arr[i]);
    }
    for (i=0;i<n/2;i++)
        if (arr[i]!=arr[n-(i+1)])
        {
            printf("\nThe array has FAILED the test.\n");
            exit(1);
        }
    printf("\nThe array has PASSED the test.\n");
    return 0;
}
