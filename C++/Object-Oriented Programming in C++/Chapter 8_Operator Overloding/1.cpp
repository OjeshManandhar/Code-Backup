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

    Distance(int ft, float in): feet(ft), inches(in)
    {}

    void getdist()
    {
        cout << "Enter feet: ";
        cin >> feet;
        cout << "Enter inches: ";
        cin >> inches;
    }

    void showdist() const
    {
        cout << feet << "\' - " << inches << '\"' << endl;
    }

    Distance operator -(const Distance d) const
    {
        Distance temp;

        temp.feet = feet - d.feet;
        temp.inches =inches - d.inches;
        if (temp.inches < 0)
        {
            temp.feet -= 1;
            temp.inches += 12;
        }

        return temp;
    }
};


int main()
{
    Distance d1, d2, d3;

    cout << "Enter the loner distance:" << endl;
    d1.getdist();

    cout << endl << "Enter the shorter distance:" << endl;
    d2.getdist();

    d3 = d1 - d2;

    cout << endl << "The difference is ";
    d3.showdist();

    return 0;
}
