#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i;
    const float pi=3.141592653589793;
    float r;
    printf("Of how many circle(s) do you want to calculate area: ");
    scanf("%d",&n);
    for (i=1;i<=n;i++)
    {
        printf("\nEnter radius of circle no.%d: ",i);
        scanf("%f",&r);
        printf("The Area of circle no.%d is %.2f.\n",i,pi*r*r);
    }
    return 0;
}
