#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

struct student
{
    int size;
    char *name;
}data;

int main()
{
    FILE *fp;
    char ch[31],c;
    fp=fopen("file_C(k).dat","ab");
    if (fp==NULL)
    {
        perror("Can't open file");
        exit(EXIT_FAILURE);
    }
    do
    {
        do
        {
            printf("Enter the NAME of the student [MAX 30 CHARACTERS]: ");
            fflush(stdin);
            gets(ch);
            data.size=strlen(ch)+1;
        }while(data.size>31);
        data.name=(char *)malloc(data.size*sizeof(data.name));
        strcpy(data.name,ch);
        fwrite(&data.size,sizeof(int),1,fp);
        fwrite(data.name,data.size*sizeof(char),1,fp);
        printf("\nAdd another record [Y/N]: ");
        fflush(stdin);
        c=getchar();
        printf("\n");
    }while(c=='y' || c=='Y');
    fclose(fp);
    return 0;
}
