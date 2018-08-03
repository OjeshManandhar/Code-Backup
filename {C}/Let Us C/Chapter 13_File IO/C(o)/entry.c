#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#include <lower.h>

struct employee
{
    int empno;
    char name[30];
    int basic, grade;
}*data;

int compare(const void *elem1, const void *elem2)
{
    struct employee *x=(struct employee *)elem1;
    struct employee *y=(struct employee *)elem2;

    return (x->empno - y->empno);
}

char getkey()
{
    int ch;
    ch=getch();
    if (ch==224)
    {
        ch=getch();
        return ch;
    }
    return ch;
}

int main()
{
    FILE *fp;
    int i,total=0,flag,x;
    char c;
    fp=fopen("EMPLOYEE.dat","rb+");
    if (fp==NULL)
    {
        fp=fopen("EMPLOYEE.dat","ab+");
        if (fp==NULL)
        {
            perror("Can't open file");
            exit(EXIT_FAILURE);
        }
    }
    while (1)
    {
        total++;
        i=total-1;
        data=(struct employee *)realloc(data,total*sizeof(struct employee));
        if (fread(&data[i],sizeof(struct employee),1,fp)!=1)
            break;
    }
    total--;
    if (total!=0)
    {
        puts("Data(s) which are already in file:\n");
        printf("empno \t %-29s \t Basic \t Grade\n","Name");
        for (i=0;i<total;i++)
            printf("%-5d \t %-29s \t %-5d \t %-5d\n",data[i].empno,data[i].name,data[i].basic,data[i].grade);

        printf("\nPress Esc to exit or any other key to continue....");
        c=getkey();
        if (c==27)
        {
            free(data);
            fclose(fp);
            exit(EXIT_SUCCESS);
        }
        fclose(fp);
        remove("EMPLOYEE.dat");
        fp=fopen("EMPLOYEE.dat","wb+");
        system("cls");
    }
    do
    {
        flag=0;
        total++;
        i=total-1;
        data=(struct employee *)realloc(data,total*sizeof(struct employee));
        printf("Enter the empno of the employee: ");
        scanf("%d",&data[i].empno);
        for (x=0;x<i;x++)
            if (data[x].empno==data[i].empno)
            {
                flag=1;
                total--;
                break;
            }
        if (flag==1)
            puts("\tData is already present.");
        else
        {
            do
            {
                printf("Enter the NAME of the employee [MAX 29 CHARACTERS]: ");
                fflush(stdin);
                gets(data[i].name);
            }while (strlen(data[i].name)>29);
            printf("Enter the BASIC SALARY of the employee: ");
            scanf("%d",&data[i].basic);
            printf("Enter the GRADE of the employee: ");
            scanf("%d",&data[i].grade);
        }
        printf("\n");
        do
        {
            printf("Add another data [Y/N]: ");
            fflush(stdin);
            c=getchar();
            c=clwr(c);
        }while (c!='n' && c!='y');
        printf("\n");
    }while (c=='y');
    puts("All data(s) have been entered.");
    printf("Press any key to continue...");
    getch();
    system("cls");
    puts("The data(s) which are already in file as well as newly entered data(s):\n");
    printf("empno \t %-29s \t Basic \t Grade\n","Name");
    for (i=0;i<total;i++)
        printf("%-5d \t %-29s \t %-5d \t %-5d\n",data[i].empno,data[i].name,data[i].basic,data[i].grade);
    qsort(data,total,sizeof(struct employee),compare);
    puts("\nThe data will be written to the file in ascending order of the \"empno\" as:\n");
    printf("empno \t %-29s \t Basic \t Grade\n","Name");
    for (i=0;i<total;i++)
    {
        printf("%-5d \t %-29s \t %-5d \t %-5d\n",data[i].empno,data[i].name,data[i].basic,data[i].grade);
        fwrite(&data[i],sizeof(struct employee),1,fp);
    }
    free(data);
    fclose(fp);
    return 0;
}
