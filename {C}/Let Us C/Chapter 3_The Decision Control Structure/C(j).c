#include <stdio.h>
#include <stdlib.h>

int main()
{
    float x1,y1,x2,y2,x3,y3,area;
    printf("If A(x1,y1), B(x2,y2) and C(x3,y3) be three points in the graph, then\n");
    printf("Enter the Values of x1 and y1 [SEPERATED BYA TAB]:");
    scanf("%f%f",&x1,&y1);
    printf("Enter the Values of x2 and y2 [SEPERATED BYA TAB]:");
    scanf("%f%f",&x2,&y3);
    printf("Enter the Values of x3 and y3 [SEPERATED BYA TAB]:");
    scanf("%f%f",&x3,&y3);
    area=(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2))/2.0;
    if (area==0.0)
        printf("\nThe given 3 points LIES on the same straight line.\n");
    else
        printf("\nThe given 3 points DOES NOT LIE on the same straight line.\n");
    return 0;
}
