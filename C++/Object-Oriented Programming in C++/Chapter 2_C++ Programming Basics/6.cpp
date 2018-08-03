#include <iostream>

using namespace std;

int main()
{
    float usd;

    cout << "Enter amount in U.S. dollars: $";
    cin >> usd;

    cout << endl << '$' << usd << " = " << usd/1.487 << " British pound." << endl;
    cout << '$' << usd << " = " << usd/0.172 << " French franc." << endl;
    cout << '$' << usd << " = " << usd/0.584 << " German deutschemark." << endl;
    cout << '$' << usd << " = " << usd/0.00955 << " Japanese yen." << endl;
    return 0;
}
