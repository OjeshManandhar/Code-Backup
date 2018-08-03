#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct automobile
{
    char serial[4];
    int year;
    char *material;
    int quantity;
}*data;

int hextodeci(const char *ch)
{
    int ans=0,i,l,p;
    l=strlen(ch);
    p=l-1;
    for (i=0;i<l;i++,p--)
        if (ch[i]=='0')
            ans+=0*pow(16,p);
        else if (ch[i]=='1')
            ans+=1*pow(16,p);
        else if (ch[i]=='2')
            ans+=2*pow(16,p);
        else if (ch[i]=='3')
            ans+=3*pow(16,p);
        else if (ch[i]=='4')
            ans+=4*pow(16,p);
        else if (ch[i]=='5')
            ans+=5*pow(16,p);
        else if (ch[i]=='6')
            ans+=6*pow(16,p);
        else if (ch[i]=='7')
            ans+=7*pow(16,p);
        else if (ch[i]=='8')
            ans+=8*pow(16,p);
        else if (ch[i]=='9')
            ans+=9*pow(16,p);
        else if (ch[i]=='A' || ch[i]=='a')
            ans+=10*pow(16,p);
        else if (ch[i]=='B' || ch[i]=='b')
            ans+=11*pow(16,p);
        else if (ch[i]=='C' || ch[i]=='c')
            ans+=12*pow(16,p);
        else if (ch[i]=='D' || ch[i]=='d')
            ans+=13*pow(16,p);
        else if (ch[i]=='E' || ch[i]=='e')
            ans+=14*pow(16,p);
        else if (ch[i]=='F' || ch[i]=='f')
            ans+=15*pow(16,p);
    return ans;
}

int main()
{
    int n,i,l,f=0;
    char ch[25];
    printf("Enter the no. of data to be entered: ");
    scanf("%d",&n);
    data=(struct automobile *)malloc(n*sizeof(struct automobile));
    for (i=0;i<n;i++)
    {
        printf("\n");
        fflush(stdin);
        do
        {
            printf("Enter the serial number of the engine no.%d [BETWEEN AA0 AND FF9]: ",i+1);
            gets(data[i].serial);
        }while(hextodeci(data[i].serial)<hextodeci("AA0") || hextodeci(data[i].serial)>hextodeci("FF9"));
        printf("Enter year of manufacture of engine no.%d: ",i+1);
        scanf("%d",&data[i].year);
        fflush(stdin);
        printf("Enter the material of engine no.%d: ",i+1);
        gets(ch);
        l=strlen(ch)+1;
        data[i].material=(char *)malloc(l*sizeof(char));
        strcpy(data[i].material,ch);
        printf("Enter the quantity manufactured of engine no.%d: ",i+1);
        scanf("%d",&data[i].quantity);
    }
    printf("\nAll data(s) have been entered. Press any key.");
    getch();
    system("cls");
    printf("Information on parts with serial number between BB1 and CC6.\n\n");
    for (i=0;i<n;i++)
        if (f==0 && (hextodeci(data[i].serial)>=2993 && hextodeci(data[i].serial)<=3270))
        {
            f=1;
            printf("Serial No.\tYear\tMaterial\tQuantity\n");
            printf("%s\t\t%d\t%s\t%d\n",data[i].serial,data[i].year,data[i].material,data[i].quantity);
        }
        else if (f==1 && (hextodeci(data[i].serial)>=2993 && hextodeci(data[i].serial)<=3270))
            printf("%s\t\t%d\t%s\t%d\n",data[i].serial,data[i].year,data[i].material,data[i].quantity);
    if (f==0)
        printf("\tNO DATA FOUND.\n");
	free(data);
    return 0;
}
