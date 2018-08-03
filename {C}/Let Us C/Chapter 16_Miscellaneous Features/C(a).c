#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

float add(int a, int b)
{
    return (float)a+b;
}

float subtract(int a, int b)
{
    return (float)a-b;
}

float multiply(int a, int b)
{
    return (float)a*b;
}

float divide(int a, int b)
{
    return (float)a/b;
}

int main()
{
    int i,a,b;
    float (*func_ptr[4])(int,int);

    func_ptr[0]=add;
    func_ptr[1]=subtract;
    func_ptr[2]=multiply;
    func_ptr[3]=divide;

    printf("Enter two integers [SEPARATED BY A TAB]: ");
    scanf("%d %d",&a,&b);

    printf("\nFor the values %d and %d,\n",a,b);
    for (i=0;i<4;i++)
        printf("the result of func_ptr[%d] is: %.2f\n",i,func_ptr[i](a,b));
    return 0;
}
