#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float a[]={137.4,155.2,149.3,160.0,155.6,149.7};
    float b[]={80.9,92.62,97.93,100.25,68.95,120.0};
    float angle[]={0.78,0.89,1.35,9.00,1.25,1.75};//the angle are in DEGREE
    float area[6],max=0.0;
    int i,x;
    printf("The values of sides and angle(in DEGREES) of triangle are:\na\tb\tangle\n");
    for (i=0;i<6;i++)
    {
        printf("%.2f\t%.2f\t%.2f\n",a[i],b[i],angle[i]);
        angle[i]=angle[i]*3.141592653589793/180;//Converting angles in DEGREE into RADIAN
        area[i]=a[i]*b[i]*sin(angle[i])/2.0;//Sin() takes values of angles in RADIAN
        if (area[i]>max)
        {
            x=i;
            max=area[i];
        }
    }
    printf("\nGreatest area is: %.2f.\n",max);
    angle[x]=angle[x]*180/3.141592653589793;
    printf("Of the triangle with sides %.2f & %.2f with angle %.2f\n",a[x],b[x],angle[x]);
    return 0;
}
