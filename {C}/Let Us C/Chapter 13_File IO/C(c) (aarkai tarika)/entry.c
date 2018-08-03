#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
    int size;           //Fileko data stored vayeko format:
    char *name;         //size of name, name  , age
    int age;            //int         , char *, int
}data;

int main()
{
    FILE *fp;
    char ch[26],c;
    fp=fopen("file_C(c).dat","ab+");
    if (fp==NULL)
    {
        perror("Can't open file");
        exit(EXIT_FAILURE);
    }
    do
    {
        printf("Enter the NAME of the student: ");
        fflush(stdin);
        gets(ch);
        data.size=strlen(ch)+1;
        data.name=(char *)malloc(data.size*sizeof(char));
        strcpy(data.name,ch);
        printf("Enter the AGE of the student: ");
        scanf("%d",&data.age);
        fwrite(&data.size,sizeof(int),1,fp);
        fwrite(data.name,data.size*sizeof(char),1,fp);
        fwrite(&data.age,sizeof(int),1,fp);
        printf("Add another record [Y/N]: ");
        fflush(stdin);
        c=getchar();
        printf("\n");
    }while(c=='y' || c=='Y');
    fclose(fp);
    return 0;
}
