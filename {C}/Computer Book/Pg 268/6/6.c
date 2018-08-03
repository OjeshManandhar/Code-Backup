#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#include <upper.h>

struct student
{
    int size;
    char *name;
    int age;
}data;

int main()
{
    FILE *fp;
    char c,ch[31];
    fp=fopen("file_6.dat","rb+");
    if (fp==NULL)
    {
        fp=fopen("file_6.dat","ab+");
        if (fp==NULL)
        {
            perror("Can't open file");
            exit(EXIT_FAILURE);
        }
    }
    do
    {
        do
        {
            printf("Enter the name of the student [max 30 characters]: ");
            fflush(stdin);
            gets(ch);
            data.size=strlen(ch)+1;
        }while (data.size>31);
        data.name=(char *)malloc(data.size*sizeof(char));
        strcpy(data.name,ch);
        printf("Enter the age of the student: ");
        scanf("%d",&data.age);

        fwrite(&data.size,sizeof(int),1,fp);
        fwrite(data.name,data.size*sizeof(char),1,fp);
        fwrite(&data.age,sizeof(int),1,fp);

        printf("\n");
        do
        {
            printf("Add another record [Y/N]: ");
            fflush(stdin);
            c=cupr(getchar());
        }while (c!='Y' && c!='N');
        printf("\n");
    }while (c=='Y');
    puts("All data(s) has been entered");
    printf("Press any key to continue...");
    getch();
    system("cls");
    rewind(fp);
    printf("%ld\n",ftell(fp));
    puts("The list of data(s) you have just entered is:\n");
    printf("%-30s \t Age\n","Name");
    while (fread(&data.size,sizeof(int),1,fp)==1)
    {
        data.name=(char *)malloc(data.size*sizeof(char));
        fread(data.name,data.size*sizeof(char),1,fp);
        fread(&data.age,sizeof(int),1,fp);
        printf("%-30s \t %d\n",data.name,data.age);
    }
    fclose(fp);
    return 0;
}
