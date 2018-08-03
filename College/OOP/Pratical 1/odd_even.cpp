#include <iostream>

using namespace std;

int main()
{
    int n;

    cout << "Enter a number: ";
    cin >> n;

    cout << endl;
    if (n == 0)
        cout << n << " is neither odd nor even." << endl;
    else if (n%2 == 0)
        cout << n << " is even." << endl;
    else
        cout << n << " is odd." << endl;

    return 0;
}
