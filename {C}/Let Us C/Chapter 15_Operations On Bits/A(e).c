#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#include <stdint.h>
#include <inttypes.h>

#define _BV(x) (1<<x)

void change(const uint16_t time, int *hh, int *mm, int *ss)
{
    int i;
    uint16_t n;
    *hh=time>>12;
    n=time>>6;
    for (i=6;i<=9;i++)
        n&=~_BV(i);
    *mm=n;
    n=time;
    for (i=6;i<16;i++)
        n&=~_BV(i);
    *ss=n;
}

int main()
{
    int hh,mm,ss;
    uint16_t time;
    printf("Enter the 2-bytes integer time [12 HRS FORMAT]: ");
    scanf("%hu",&time);
    change(time,&hh,&mm,&ss);
    if (hh>12 || mm>59 || ss>59)
        printf("\nWrong Input. Program Terminated\n");
    else
    {
        printf("Hours = %hu \t Minutes = %hu \t Seconds = %hu\n",hh,mm,ss);
        printf("HH : MM : SS = %hu : %hu : %hu\n",hh,mm,ss);
    }
    return 0;
}
