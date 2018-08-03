#include <iostream>

using namespace std;

int main()
{
    float celsius;

    cout << "Enter temperature in Celsius: ";
    cin >> celsius;

    cout << endl << "Temperature in Fahrenheit is: " << celsius*(9.0/5.0)+32 << '.' << endl;
    return 0;
}
