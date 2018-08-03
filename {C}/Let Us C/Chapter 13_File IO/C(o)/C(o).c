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
}data;

int main()
{
    FILE *fp;
    int count=0,i,*arr=NULL,total=0;
    fp=fopen("EMPLOYEE.dat","rb");
    if (fp==NULL)
    {
        perror("Can't open file");
        exit(EXIT_FAILURE);
    }
    while (fread(&data,sizeof(struct employee),1,fp)==1)
    {
        for (i=count+1;i<data.empno;i++)
        {
            total++;
            arr=(int *)realloc(arr,total*sizeof(int));
            arr[total-1]=i;
        }
        count=data.empno;
    }
    puts("List of missing employee no is:");
    for (i=0;i<total;i++)
        printf("%d\t",arr[i]);
    printf("\n");
    free(arr);
    fclose(fp);
    return 0;
}
