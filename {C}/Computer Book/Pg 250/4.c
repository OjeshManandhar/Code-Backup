#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n,*arr,i,sum=0;
    printf("Of how many numbers do you want to find sum of: ");
    scanf("%d",&n);
    arr=(int *)malloc(n*sizeof(int));
    printf("\n");
    for (i=0;i<n;i++)
    {
        printf("Enter the number no.%d: ",i+1);
        scanf("%d",&(*(arr+i)));
        sum+=*(arr+i);
    }
    printf("\nThe sum of these numbers is: %d.\n",sum);
    return 0;
}
