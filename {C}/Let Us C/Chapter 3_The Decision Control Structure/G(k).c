#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m,d;
    printf("Enter the month of your DOB [IN NUMBERS]: ");
    scanf("%d",&m);
    printf("Enter the date of your DOB: ");
    scanf("%d",&d);
    if ((m==12 && d>=22 && d<=31) || (m==1 && d<=19))
        printf("\nSun Sign: Capricorn.\n");
    else if ((m==1 && d>=20 && d<=31) || (m==2 && d<=17))
        printf("\nSun Sign: Aquarius.\n");
    else if ((m==2 && d>=18 && d<=29) || (m==3 && d<=19))
        printf("\nSun Sign: Pisces.\n");
    else if ((m==3 && d>=20 && d<=31) || (m==4 && d<=19))
        printf("\nSun Sign: Aries.\n");
    else if ((m==4 && d>=20 && d<=30) || (m==5 && d<=20))
        printf("\nSun Sign: Taurus.\n");
    else if ((m==5 && d>=21 && d<=31) || (m==6 && d<=20))
        printf("\nSun Sign: Gemini.\n");
    else if ((m==6 && d>=21 && d<=30) || (m==7 && d<=22))
        printf("\nSun Sign: Cancer.\n");
    else if ((m==7 && d>=23 && d<=31) || (m==8 && d<=22))
        printf("\nSun Sign: Leo.\n");
    else if ((m==8 && d>=23 && d<=31) || (m==9 && d<=22))
        printf("\nSun Sign: Virgo.\n");
    else if ((m==9 && d>=23 && d<=30) || (m==10 && d<=22))
        printf("\nSun Sign: Libra.\n");
    else if ((m==10 && d>=23 && d<=31) || (m==11 && d<=21))
        printf("\nSun Sign: Scorpio.\n");
    else if ((m==11 && d>=22 && d<=30) || (m==12 && d<=21))
        printf("\nSun Sign: Sagittarius.\n");
    return 0;
}
