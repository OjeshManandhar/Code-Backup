#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int point[10][2],i,j,x1,y1,x2,y2,temp1,temp2;
    float distance,sum=0;
    for (i=0;i<10;i++)
    {
        printf("Enter the co-ordinate of point(x,y) no. %d[SEPERATED BY A TAB]: ",i+1);
        scanf("%d%d",&point[i][0],&point[i][1]);
    }
    printf("\nThe points you have entered are:\nx , y\n");
    for (i=0;i<10;i++)
        printf("%d , %d\n",point[i][0],point[i][1]);
    for (i=0;i<9;i++)
    {
        x1=point[i][0];
        x2=point[i][1];
        y1=point[i+1][0];
        y2=point[i+1][1];
        temp1=pow(x2-x1,2);
        temp2=pow(y2-y1,2);
        distance=pow(temp1+temp2,0.5);
        sum+=distance;
    }
    printf("\nThe distance between the first and the last point is: %.2f.\n",sum);
    return 0;
}
