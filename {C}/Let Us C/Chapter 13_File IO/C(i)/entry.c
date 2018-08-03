#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

struct date
{
    int d,m,y;
};

struct employee
{
    int empcode;
    char empname[20];
    struct date join_date;
    float salary;
}data;

int main()
{
    FILE *fp;
    int i,n;
    char c;
    fp=fopen("file_C(i).dat","ab");
    if (fp==NULL)
    {
        perror("Can't open file.");
        exit(EXIT_FAILURE);
    }
    do
    {
        do
        {
            printf("Enter the EMPLOYEE CODE of the employee [6 DIGITS]: ");
            scanf("%d",&data.empcode);
            n=data.empcode;
            for (i=0;n!=0;i++)
                n/=10;
        }while(i!=6);
        printf("Enter the NAME of the employee [MAX 19 CHARACTERS]: ");
        fflush(stdin);
        gets(data.empname);
        printf("Enter the JOIN DATE of the employee [DD/MM/YYYY] [SEPARATED BY A TAB]: ");
        scanf("%d%d%d",&data.join_date.d,&data.join_date.m,&data.join_date.y);
        printf("Enter the SALARY of the employee: ");
        scanf("%f",&data.salary);
        fwrite(&data,sizeof(struct employee),1,fp);
        printf("\nEnter another data [Y/N]: ");
        fflush(stdin);
        c=getchar();
        printf("\n");
    }while (c=='y' || c=='Y');
    fclose(fp);
    return 0;
}
