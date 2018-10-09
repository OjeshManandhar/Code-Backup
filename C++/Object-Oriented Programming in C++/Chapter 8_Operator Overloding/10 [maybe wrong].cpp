#include <iostream>
#include <cmath>

using namespace std;

class polar
{
private:
    float radius, angle;

    void to_polar(float x, float y)
    {
        radius = sqrt(x*x + y*y);
        angle = atan(y/x);
    }

    void to_rectangular(float &x, float &y) const
    {
        x = radius*cos(angle);
        y = radius*sin(angle);
    }

public:
    polar(float r = 0, float a = 0): radius(r), angle(a)
    {}

    void get_data()
    {
        cout << "Enter radius: ";
        cin >> radius;
        cout << "Enter angle: ";
        cin >> angle;
    }

    void show_data() const
    {
        cout << "r = " << radius << ' ' << static_cast<unsigned char>(233) << " = " << angle << " radian" << endl;
    }

    polar operator +(const polar r) const
    {
        polar temp;
        float x1, y1, x2, y2;

        this->to_rectangular(x1, y1);
        r.to_rectangular(x2, y2);

        temp.to_polar(x1 + x2, y1 + y2);

        return temp;
    }
};

int main()
{
    polar a, b;

    cout << "Enter a polar coordinate:" << endl;
    a.get_data();
    cout << endl << "Enter another polar coordinate:" << endl;
    b.get_data();

    cout << endl << "Sum = ";
    (a + b).show_data();

    return 0;
}
