#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
    int size;           //Fileko data stored vayeko format:
    char *name;         //size of name, name  , age
    int age;            //int         , char *, int
}*data;

int compare(const struct student *elem1, const struct student *elem2)
{
    return(strcmp(elem1->name,elem2->name));
}

int main()
{
    FILE *fp;
    int n=0,i,s;
    char c;
    fp=fopen("file_C(c).dat","rb");
    if (fp==NULL)
    {
        perror("Can't open file");
        exit(EXIT_FAILURE);
    }
    while (fread(&s,sizeof(int),1,fp)==1)
    {
        n++;
        i=n-1;
        data=(struct student *)realloc(data,n*sizeof(struct student));
        data[i].size=s;
        data[i].name=(char *)malloc(s*sizeof(char));
        fread(data[i].name,s*sizeof(char),1,fp);
        fread(&data[i].age,sizeof(int),1,fp);
    }
    printf("Data as stored.\n");
    printf("%-25s Age\n","Name");
    for (i=0;i<n;i++)
        printf("%-25s %d\n",data[i].name,data[i].age);
    printf("\nSorting data in order of name.\n");
    qsort(data,n,sizeof(struct student),compare);
    printf("%-25s Age\n","Name");
    for (i=0;i<n;i++)
        printf("%-25s %d\n",data[i].name,data[i].age);
    free(data);
    fclose(fp);
    return 0;
}
