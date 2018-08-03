#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    struct student
    {
        char *name;
        float comp;
        float acc;
        float eng;
        float nep;
        float math;
        float sum;
        float per;
    }data;
    int l;
    char ch[50];
    printf("Enter NAME of the student: ");
    gets(ch);
    l=strlen(ch)+1;
    data.name=(char *)malloc(l*sizeof(char));
    strcpy(data.name,ch);
    printf("Marks obtained in COMPUTER: ");
    scanf("%f",&data.comp);
    printf("Marks obtained in ACCOUNT: ");
    scanf("%f",&data.acc);
    printf("Marks obtained in ENGLISH: ");
    scanf("%f",&data.eng);
    printf("Marks obtained in NEPALI: ");
    scanf("%f",&data.nep);
    printf("Marks obtained in MATHEMATIC: ");
    scanf("%f",&data.math);
    data.sum=data.comp+data.acc+data.eng+data.nep+data.math*1.0;
    data.per=data.sum*1.0/5.0;
    printf("\n\nThe data you have entered are:\n");
    printf("NAME: ");
    puts(data.name);
    printf("Marks in COMPUTER: %.2f\n",data.comp);
    printf("Marks in ACCOUNT: %.2f\n",data.acc);
    printf("Marks in ENGLISH %.2f\n",data.eng);
    printf("Marks in NEPALI: %.2f\n",data.nep);
    printf("Marks in MATHEMATIC: %.2f\n",data.math);
    printf("TOTAL: %.2f\n",data.sum);
    printf("PERCENTAGE: %.2f\n",data.per);
	free(data.name);
    return 0;
}
