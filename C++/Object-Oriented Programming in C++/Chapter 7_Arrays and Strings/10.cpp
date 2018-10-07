#include <iostream>

using namespace std;

class matrix
{
private:
    int arr[10][10];
    int row, col;

public:
    matrix(int r, int c)
    {
        int i, j;

        row = r;
        col = c;

        for (i = 0; i < row; i++)
            for (j = 0; j < col; j++)
                arr[i][j] = 0;
    }

    void putel(int i, int j, int data)
    {
        if (((i < 0 || i > row - 1)) || (j < 0 || j > (col - 1)))
            cout << "Out of bound." << endl;
        else
            arr[i][j] = data;
    }

    int getel(int i, int j)
    {
        if (((i < 0 || i > row - 1)) || (j < 0 || j > (col - 1)))
        {
            cout << "Out of bound." << endl;
            return 0;
        }

        return arr[i][j];
    }
};

int main()
{
    matrix m(3, 4);

    m.putel(0, 3, 99);
    m.putel(1, 2, 45);
    m.putel(3, 3, 45);

    cout << m.getel(0, 3) << endl;
    cout << m.getel(1, 2) << endl;
    cout << m.getel(3, 3) << endl;

    return 0;
}
