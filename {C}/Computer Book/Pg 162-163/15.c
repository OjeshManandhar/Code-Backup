#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i=1;
    float x,s;
    printf("Of how many numbers do you want of calculate sum of: ");
    scanf("%d",&n);
    level:
        printf("Enter any number no.%d: ",i);
        scanf("%f",&x);
        s+=x;
        i++;
        if (i<=n)
            goto level;
    printf("\nSum of all the number is %.2f.\n",s);
    return 0;
}
