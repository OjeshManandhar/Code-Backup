#include <iostream>

using namespace std;

int main()
{
    int pounds,shillings,pence;
    float decimal_pounds,decimal_shellings,frac;

    cout << "Enter decimal pounds: ";
    cin >> decimal_pounds;

    pounds = static_cast<int>(decimal_pounds);
    frac = decimal_pounds - pounds;
    decimal_shellings = frac * 20;
    shillings = static_cast<int>(decimal_shellings);
    frac = decimal_shellings - shillings;
    pence = frac * 12;

    cout << endl << "Equivalent in old notation = \x9c" << pounds << '.' << shillings << '.' << pence << '.' << endl;

    /* OR
    pounds = static_cast<int>(decimal_pounds);
    frac = decimal_pounds - pounds;
    decimal_shellings = frac * 20;

    cout << endl << "Equivalent in old notation = \x9c" << pounds << '.' << decimal_shellings << '.' << endl;
    */

    return 0;
}
