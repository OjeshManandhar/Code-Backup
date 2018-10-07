#include <iostream>

using namespace std;

class safearray
{
private:
    static const int LIMIT = 10;
    int arr[LIMIT];

public:
    safearray()
    {
        int i;

        for (i = 0; i < LIMIT; i++)
            arr[i] = 0;
    }

    void putel(int index, int data)
    {
        if (index < 0 || index > (LIMIT - 1))
            cout << "Out of bound." << endl;
        else
            arr[index] = data;
    }

    int getel(int index)
    {
        if (index < 0 || index > (LIMIT - 1))
        {
            cout << "Out of bound." << endl;
            return 0;
        }

        return arr[index];
    }
};

int main()
{
    safearray s;

    s.putel(5, 99);
    s.putel(7, 80);
    s.putel(10, 100);

    cout << s.getel(5) << endl;
    cout << s.getel(7) << endl;
    cout << s.getel(0) << endl;

    return 0;
}
