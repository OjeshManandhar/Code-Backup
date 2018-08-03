#include <stdio.h>
#include <stdlib.h>

int main()
{
    float a,b,c,d,e,agg,per;
    printf("Input marks of FIVE different subjects [SEPERATED BY A TAB]: ");
    scanf("%f%f%f%f%f",&a,&b,&c,&d,&e);
    agg=a+b+c+d+e;
    per=agg/5;
    printf("\nAggregate: %.1f\n",agg);
    printf("Percentage: %.1f\n",per);
    return 0;
}
