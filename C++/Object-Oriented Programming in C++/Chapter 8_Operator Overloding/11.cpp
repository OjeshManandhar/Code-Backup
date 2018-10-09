#include <iostream>

using namespace std;

class sterling
{
private:
    long int pounds;
    int shillings, pence;

public:
    sterling(long int pnd = 0, int str = 0, int pen = 0): pounds(pnd), shillings(str), pence(pen)
    {}

    sterling(double amount)
    {
        pounds = amount/(20 * 12);
        amount -= pounds*(20 * 12);
        shillings = amount/(12);
        pence = amount - shillings * 12;
    }

    void getSterling()
    {
        char dummy;

        cout << "Enter amount: \x9C";
        cin >> pounds >> dummy >> shillings >> dummy >> pence;
    }

    void putSterling() const
    {
        cout << '\x9c' << pounds << '.' << shillings << '.' << pence << endl;
    }

    operator double() const
    {
        return pounds*(20*12) + shillings*12 + pence;
    }

    sterling operator +(const sterling s) const
    {
        return sterling(double(*this) + double(s));
    }

    sterling operator -(const sterling s) const
    {
        return sterling(double(*this) - double(s));
    }

    sterling operator *(const double mul) const
    {
        return sterling(double(*this)*mul);
    }

    double operator /(const sterling s) const
    {
        return (double(*this)/double(s));
    }

    sterling operator /(const double div) const
    {
        return sterling(double(*this)/div);
    }
};

int main()
{
    sterling total, price;
    double no_widgets;

    cout << "Enter total amount in sterling:" << endl;
    total.getSterling();
    cout << "Enter price per widget amount in sterling:" << endl;
    price.getSterling();
    cout << "Enter no. of widgets: ";
    cin >> no_widgets;

    cout << endl << "Total amount + price per widget = ";
    (total + price).putSterling();
    cout << "Total amount - price per widget = ";
    (total - price).putSterling();
    cout << "Price per widget * no of widgets = ";
    (price * no_widgets).putSterling();
    cout << "Total amount / price per widget = ";
    cout << total/price << endl;
    cout << "Total amount / no of widgets = ";
    (total/no_widgets).putSterling();

    return 0;
}
