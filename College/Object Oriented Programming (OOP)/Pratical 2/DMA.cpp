#include <iostream>

using namespace std;

int main()
{
    int *num = NULL;
    int n, sum = 0;

    cout << "Total no. of number: ";
    cin >> n;

    num = new int[n];

    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter number no. " << i + 1 << ": ";
        cin >> num[i];

        sum += num[i];
    }

    cout << endl << "Sum = " << sum << endl;
    cout << "Average = " << (float)sum/n << endl;
	
	delete[] num;

    return 0;
}
