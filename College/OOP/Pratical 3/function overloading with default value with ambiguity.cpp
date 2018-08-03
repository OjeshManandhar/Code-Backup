#include <iostream>

using namespace std;

void sum(float a = 0, float b = 0, float c = 0)
{
    cout << "Sum of floats = " << (a + b + c) << endl;
}

void sum(double a = 0, double b = 0, double c = 0)
{
    cout << "Sum of doubles = " << (a + b + c) << endl;
}

int main()
{
    float a = 3.5, b = 3.3;
    double x = 5.68, y = 0.02;

    //sum(5, 6);    //ambiguous
	sum((float)5, 6);
    sum(5.6, 4);
    sum(5.6f, 4, 9);
    sum(5.6d, 4);
    sum(a, b);
    sum(x, y);

    return 0;
}
/*
Output:
Sum of floats = 11
Sum of doubles = 9.6
Sum of floats = 18.6
Sum of doubles = 9.6
Sum of floats = 6.8
Sum of doubles = 5.7
*/
