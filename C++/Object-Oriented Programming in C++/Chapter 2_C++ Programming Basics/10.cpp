#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int pounds,shillings,pence;
    float decimal_pounds,total_shillings;

    cout << "Enter pounds: ";
    cin >> pounds;
    cout << "Enter shillings: ";
    cin >> shillings;
    cout << "Enter pence: ";
    cin >> pence;

    total_shillings = shillings + static_cast<float>(pence) / 12.0;
    decimal_pounds = pounds + total_shillings / 20.0;

    //Precisionko lagi
    cout << setprecision(2) << fixed;
    cout << fixed << setprecision(2);

    cout << endl << "Decimal pounds: " << static_cast<char>(156) << decimal_pounds << '.' << endl;
    //cout << endl << "Decimal pounds: /x9c" << decimal_pounds << '.' << endl;

    return 0;
}
