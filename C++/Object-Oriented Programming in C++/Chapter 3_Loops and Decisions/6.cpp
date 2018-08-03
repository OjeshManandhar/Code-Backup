#include <iostream>

using namespace std;

int main()
{
    unsigned int numb;
    unsigned long fact;

    while (1)
    {
        fact=1;
        cout << "Enter a number [0 TO EXIT]: ";
        cin >> numb;
        if (numb == 0)
            break;
        for (int j=numb; j>0; j--)
            fact*=j;
        cout << "Factorial is " << fact << endl << endl;
    }
	
    return 0;
}
