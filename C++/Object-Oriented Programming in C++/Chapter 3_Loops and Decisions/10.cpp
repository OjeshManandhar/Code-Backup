#include <iostream>

using namespace std;

int main()
{
    int years=0;
    float amount, final_amount, rate;

    cout << "Enter initial amount: ";
    cin >> amount;
    cout << "Enter final amount: ";
    cin >> final_amount;
    cout << "Enter interest rate (percent per year): ";
    cin >> rate;

    while (amount < final_amount)
    {
        years++;
        amount += amount * rate / 100;
    }

    cout << endl << "Required number of years is: " << years << '.' << endl;

    return 0;
}
