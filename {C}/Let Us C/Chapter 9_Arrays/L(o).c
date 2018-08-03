#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float x[]={34.22,39.87,41.85,43.23,40.06,53.29,53.29,54.14,49.12,40.71,55.15};
    float y[]={102.43,100.93,97.43,97.81,98.32,98.32,100.07,97.08,91.59,94.85,94.65};
    float sum_x=0,sum_y=0,sum_xy=0,sum_x2=0,sum_y2=0,r1,rx,ry,r;
    int i;
    printf("The values of (x,y) are:\nx\ty\n");
    for (i=0;i<11;i++)
    {
        printf("%.2f\t%.2f\n",x[i],y[i]);
        sum_x+=x[i];
        sum_y+=y[i];
        sum_xy+=(x[i]*y[i]);
        sum_x2+=(x[i]*x[i]);
        sum_y2+=(y[i]*y[i]);
    }
    r1=sum_xy-(sum_x*sum_y);
    rx=11.0*sum_x2-sum_x*sum_x;
    ry=11.0*sum_y2-sum_y*sum_y;
    r=r1/pow(rx*ry,0.5);
    printf("\nThe correlation coefficient of the given values of (x,y) is %.3f.\n",r);
    return 0;
}
