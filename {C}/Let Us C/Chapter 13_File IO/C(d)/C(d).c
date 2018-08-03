#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fs,*ft;
    char c;
    fs=fopen("file_C(d)_s.txt","r");
    ft=fopen("file_C(d)_t.txt","a");
    putc('\n',ft);
    while (1)
    {
        c=fgetc(fs);
        if (c==EOF)
            break;
        if (c>=97 && c<=122)
            putc(c-32,ft);
        else
            putc(c,ft);
    }
	fclose(fs);
	fclose(ft);
    return 0;
}
