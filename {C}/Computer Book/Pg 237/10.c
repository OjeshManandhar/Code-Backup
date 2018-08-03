#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    struct school
    {
        int reg;
        char name[20];
        int year;
        int sub1;
        int sub2;
        int sub3;
        int sub4;
        int sub5;
    }*data;
    int n,i,l;
    printf("Enter the number of students whose data is to entered: ");
    scanf("%d",&n);
    data=(struct school *)malloc(n*sizeof(struct school));
    for (i=0;i<n;i++)
    {
        printf("\n");
        do
        {
            printf("Enter Reg. No. of student no.%d [030099-060099]: ",i+1);
            scanf("%d",&data[i].reg);
        }while(data[i].reg<30099 || data[i].reg>60099);
        fflush(stdin);
        printf("Enter the Name of the student no.%d: ",i+1);
        gets(data[i].name);
        do
        {
            printf("Enter Year of joining of student no.%d [98-99]: ",i+1);
            scanf("%d",&data[i].year);
        }while(data[i].year<98 || data[i].year>99);
        do
        {
            printf("Enter marks of Sub1 of student no.%d [0-100]: ",i+1);
            scanf("%d",&data[i].sub1);
        }while(data[i].sub1<0 || data[i].sub1>100);
        do
        {
            printf("Enter marks of Sub2 of student no.%d [0-100]: ",i+1);
            scanf("%d",&data[i].sub2);
        }while(data[i].sub2<0 || data[i].sub2>100);
        do
        {
            printf("Enter marks of Sub3 of student no.%d [0-100]: ",i+1);
            scanf("%d",&data[i].sub3);
        }while(data[i].sub3<0 || data[i].sub3>100);
        do
        {
            printf("Enter marks of Sub4 of student no.%d [0-100]: ",i+1);
            scanf("%d",&data[i].sub4);
        }while(data[i].sub4<0 || data[i].sub4>100);
        do
        {
            printf("Enter marks of Sub5 of student no.%d [0-100]: ",i+1);
            scanf("%d",&data[i].sub5);
        }while(data[i].sub5<0 || data[i].sub5>100);
    }
    printf("\nAll data(s) have been entered. Press any key.");
    getch();
    system("cls");
    printf("Reg. No.  Name\tYear\tSub1\tSub2\tSub3\tSub4\tSub5\n");
    for (i=0;i<n;i++)
        printf("0%d\t  %s\t%d\t%d\t%d\t%d\t%d\t%d\n",data[i].reg,data[i].name,data[i].year,data[i].sub1,data[i].sub2,data[i].sub3,data[i].sub4,data[i].sub5);
    return 0;
}
