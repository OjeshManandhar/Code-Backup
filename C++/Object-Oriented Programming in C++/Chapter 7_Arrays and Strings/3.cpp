#include <iostream>

using namespace std;

class Distance
{
private:
    int feet;
    float inches;

public:
    Distance(): feet(0), inches(0)
    {}

    void getdist()
    {
        cout << "Enter feet(s): ";
        cin >> feet;
        cout << "Enter inch(es): ";
        cin >> inches;
        cout << endl;
    }

    void showdist()
    {
        cout << feet << "\' - " << inches << '\"' << endl;
    }

    void add_dist(Distance d1, Distance d2)
    {
        inches = d1.inches + d2.inches;
        feet = 0;
        if(inches >= 12.0)
        {
            inches -= 12.0;
            feet++;
        }
        feet += d1.feet + d2.feet;
    }

    void div_dist(Distance d, int divisor)
    {
        /*
        float fltfeet = d.feet + d.inches/12.0;
        fltfeet /= divisor;
        feet = int(fltfeet);
        inches = (fltfeet - feet) * 12.0;
        */

        float total = d.inches + d.feet*12.0;
        total /= divisor;
        feet = int(total/12);
        inches = total - feet*12.0;
    }
};

int main()
{
    Distance data[100], total, average;
    int i;
    char ch;

    i = 0;
    do
    {
        i++;

        data[i - 1].getdist();

        total.add_dist(total, data[i - 1]);

        cout << "Enter another distance [Y/N]: ";
        cin >> ch;
        if (ch == 'y')
            ch = 'Y';
        cout << endl;
    }while (ch == 'Y');

    cout << endl << "Total: ";
    total.showdist();

    average.div_dist(total, i);
    cout << "Average: ";
    average.showdist();

    return 0;
}
