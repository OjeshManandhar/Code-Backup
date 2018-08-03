#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,x;
    float *n;
    printf("Enter the number of students: ");
    scanf("%d",&x);
    printf("\n");
    n=(float *)malloc(x);
    for (i=0;i<x;i++)
    {
        printf("Enter the marks of student no.%d: ",i+1);
        scanf("%f",&n[i]);
        n[i]+=15.0;
    }
    printf("\nThe marks of the students when 15 grace marks is added are:\n");
    for (i=0;i<x;i++)
        printf("%.2f ",n[i]);
    return 0;
}
