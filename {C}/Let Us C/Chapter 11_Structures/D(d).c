#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

struct cricket
{
    char *name;
    int age;
    int match;
    int runs;
}*data;

int compare(const struct cricket *elem1,const struct cricket *elem2)
{
    return (elem1->runs - elem2->runs);
}

int main()
{
    int n,i,l;
    char ch[25];
    do
	{
		system("cls");
		printf("Enter the no. of data to be entered [MAX=20]: ");
        scanf("%d",&n);
	}while(n>20);
    data=(struct cricket *)malloc(n*sizeof(struct cricket));
    for (i=0;i<n;i++)
    {
        printf("\n");
        fflush(stdin);
        printf("Enter the name of cricketer no.%d: ",i+1);
        gets(ch);
        l=strlen(ch)+1;
        data[i].name=(char *)malloc(l*sizeof(char));
        strcpy(data[i].name,ch);
        printf("Enter the age of cricketer no.%d: ",i+1);
        scanf("%d",&data[i].age);
        printf("Enter the no. of test match cricketer no.%d has played: ",i+1);
        scanf("%d",&data[i].match);
        printf("Enter the average runs of cricketer no.%d: ",i+1);
        scanf("%d",&data[i].runs);
    }
    qsort(data,n,sizeof(struct cricket),compare);
    printf("\nThe data of cricketers sorted (ascending order) by average runs are:\n");
    printf("Name\tAge\tMatches\t Runs\n");
    for (i=0;i<n;i++)
        printf("%s\t%d\t%d\t %d\n",data[i].name,data[i].age,data[i].match,data[i].runs);
    free(data);
    return 0;
}
