#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#include <upper.h>

struct employee
{
    int emp_no;
    int size;
    char *name;
    char sex;
    float salary;
}*data;

void add_record(struct employee *data, int n, FILE *fp)
{
    int i;
    fclose(fp);
    remove("file_C(m).dat");
    fp=fopen("file_C(m).dat","wb+");
    for (i=0;i<n;i++)
    {
        fwrite(&data[i].emp_no,sizeof(int),1,fp);
        fwrite(&data[i].size,sizeof(int),1,fp);
        fwrite(data[i].name,data[i].size*sizeof(char),1,fp);
        //fwrite(data[i].name,sizeof(char),data[i].size,fp);
        fwrite(&data[i].sex,sizeof(char),1,fp);
        fwrite(&data[i].salary,sizeof(float),1,fp);
    }
}

int main()
{
    FILE *fp;
    int i,total=0,count=0,x,choice,flag,change_flag;
    char ch[31],c;
    fp=fopen("file_C(m).dat","rb+");
    if (fp==NULL)
    {
        fp=fopen("file_C(m).dat","ab+");
        if (fp==NULL)
        {
            perror("Can't open file");
            exit(EXIT_FAILURE);
        }
    }
    while (fread(&x,sizeof(int),1,fp)==1)
    {
        total++;
        i=total-1;
        data=(struct employee *)realloc(data,total*sizeof(struct employee));
        data[i].emp_no=x;
        fread(&data[i].size,sizeof(int),1,fp);
        data[i].name=(char *)malloc(data[i].size*sizeof(char));
        fread(data[i].name,data[i].size*sizeof(char),1,fp);
        //fread(data[i].name,sizeof(char),data[i].size,fp);
        fread(&data[i].sex,sizeof(char),1,fp);
        fread(&data[i].salary,sizeof(float),1,fp);
        if (data[i].salary==0)
            count++;
    }
    while (1)
    {
        system("cls");
        puts("\tMAIN MENU\n");
        puts("Choose an option.");
        puts("1. Add Records.");
        puts("2. List Records.");
        puts("3. Delete Records.");
        puts("4. Edit Gross Salary.");
        puts("5. Exit.");
        do
        {
            printf("Enter your choice: ");
            scanf("%d",&choice);
        }while(choice<1 || choice>5);
        system("cls");
        switch(choice)
        {
        case 1:
            puts("\tADDING RECORDS");
            do
            {
                total++;
                i=total-1;
                data=(struct employee *)realloc(data,total*sizeof(struct employee));
                printf("\nEMPLOYEE NUMBER: %d\n",total);
                data[i].emp_no=total;
                do
                {
                    printf("Enter the NAME of the employee [MAX 31 CHARACTERS]: ");
                    fflush(stdin);
                    gets(ch);
                    data[i].size=strlen(ch)+1;
                }while (data[i].size>31);
                data[i].name=(char *)malloc(data[i].size*sizeof(char));
                strcpy(data[i].name,ch);
                do
                {
                    printf("Enter the SEX of the employee [M/F]: ");
                    fflush(stdin);
                    data[i].sex=getchar();
                    data[i].sex=cupr(data[i].sex);
                }while (data[i].sex!='M' && data[i].sex!='F');
                do
                {
                    printf("Enter the GROSS SALARY of the employee: ");
                    scanf("%f",&data[i].salary);
                }while (data[i].salary<=0);
                printf("\n");
                do
                {
                    printf("Add another record [Y/N]: ");
                    fflush(stdin);
                    c=getchar();
                    c=cupr(c);
                }while (c!='Y' && c!='N');
            }while (c=='Y');
            add_record(data,total,fp);
            puts("\nAll data(s) have been entered.");
            printf("Press any key to go back to main menu...");
            getch();
            break;
        case 2:
            puts("\t\t\tLIST OF RECORDS\n");
            if (total-count==0)
            {
                puts("NO DATA FOUND");
                printf("Press any key to go back to main menu...");
            }
            else
            {
                printf("No.\t %-30s \t %-6s \t Salary\n","Name","Sex");
                for (i=0;i<total;i++)
                    if (data[i].salary!=0)
                    {
                        printf("%-3.2d \t %-30s \t ",data[i].emp_no,data[i].name);
                        if (data[i].sex=='M')
                            printf("%-6s \t ","Male");
                        else
                            printf("%-6s \t ","Female");
                        printf("Rs. %.2f\n",data[i].salary);
                    }
                puts("\nAll data(s) have been displayed.");
                printf("Press any key to go back to main menu...");
            }
            getch();
            break;
        case 3:
            change_flag=0;
            puts("\tDELETING RECORDS");
            if (total-count==0)
            {
                puts("\nNO DATA FOUND");
                printf("Press any key to go back to main menu...");
            }
            else
            {
                do
                {
                    flag=0;
                    printf("\nEnter employee no.: ");
                    scanf("%d",&choice);
                    for (i=0;i<total;i++)
                        if (data[i].emp_no==choice && data[i].salary!=0)
                        {
                            flag=1;
                            break;
                        }
                    if (flag==0)
                        puts("\tNO DATA FOUND");
                    else
                    {
                        puts("Employee Information:");
                        printf("NO. = %-3.2d \t NAME = %-30s\n",data[i].emp_no,data[i].name);
                        if (data[i].sex=='M')
                            printf("SEX = %-6s \t ","Male");
                        else
                            printf("SEX = %-6s \t ","Female");
                        printf("SALARY = Rs. %.2f\n",data[i].salary);
                        printf("Rs. %.2f\n",data[i].salary);
                        do
                        {
                            printf("DELETE this record [Y/N]: ");
                            fflush(stdin);
                            c=getchar();
                            c=cupr(c);
                        }while (c!='Y' && c!='N');
                        if (c=='Y')
                        {
                            change_flag=1;
                            data[i].salary=0;
                            count++;
                        }
                    }
                    printf("\n");
                    do
                    {
                        printf("Delete another record [Y/N]: ");
                        fflush(stdin);
                        c=getchar();
                        c=cupr(c);
                    }while (c!='Y' && c!='N');
                }while (c=='Y' && total-count!=0);
                add_record(data,total,fp);
                if (total-count==0 && c=='Y')
                    puts("\nNO DATA FOUND.");
                else if (change_flag==1)
                    puts("\nAll these data(s) have been deleted.");
                else
                    printf("\n");
                printf("Press any key to go back to main menu...");
            }
            getch();
            break;
        case 4:
            change_flag=0;
            puts("\tEDITING GROSS SALARY");
            if (total-count==0)
            {
                puts("\nNO DATA FOUND");
                printf("Press any key to go back to main menu...");
            }
            else
            {
                do
                {
                    flag=0;
                    printf("\nEnter employee no.: ");
                    scanf("%d",&choice);
                    for (i=0;i<total;i++)
                        if (data[i].emp_no==choice && data[i].salary!=0)
                        {
                            flag=1;
                            break;
                        }
                    if (flag==0)
                        puts("\tNO DATA FOUND");
                    else
                    {
                        puts("Employee Information:");
                        printf("NO. = %-3.2d \t NAME = %-30s\n",data[i].emp_no,data[i].name);
                        if (data[i].sex=='M')
                            printf("SEX = %-6s \t ","Male");
                        else
                            printf("SEX = %-6s \t ","Female");
                        printf("SALARY = Rs. %.2f\n",data[i].salary);
                        do
                        {
                            printf("Change GROSS SALARY this record [Y/N]: ");
                            fflush(stdin);
                            c=getchar();
                            c=cupr(c);
                        }while (c!='Y' && c!='N');
                        if (c=='Y')
                        {
                            change_flag=1;
                            printf("\n");
                            do
                            {
                                printf("Enter the NEW GROSS SALARY of the employee: ");
                                scanf("%f",&data[i].salary);
                            }while (data[i].salary<=0);
                        }
                    }
                    printf("\n");
                    do
                    {
                        printf("EDIT another record [Y/N]: ");
                        fflush(stdin);
                        c=getchar();
                        c=cupr(c);
                    }while (c!='Y' && c!='N');
                }while (c=='Y');
                add_record(data,total,fp);
                if (change_flag==1)
                    puts("\nAll these data(s) have been edited.");
                else
                    printf("\n");
                printf("Press any key to go back to main menu...");
            }
            getch();
            break;
        case 5:
            puts("PROGRAM TERMINATED.");
            printf("Press any key...");
            getch();
            free(data);
            fclose(fp);
            exit(EXIT_SUCCESS);
        }
    }
	free(data);
	fclose(fp);
    return 0;
}
