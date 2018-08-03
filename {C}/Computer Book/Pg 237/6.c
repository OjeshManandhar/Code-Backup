#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    struct student
    {
        char *name;
        int roll;
        float sub1;
        float sub2;
        float sub3;
        float sub4;
        float sub5;
    }*data;
    int n,i,l;
    float t;
    char ch[50];
    do
    {
        system("cls");
        printf("Enter the total number of data [MAX=10]: ");
        scanf("%d",&n);
    }while(n>10);
    data=(struct student*)malloc(n*sizeof(struct student));
    for (i=0;i<n;i++)
    {
        printf("\n");
        fflush(stdin);
        printf("Enter the FULL NAME of student no.%d: ",i+1);
        gets(ch);
        l=strlen(ch)+1;
        data[i].name=(char *)malloc(l*sizeof(char));
        strcpy(data[i].name,ch);
        printf("Enter the ROLL of student no.%d: ",i+1);
        scanf("%d",&data[i].roll);
        printf("Enter the marks obtained in SUB1 by student no.%d: ",i+1);
        scanf("%f",&data[i].sub1);
        printf("Enter the marks obtained in SUB2 by student no.%d: ",i+1);
        scanf("%f",&data[i].sub2);
        printf("Enter the marks obtained in SUB3 by student no.%d: ",i+1);
        scanf("%f",&data[i].sub3);
        printf("Enter the marks obtained in SUB4 by student no.%d: ",i+1);
        scanf("%f",&data[i].sub4);
        printf("Enter the marks obtained in SUB5 by student no.%d: ",i+1);
        scanf("%f",&data[i].sub5);
    }
    printf("\nAll data(s) have been entered. Press any key.");
    getch();
    system("cls");
    printf("Name\t\tRoll\tTotal\n");
    for (i=0;i<n;i++)
    {
        t=data[i].sub1+data[i].sub2+data[i].sub3+data[i].sub4+data[i].sub5*1.0;
        printf("%s\t\t%d\t%.2f\n",data[i].name,data[i].roll,t);
    }
    return 0;
}
