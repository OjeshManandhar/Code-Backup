#include <iostream>

using namespace std;

int main()
{
    int i,j,c;

    for (i=1,c=1; i<=20; i++,c+=2)
    {
        for (j=i; j<20; j++)
            cout << ' ';
        for (j=1; j<=c; j++)
            cout << 'X';
        cout << endl;
    }

    return 0;
}
