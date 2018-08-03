#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

struct school
{
    char *name;
    int *sub;
    int total;
    float per;
    char *result;
    float sort;
}*data,*temp;

int compare_asc(const struct school *elem1, const struct school *elem2)
{
    return (elem1->sort - elem2->sort);
}

int compare_dsc(const struct school *elem1, const struct school *elem2)
{
    return (elem2->sort - elem1->sort);
}

int compare_str_asc(const struct school *elem1, const struct school *elem2)
{
    return (strcmp(elem2->result,elem1->result));
}

int compare_str_dsc(const struct school *elem1, const struct school *elem2)
{
    return (strcmp(elem1->result,elem2->result));
}

int main()
{
    int n,m,j,i,flag=0,l,choice,f=0;
    char ch[50];
    printf("Enter the number of STUDENTS: ");
    scanf("%d",&n);
    printf("Enter the number of SUBJECTS: ");
    scanf("%d",&m);
    data=(struct school *)malloc(n*sizeof(struct school));
    for (i=0;i<n;i++,flag=0)
    {
        fflush(stdin);
        printf("\nEnter the NAME of the student no.%d: ",i+1);
        gets(ch);
        l=strlen(ch)+1;
        data[i].name=(char *)malloc(l*sizeof(char));
        strcpy(data[i].name,ch);
        data[i].sub=(int *)malloc(m*sizeof(int));
        data[i].total=0;
        for (j=0;j<m;j++)
        {
            printf("Enter the marks scored in Sub%d by student no.%d: ",j+1,i+1);
            scanf("%d",&data[i].sub[j]);
            if (data[i].sub[j]<40)
                flag=1;
            data[i].total+=data[i].sub[j];
        }
        data[i].per=data[i].total*1.0/m*1.0;
        if (flag==0)
        {
            if (data[i].per>=65)
                data[i].result="I Division";
            else if (data[i].per>=50)
                data[i].result="II Division";
            else if (data[i].per>=40)
                data[i].result="III Division";
        }
        else if (flag==1)
            data[i].result="Fail";
        data[i].sort=0.0;
    }
    temp=(struct school*)malloc(n*sizeof(struct school));
    for (i=0;i<n;i++)
    {
        temp[i].name=data[i].name;
        temp[i].sub=(int *)malloc(m*sizeof(int));
        for (j=0;j<m;j++)
            temp[i].sub[j]=data[i].sub[j];
        temp[i].total=data[i].total;
        temp[i].per=data[i].per;
        temp[i].result=data[i].result;
        temp[i].sort=data[i].sort;
    }
    printf("\nAll data(s) have been entered. Press any key.");
    getch();
    for (;;f=0)
    {
        system("cls");
        printf("\t\tMAIN MENU\n\n");
        printf("1. Sort according TOTAL MARKS or PERCENTAGE.\n");
        printf("2. Sort according RESULT.\n");
        printf("3. Sort SUBJECT WISE.\n");
        printf("4. Exit\n\n");
        do
        {
            printf("Enter your choice: ");
            scanf("%d",&choice);
        }while (choice<1 || choice >4);
        if (choice!=4)
            system("cls");
        switch (choice)
        {
        case 1:
            printf("\t\t1. Sort according TOTAL MARKS or PERCENTAGE.\n");
            for (i=0;i<n;i++)
            {
                data[i].sort=data[i].total;
                temp[i].sort=temp[i].total;
            }
            qsort(data,n,sizeof(struct school),compare_dsc);
            qsort(temp,n,sizeof(struct school),compare_asc);
            break;
        case 2:
            printf("\t\t2. Sort according RESULT.\n");
			for (i=0;i<n;i++)
            {
                data[i].sort=data[i].total;
                temp[i].sort=temp[i].total;
            }
            qsort(data,n,sizeof(struct school),compare_str_dsc);
            qsort(temp,n,sizeof(struct school),compare_str_asc);
            break;
        case 3:
            f=1;
            printf("\t\t3. Sort SUBJECT WISE.\n\n");
            for (i=0;i<m;i++)
                printf("%d. Sort according to Sub%d.\n",i+1,i+1);
            printf("\n");
            do
            {
                printf("Enter your choice: ");
                scanf("%d",&j);
            }while (j<1 || j >m);
            for (i=0;i<n;i++)
            {
                data[i].sort=data[i].sub[j-1];
                temp[i].sort=temp[i].sub[j-1];
            }
            qsort(data,n,sizeof(struct school),compare_dsc);
            qsort(temp,n,sizeof(struct school),compare_asc);
            break;
        case 4:
            exit(1);
        }
        if (f==1)
            printf("\nA. Descending sort according to Sub%d\nName\t",j);
        else if (f!=1)
            printf("\nA. Sort type = Descending\nName\t");
        for (i=0;i<m;i++)
            printf("Sub%d\t",i+1);
        printf("Total\tPercentage\tResult\n");
        for (i=0;i<n;i++)
        {
            printf("%s\t",data[i].name);
            for (j=0;j<m;j++)
                if (data[i].sub[j]<40)
                    printf("%d*\t",data[i].sub[j]);
                else
                    printf("%d\t",data[i].sub[j]);
            printf("%d\t%.2f %c\t\t%s\n",data[i].total,data[i].per,'%',data[i].result);
        }
        if (f==1)
            printf("\nB. Ascending sort according to Sub%d\nName\t",j);
        else if (f!=1)
            printf("\nB. Sort type = Ascending\nName\t");
        for (i=0;i<m;i++)
            printf("Sub%d\t",i+1);
        printf("Total\tPercentage\tResult\n");
        for (i=0;i<n;i++)
        {
            printf("%s\t",temp[i].name);
            for (j=0;j<m;j++)
                if (temp[i].sub[j]<40)
                    printf("%d*\t",temp[i].sub[j]);
                else
                    printf("%d\t",temp[i].sub[j]);
            printf("%d\t%.2f %c\t\t%s\n",temp[i].total,temp[i].per,'%',temp[i].result);
        }
        printf("\nPress any key to go back to MAIN MENU...");
        getch();
    }
    return 0;
}
