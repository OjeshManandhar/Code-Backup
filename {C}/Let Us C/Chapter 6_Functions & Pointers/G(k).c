#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float distance(int,int,int,int);
float area(int,int,int,int,int,int);
int check(int,int,int,int,int,int,int,int);
int main()
{
    int x1,y1,x2,y2,x3,y3,x,y,c;
    float a;
    printf("If A(x1,y1), B(x2,y2) and C(x3,y3) be the 3 vertices of the triangle ABC,then\n");
    printf("Enter the values of x1 and y1 [SEPERATED BY A TAB]: ");
    scanf("%d%d",&x1,&y1);
    printf("Enter the values of x2 and y2 [SEPERATED BY A TAB]: ");
    scanf("%d%d",&x2,&y2);
    printf("Enter the values of x3 and y3 [SEPERATED BY A TAB]: ");
    scanf("%d%d",&x3,&y3);
    printf("\nIf X(x,y) be any point, then\n");
    printf("Enter the values of x and y [SEPERATED BY A TAB]: ");
    scanf("%d%d",&x,&y);
    a=area(x1,y1,x2,y2,x3,y3);
    c=check(x1,y1,x2,y2,x3,y3,x,y);
    printf("\nArea of the triangle is: %.2f.\n",a);
    if (c==1)
        printf("\nThe point X(%d,%d) lies in the triangle ABC.\n",x,y);
    else
        printf("\nThe point X(%d,%d) does not lies in the triangle ABC.\n",x,y);
    return 0;
}

//question ma distanceko function vanekole matra yo function banako|
//natra vane yo function ko kam xaina|
float distance(int x1,int y1,int x2,int y2)
{
    float a,b;
    a=pow(x2-x1,2);
    b=pow(y2-y1,2);
    return pow(a+b,0.5);
}

//yo functionle exact answer didaina|
float area (int x1,int y1,int x2,int y2,int x3,int y3)
{
    float ab,bc,ca,s,ans;
    ab=distance(x1,y1,x2,y2);
    bc=distance(x2,y2,x3,y3);
    ca=distance(x3,y3,x1,y1);
    s=(ab+bc+ca)/2;
    ans=s*(s-ab)*(s-bc)*(s-ca);
    return pow(ans,0.5);
}

int check(int x1,int y1,int x2,int y2,int x3,int y3,int x,int y)
{
    float abc,abx,bcx,cax;
    abc=area(x1,y1,x2,y2,x3,y3);
    abx=area(x1,y1,x2,y2,x,y);
    bcx=area(x2,y2,x3,y3,x,y);
    cax=area(x3,y3,x1,y1,x,y);
    if (abx+bcx+cax==abc)
        return 1;
    else
        return 0;
}
