#include <iostream>

#define LIMIT 100

using namespace std;

class safearray
{
private:
    int arr[LIMIT];
    int upper, lower;

public:
    safearray(int lw, int up): upper(up), lower(lw)
    {}

    int& operator [](int n)
    {
        if(n < lower || n > upper)
        {
            cout << "Out of bound" << endl;
            return arr[0];
        }
        return arr[n - lower];
    }
};

int main()
{
    safearray a(500, 510);
    int i;

    for (i = 500; i <= 510; i++)
        a[i] = i;

    cout << "Elements from 500 to 510:" << endl;
    for (i = 500; i <= 510; i++)
        cout << "arr[" << i << "] = " << a[i] << endl;

    return 0;
}
