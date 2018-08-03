#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <swap.h>

int main()
{
    char **name;
    int n,*r,i,j;
    float *m;
    printf("Enter the number of students whose list you want to create: ");
    scanf("%d",&n);
    printf("\n");
    name=(char **)malloc(n*sizeof(char *));
    for (i=0;i<n;i++)
        name[i]=(char *)malloc(50*sizeof(char));
    r=(int *)malloc(n);
    m=(float *)malloc(n);
    for (i=0;i<n;i++)
    {
        fflush(stdin);
        printf("Enter the name of student no.%d: ",i+1);
        gets(name[i]);
        printf("Enter the roll number of student no.%d: ",i+1);
        scanf("%d",&r[i]);
        printf("Enter the marks of student no.%d: ",i+1);
        scanf("%f",&m[i]);
        printf("\n");
    }
    printf("\nList as entered:\n");
    printf("Name\t\tRoll\tMarks\n");
    for (i=0;i<n;i++)
    {
        if (strlen(name[i])<9)
            printf("%s\t\t",name[i]);
        else
            printf("%s\t",name[i]);
        printf("%d\t",r[i]);
        printf("%.2f\n",m[i]);
    }
    printf("\nList sorted on roll number:\n");
    printf("Name\t\tRoll\tMarks\n");
    for (i=0;i<n;i++)
        for (j=i+1;j<n;j++)
            if(r[i]>r[j])
            {
                swapi(&r[i],&r[j]);
                swapf(&m[i],&m[j]);
                swaps(name[i],name[j]);
            }
    for (i=0;i<n;i++)
    {
        if (strlen(name[i])<9)
            printf("%s\t\t",name[i]);
        else
            printf("%s\t",name[i]);
        printf("%d\t",r[i]);
        printf("%.2f\n",m[i]);
    }
    printf("\nList sorted on marks:\n");
    printf("Name\t\tRoll\tMarks\n");
    for (i=0;i<n;i++)
        for (j=i+1;j<n;j++)
            if(m[i]>m[j])
            {
                swapi(&r[i],&r[j]);
                swapf(&m[i],&m[j]);
                swaps(name[i],name[j]);
            }
    for (i=0;i<n;i++)
    {
        if (strlen(name[i])<9)
            printf("%s\t\t",name[i]);
        else
            printf("%s\t",name[i]);
        printf("%d\t",r[i]);
        printf("%.2f\n",m[i]);
    }
    for (i=0;i<n;i++)
        free(name[i]);
    free(name);
    free(m);
    free(r);
    return 0;
}
