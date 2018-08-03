#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#include <stdint.h>
#include <inttypes.h>

#define _BV(x) (1<<x)

int main()
{
    struct animal
    {
        char name[30];
        int type;
    }a={"OCELOT",18};
    if ((a.type & _BV(0))!=0)
        printf("%s is Canine.\n",a.name);
    else if ((a.type & _BV(1))!=0)
        printf("%s is Feline.\n",a.name);
    else if ((a.type & _BV(2))!=0)
        printf("%s is Cetacean.\n",a.name);
    else if ((a.type & _BV(3))!=0)
        printf("%s is Marsupial.\n",a.name);
    if ((a.type & _BV(4))==0)
        printf("%s is Herbivore.\n",a.name);
    else
        printf("%s is Carnivore.\n",a.name);
    return 0;
}
