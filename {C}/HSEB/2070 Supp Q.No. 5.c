#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fp;
    struct student
    {
        char name[25];
        int age;
        int roll;
    }data;
    char c;
    fp=fopen("xyz_HSEB 2070 Supp Q.No. 5.dat","ab+");
    if (fp==NULL)
    {
        printf("ab+ failed\n");
        fp=fopen("xyz_HSEB 2070 Supp Q.No. 5.dat","wb+");
        if (fp==NULL)
        {
            printf("Can't open file.\n");
            exit(1);
        }
    }
    do
    {
        fflush(stdin);
        printf("Enter the NAME of the student [MAX 25 CHARACTERS]: ");
        gets(data.name);
        printf("Enter the AGE of the student: ");
        scanf("%d",&data.age);
        printf("Enter the ROLL of the student: ");
        scanf("%d",&data.roll);
        fwrite(&data,sizeof(data),1,fp);
        fflush(stdin);
        printf("\nDo you want to another record [Y/N]: ");
        c=getchar();
        printf("\n");
    }while (c=='y' || c=='Y');
    rewind(fp);
    system("cls");
    printf("The data in this file are(is):\n");
    printf("%-20s %-5s %-5s\n","Name","Age","Roll");
    while (fread(&data,sizeof(data),1,fp)==1)
        printf("%-20s %-5d %-5d\n",data.name,data.age,data.roll);
    fclose(fp);
    return 0;
}
