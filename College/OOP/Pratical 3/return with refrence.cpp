#include <iostream>

using namespace std;

int &min(int &x, int &y)
{
    if (x < y)
        return x;
    else
        return y;
}

int main()
{
    int a, b;

    cout << "Enter value for a: ";
    cin >> a;
    cout << "Enter value for b: ";
    cin >> b;

    cout << endl << "Changing the minimum to -1." << endl;
    min(a, b) = -1;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    return 0;
}
/*
Output:
Enter value for a: 5
Enter value for b: 9

Changing the minimum to -1.
a = -1
b = 9
*/
