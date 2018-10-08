#include <iostream>

#define PI 3.141592653589793

using namespace std;

void volume(int l)
{
    cout << "Volume = " << (l*l*l) << endl;
}

void volume(int r, int h)
{
    cout << "Volume = " << (PI*r*r*h) << endl;
}

void volume(int l, int b, int h)
{
    cout << "Volume = " << (l*b*h) << endl;
}

int main()
{
    int a, b, c;

    cout << "Enter length: ";
    cin >> a;
    volume(a);

    cout << endl << "Enter radius and height: ";
    cin >> a >> b;
    volume(a, b);

    cout << endl << "Enter length, breadth and height: ";
    cin >> a >> b >> c;
    volume(a, b, c);

    return 0;
}
