#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num[25],i,s,j,c=1;
    for (i=0;i<25;i++)
    {
        printf("Enter %d number: ",i+1);
        scanf("%d",&num[i]);
    }
    printf("\nEnter the number you want to search: ");
    scanf("%d",&s);
    for (i=0;i<25;i++)
        if (num[i]==s)
        {
            for (j=i+1;j<25;j++)
                if (num[j]==s)
                    c++;
            printf("\nNumber of times %d is repeated is: %d\n",s,c);
            break;
        }

    return 0;
}
