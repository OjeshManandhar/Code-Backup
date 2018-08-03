#include <iostream>

using namespace std;

int main()
{
    int years,i;
    float amount, rate;

    cout << "Enter initial amount: ";
    cin >> amount;
    cout << "Enter number of years: ";
    cin >> years;
    cout << "Enter interest rate (percent per year): ";
    cin >> rate;

    for (i=1; i<=years; i++)
    {
        amount += (amount * (rate / 100.0));
    }

    cout << endl << "At the end of " << years << " years, you will have " << amount << " dollars." << endl;

    return 0;
}
