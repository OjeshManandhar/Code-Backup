#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
    char name[26];
    int age;
}data;

int main()
{
    FILE *fp;
    char c;
    fp=fopen("file_C(c).dat","ab+");
    if (fp==NULL)
    {
        perror("Can't open file");
        exit(EXIT_FAILURE);
    }
    do
    {
        printf("Enter the NAME of the student [MAX 25 CHARACTERS]: ");
        fflush(stdin);
        gets(data.name);
        printf("Enter the AGE of the student: ");
        scanf("%d",&data.age);
        fwrite(&data,sizeof(struct student),1,fp);
        printf("Add another record [Y/N]: ");
        fflush(stdin);
        c=getchar();
        printf("\n");
    }while(c=='y' || c=='Y');
    fclose(fp);
    return 0;
}
