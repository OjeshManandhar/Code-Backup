#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#include <stdint.h>             //data types ko lagi
#include <inttypes.h>           //macros ko lagi Eg: "SCNd16" -> "hd"

#define _BV(x) (1<<x)

int main()
{
    int8_t i,n,game,count=0,*games_won=NULL;
    char *arr[]={"Cricket","Basketball","Football","Hockey","Lawn Tennis","Table Tennis","Carom","Chess"};
    printf("Enter the number representing the bit pattern: ");
    scanf("%d",&game);
    /*
        "%d" int8_t ko format specifier hoina|
        int8_t ko format specifier define gareko xaina <inttypes.h>ma|
        input wont be more than 255 kinaki 256 dekhi 9-bit use garnu parxa|
    */
    for (i=7;i>=0;i--)
    //for (i=0;i<8;i++)         //yo vanda mathiko ramro| bujnako lagi "checking" herne
    {
        n=game&_BV(i);
        if (n!=0)
        {
            //printf("1 ");       //checking
            count++;
            games_won=(int8_t *)realloc(games_won,count*sizeof(int8_t));
            games_won[count-1]=i;
        }
        //else                    //checking
           //printf("1 ");       //checking
    }
    if (count<5)
        puts("\nThis team did not win the Champion of Champions trophy.");
    else
    {
        puts("\nThis team has won the Champion of Champions trophy.");
        puts("The games won by this team are:");
        for (i=count-1;i>=0;i--)
            puts(arr[games_won[i]]);
    }
    free(games_won);
    return 0;
}
