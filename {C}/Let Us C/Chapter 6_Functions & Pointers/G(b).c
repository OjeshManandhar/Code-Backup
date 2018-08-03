#include <stdio.h>
#include <stdlib.h>

void calc(int,float,float,float,float *,float *);
int main()
{
    int t,t1,t2,t3;
    float a,b,c,avg,per;
    printf("Enter the marks of 3 subjects.\n");
    printf("Subject 1: ");
    scanf("%f",&a);
    printf("Subject 2: ");
    scanf("%f",&b);
    printf("Subject 3: ");
    scanf("%f",&c);
    printf("Enter the full marks of these subjects.\n");
    printf("Subject 1: ");
    scanf("%d",&t1);
    printf("Subject 2: ");
    scanf("%d",&t1);
    printf("Subject 3: ");
    scanf("%d",&t3);
    t=t1+t2+t3;
    calc(t,a,b,c,&avg,&per);
    printf("\nAverage: %.2f\n",avg);
    printf("Percentage: %.2f\n",per);
    return 0;
}

void calc(int t,float a,float b,float c,float *avg,float *per)
{
    *avg=(a+b+c)/3.0;
    *per=(a+b+c)*100.0/t;
}
