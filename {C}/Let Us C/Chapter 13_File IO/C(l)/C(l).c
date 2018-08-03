#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

struct student
{
    int roll,size;
    char *name;
}*data,*update;

struct transaction
{
    int roll,size;
    char *name,type;
}*trans;

int compare(const void *elem1, const void *elem2)
{
    struct student *x=(struct student *)elem1;
    struct student *y=(struct student *)elem2;

    return (x->roll - y->roll);
}

void del_record(struct student *arr,int *no,const int loc)
{
    int i,j,n=*no,size;
    struct student *temp;
    size=sizeof(struct student);
    temp=(struct student *)malloc((n-1)*size);
    for (i=0,j=0;i<n;i++)
        if (i!=loc)
        {
            temp[j]=arr[i];
            j++;
        }
    free(arr);
    n--;
    arr=(struct student *)malloc(n*size);
    for (i=0;i<n;i++)
        arr[i]=temp[i];
    free(temp);
    *no=n;
}

int main()
{
    FILE *fp;
    int i,j,n=0,total_master=0,total_transaction=0,flag=0,x;
    fp=fopen("master.dat","rb");
    if (fp==NULL)
    {
        perror("Can't open master.dat");
        exit(EXIT_FAILURE);
    }
    while (fread(&x,sizeof(int),1,fp)==1)
    {
        flag=1;
        total_master++;
        i=total_master-1;
        data=(struct student *)realloc(data,total_master*sizeof(struct student));
        data[i].roll=x;
        fread(&data[i].size,sizeof(int),1,fp);
        data[i].name=(char *)malloc(data[i].size*sizeof(char));
        fread(data[i].name,data[i].size*sizeof(char),1,fp);
    }
    if (flag==0)
    {
        puts("NO DATA FOUND.\nProgram terminated.");
        fclose(fp);
        exit(EXIT_SUCCESS);
    }
    else
    {
        puts("Data(s) in the master.dat file:");
        puts("Roll Name");
        for (i=0;i<total_master;i++)
            printf(" %-3.2d %s\n",data[i].roll,data[i].name);
        printf("\nPress any key to continue....");
        getch();
        system("cls");
    }
    fclose(fp);

    flag=0;
    fp=fopen("transaction.dat","rb");
    if (fp==NULL)
    {
        perror("Can't open transaction.dat");
        exit(EXIT_FAILURE);
    }
    while (fread(&x,sizeof(int),1,fp)==1)
    {
        flag=1;
        total_transaction++;
        i=total_transaction-1;
        trans=(struct transaction *)realloc(trans,total_transaction*sizeof(struct transaction));
        trans[i].roll=x;
        fread(&trans[i].size,sizeof(int),1,fp);
        trans[i].name=(char *)malloc(trans[i].size*sizeof(char));
        fread(trans[i].name,trans[i].size*sizeof(char),1,fp);
        fread(&trans[i].type,sizeof(char),1,fp);
    }
    if (flag==0)
    {
        puts("NO DATA FOUND.\nProgram terminated.");
        free(data);
        fclose(fp);
        exit(EXIT_SUCCESS);
    }
    else
    {
        puts("Data(s) in the transaction.dat file:");
        printf("Roll %-30s Type\n","Name");
        for (i=0;i<total_transaction;i++)
            printf(" %-3.2d %-30s %c\n",trans[i].roll,trans[i].name,toupper(trans[i].type));
        printf("\nPress any key to continue....");
        getch();
        system("cls");
    }
    fclose(fp);

    flag=0;
    fp=fopen("file_C(l).dat","wb+");
    if (fp==NULL)
    {
        perror("Can't open file");
        exit(EXIT_FAILURE);
    }
    for (i=0;i<total_master;i++)
    {
        n++;
        j=n-1;
        update=(struct student *)realloc(update,n*sizeof(struct student));
        update[j]=data[i];
    }
    for (i=0;i<total_transaction;i++)
        if (trans[i].type=='a' || trans[i].type=='A')
        {
            n++;
            j=n-1;
            update=(struct student *)realloc(update,n*sizeof(struct student));
            update[j].roll=trans[i].roll;
            update[j].size=trans[i].size;
            update[j].name=(char *)malloc(update[j].size*sizeof(char));
            strcpy(update[j].name,trans[i].name);
        }
        else if (trans[i].type=='d' || trans[i].type=='d')
            for (x=0;x<j;x++)
                if (update[x].roll==trans[i].roll)
                {
                    del_record(update,&n,x);
                    break;
                }
    system("cls");
    if (n==0)
        puts("NO DATA FOUND");
    else
    {
        puts("Updated list as CREATED.");
        puts("Roll Name");
        for (i=0;i<n;i++)
            printf(" %-3.2d %s\n",update[i].roll,update[i].name);
        qsort(update,n,sizeof(struct student),compare);
        puts("\nThe data(s) will be STORED in ascending order of roll as:");
        puts("Roll Name");
        for (i=0;i<n;i++)
        {
            printf(" %-3.2d %s\n",update[i].roll,update[i].name);
            fwrite(&update[i].roll,sizeof(int),1,fp);
            fwrite(&update[i].size,sizeof(int),1,fp);
            fwrite(update[i].name,update[i].size*sizeof(char),1,fp);
        }
    }
	free(data);
	free(update);
	free(trans);
	fclose(fp);
    return 0;
}
