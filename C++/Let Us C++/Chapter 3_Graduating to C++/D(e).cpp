#include <iostream>

using namespace std;

void swapa(int &, int &);
void swapb(int &, int &);

int main()
{
    int a=10,b=20;

    cout << "a = " << a << '\t' << "b = " << b << endl;
    swapa(a,b);
    cout << "a = " << a << '\t' << "b = " << b << endl;
    return 0;
}

void swapa(int &x, int &y)
{
    swapb(x,y);
}

void swapb(int &a, int &b)
{
    a=a+b;
    b=a-b;
    a=a-b;
}
