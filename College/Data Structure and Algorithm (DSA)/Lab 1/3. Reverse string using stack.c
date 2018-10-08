#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
    unsigned int len;
    int i;
    char ch;
    char *data = NULL;

    printf("Enter a string: ");

    len = 0;
    while (1)
    {
        ch = getch();
        if (ch == '\b' && len == 0)     //BACKSPACE
            continue;
        else if (ch == '\b')            //BACKSPACE
        {
            printf("\b \b");
            len--;
            data[len] = 0;
            data = (char *)realloc(data, len*sizeof(char));
        }
        else if (ch == '\r')            //ENTER
        {
            /*
            len++;
            data = (char *)realloc(data, len*sizeof(char));
            data[len - 1] = 0;
            */
            //mathi ko code rakhyo ki tala reverse display garne loop ma i = len - 2 rakhne
            printf("\n");
            break;
        }
        else if (ch == '\t')            //TAB
            continue;
        else
        {
            len++;
            data = (char *)realloc(data, len*sizeof(char));
            data[len - 1] = ch;
            printf("%c", ch);
        }
    }

    printf("\nReverse string: ");
    for (i = len - 1; i >= 0; i--)
        printf("%c", data[i]);
    printf("\n");

    free(data);

    return 0;
}
