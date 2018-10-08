#include <iostream>

using namespace std;

void sum(int a, int b = 0, int c = 0)
{
    cout << "Sum = " << (a + b + c) << endl;
}

void sum(float a, float b = 0, float c = 0)
{
    cout << "Sum = " << (a + b + c) << endl;
}

int main()
{
    int a, b;
    float x, y, z;

    cout << "Enter 2 integers: ";
    cin >> a >> b;
    sum(a, b);

    cout << endl << "Enter 3 floating point numbers: ";
    cin >> x >> y >> z;
    sum(x, y, z);

    return 0;
}
