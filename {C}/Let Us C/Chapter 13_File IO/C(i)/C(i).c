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
}*data,temp;

/*
int compare(const struct employee *elem1, const struct employee *elem2)
{
    if (elem1->join_date.y == elem2->join_date.y)
    {                                                   //ambigious nahos vanera "{....}" rekheko||
        if (elem1->join_date.m == elem2->join_date.m)
            return (elem1->join_date.d - elem2->join_date.d);
        else if (elem1->join_date.m != elem2->join_date.m)
            return (elem1->join_date.m - elem2->join_date.m);
    }
    else if (elem1->join_date.y != elem2->join_date.y)
        return (elem1->join_date.y - elem2->join_date.y);
}
*/

int compare(const struct employee *elem1, const struct employee *elem2)
{
    if ((elem1->join_date.y == elem2->join_date.y) && (elem1->join_date.m == elem2->join_date.m))
        return (elem1->join_date.d - elem2->join_date.d);
    else if ((elem1->join_date.y == elem2->join_date.y) && (elem1->join_date.m != elem2->join_date.m))
        return (elem1->join_date.m - elem2->join_date.m);
    else
        return (elem1->join_date.y - elem2->join_date.y);
}

int main()
{
    FILE *fp;
    int i=0,n=0;
    fp=fopen("file_C(i).dat","rb");
    if (fp==NULL)
    {
        perror("Can't open file.");
        exit(EXIT_FAILURE);
    }
    while (fread(&temp,sizeof(struct employee),1,fp)==1)
    {
        n++;
        data=(struct employee *)realloc(data,n*sizeof(struct employee));
        data[i]=temp;
        i++;
    }
    puts("The data(s) as stored.\n");
    printf("%-6s \t %-19s Join Date  \t Salary\n","Code","Name");
    for (i=0;i<n;i++)
        printf("%.6d \t %-19s %.2d/%.2d/%d \t %.2f\n",data[i].empcode,data[i].empname,data[i].join_date.d,data[i].join_date.m,data[i].join_date.y,data[i].salary);
    qsort(data,n,sizeof(struct employee),compare);
    puts("\nThe data(s) sorted in order of join date.\n");
    printf("%-6s \t %-19s Join Date  \t Salary\n","Code","Name");
    for (i=0;i<n;i++)
        printf("%.6d \t %-19s %.2d/%.2d/%d \t %.2f\n",data[i].empcode,data[i].empname,data[i].join_date.d,data[i].join_date.m,data[i].join_date.y,data[i].salary);
	free(data);
    fclose(fp);
    return 0;
}
