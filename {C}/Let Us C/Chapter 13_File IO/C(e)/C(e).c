#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fs1,*fs2,*ft;
    int c=1,f1=0,f2=0;
    char ch[100];
    fs1=fopen("file_C(e)_s_1.txt","r");
    fs2=fopen("file_C(e)_s_2.txt","r");
    ft=fopen("file_C(e)_t.txt","w");
    while(1)
    {
        if (c%2==0 && f1==0)
        {
            if (fgets(ch,99,fs1)==NULL)
                f1=1;
            else
                fputs(ch,ft);
        }
        else if (c%2!=0 && f2==0)
        {
            if (fgets(ch,99,fs2)!=NULL)
                fputs(ch,ft);
            else
                f2=1;
        }
        if (f1==1 && f2==1)
            break;
        c++;
    }
    fclose(fs1);
    fclose(fs2);
    fclose(ft);
    return 0;
}
