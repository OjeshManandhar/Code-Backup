#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int n,i;

    cout << "Enter a number: ";
    cin >> n;

    cout << endl;
    for (i=1;i<=10*20;i++)
    {
        cout << setw(7) << i*n;
        if (i%10==0)
            cout << endl;
    }

    return 0;
}
