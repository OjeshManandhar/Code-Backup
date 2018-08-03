#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void calc(int,int,int,int,int,int *,float *,float *);
int main()
{
    int a,b,c,d,e,sum;
    float avg,sd;
    printf("Enter 5 integers [SEPERATED BY A TAB]: ");
    scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
    calc(a,b,c,d,e,&sum,&avg,&sd);
    printf("\nSum: %d.\n",sum);
    printf("Average: %.2f.\n",avg);
    printf("Standard Deviation: %.2f.\n",sd);
    return 0;
}

void calc(int a,int b,int c,int d,int e,int *sum,float *avg,float *sd)
{
    float s1,s2;
    *sum=a+b+c+d+e;
    *avg=*sum/5.0;
    s1=pow(a-*avg,2)+pow(b-*avg,2)+pow(c-*avg,2)+pow(d-*avg,2)+pow(e-*avg,2);
    s2=s1/5.0;
    *sd=pow(s2,0.5);
}
