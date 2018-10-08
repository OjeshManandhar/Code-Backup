#include <iostream>

using namespace std;

int main()
{
    int a = 1, b = 1;
	int c;
    int n;

    cout << "Enter the no. of terms in series: ";
    cin >> n;

    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << a << " ";

        //int c = a + b;	//memory ali badi khanxa tesaile mathi nai c lai declare gareko
		c = a + b;
        a = b;
        b = c;
    }

    cout << endl;
    return 0;
}
