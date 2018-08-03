#include <iostream>

using namespace std;

int main()
{
    int a,b,c,d;
    char dummy_char;

    cout << "Enter first fraction: ";
    cin >> a >> dummy_char >> b;
    cout << "Enter second fraction: ";
    cin >> c >> dummy_char >> d;

    cout << endl << "Sum = " << a*d+b*c << '/' << b*d << '.' << endl;
    return 0;
}
