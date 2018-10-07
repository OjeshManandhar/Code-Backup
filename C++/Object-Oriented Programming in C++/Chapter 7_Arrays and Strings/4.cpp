#include <iostream>

using namespace std;

int maxint(int *data, int n)
{
    int i, m;

    for (i = 0, m = 0; i < n; i++)
        if (data[i] > data[m])
            m = i;

    return m;
}

int main()
{
    int n[10] = {99, 58, 45, 105, -15, 52, 36, 45, 29, 37};

    cout << "Maximum is "<< n[maxint(n, 10)] << " at index " << maxint(n, 10) << endl;

    return 0;
}
