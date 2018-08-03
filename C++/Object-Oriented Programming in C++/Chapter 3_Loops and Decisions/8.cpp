#include <iostream>

using namespace std;

int main()
{
    int pounds, shillings, pence, total_pence;
    char ch;

    do
    {
        cout << "Enter first amount: \x9c";
        cin >> pounds >> ch >> shillings >> ch >> pence;
        total_pence = (pounds * 20 * 12) + (shillings * 12) + pence;
        cout << "Enter second amount: \x9c";
        cin >> pounds >> ch >> shillings >> ch >> pence;
        total_pence += (pounds * 20 * 12) + (shillings * 12) + pence;

        pounds = total_pence / (20 * 12);
        total_pence %= (20 * 12);
        shillings = total_pence / 12;
        pence = total_pence % 12;

        cout << "Total is \x9c" << pounds << '.' << shillings << '.' << pence << endl;

        cout << endl << "Do you wish to continue (y/n): ";
        cin >> ch;
        cout << endl;
    }while (ch == 'y');

    return 0;
}
