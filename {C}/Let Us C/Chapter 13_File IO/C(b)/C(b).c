#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fs,*ft;
    char c;
    fs=fopen("file_C(b)_s.txt","r");
    ft=fopen("file_C(b)_t.txt","a");
    fputc('\n',ft);
    while (1)
    {
        c=fgetc(fs);
        if (c==EOF)
            break;
        fputc(c,ft);
    }
	fclose(fs);
	fclose(ft);
    return 0;
}
