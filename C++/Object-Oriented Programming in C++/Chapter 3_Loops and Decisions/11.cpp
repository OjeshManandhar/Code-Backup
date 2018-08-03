#include <iostream>

using namespace std;

int main()
{
    int pounds, shillings, pence, choice, total_pence=0;
    float mul;
    char ch;

    cout << "1. Add money." << endl
         << "2. Subtract money." << endl
         << "3. Multiply money by a number." << endl
         << "Enter your choice: ";
    cin >> choice;

    cout << endl;
    switch (choice)
    {
    case 1:
        cout << "Enter first amount: \x9c";
        cin >> pounds >> ch >> shillings >> ch >> pence;
        total_pence = (pounds * 20 * 12) + (shillings * 12) + pence;
        cout << "Enter second amount: \x9c";
        cin >> pounds >> ch >> shillings >> ch >> pence;
        total_pence += (pounds * 20 * 12) + (shillings * 12) + pence;

        pounds = total_pence / (20 * 12);
        total_pence %= 20*12;
        shillings = total_pence / 12;
        pence = total_pence % 12;

        cout << endl << "Total is \x9c" << pounds << '.' << shillings << '.' << pence << endl;
        break;

    case 2:
        cout << "Enter first amount: \x9c";
        cin >> pounds >> ch >> shillings >> ch >> pence;
        total_pence = (pounds * 20 * 12) + (shillings * 12) + pence;
        cout << "Enter second amount: \x9c";
        cin >> pounds >> ch >> shillings >> ch >> pence;
        total_pence -= (pounds * 20 * 12) + (shillings * 12) + pence;
        total_pence = (total_pence < 0)? total_pence * -1 : total_pence;

        pounds = total_pence / (20 * 12);
        total_pence %= 20*12;
        shillings = total_pence / 12;
        pence = total_pence % 12;

        cout << endl << "Total is \x9c" << pounds << '.' << shillings << '.' << pence << endl;
        break;

    case 3:
        cout << "Enter amount: \x9c";
        cin >> pounds >> ch >> shillings >> ch >> pence;
        total_pence = (pounds * 20 * 12) + (shillings * 12) + pence;
        cout << "Multiply the amount by: ";
        cin >> mul;
        total_pence *= mul;

        pounds = total_pence / (20 * 12);
        total_pence %= 20*12;
        shillings = total_pence / 12;
        pence = total_pence % 12;

        cout << endl << "Total is \x9c" << pounds << '.' << shillings << '.' << pence << endl;
        break;

    default:
        cout << "Wrong Input." << endl;
    }

    return 0;
}
