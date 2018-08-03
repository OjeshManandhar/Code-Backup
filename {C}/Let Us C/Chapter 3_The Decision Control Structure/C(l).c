#include <stdio.h>
#include <stdlib.h>

int main()
{
    float x,y;
    printf("If A(x,y) be a point on the graph, then\n");
    printf("Enter the value of x:");
    scanf("%f",&x);
    printf("Enter the value of y:");
    scanf("%f",&y);
    if (x==0 && y==0)
        printf("\nThe point A(%.2f,%.2f) lies on the origin.\n",x,y);
    else if (x==0)
        printf("\nThe point A(%.2f,%.2f) lies on the y-axis.\n",x,y);
    else if (y==0)
        printf("\nThe point A(%.2f,%.2f) lies on the x-axis.\n",x,y);
    return 0;
}
