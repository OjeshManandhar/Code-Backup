#include <iostream>

#define PI 3.141592653589793

using namespace std;

inline double area(double radius)
{
    return (PI*radius*radius);
}

int main()
{
    double rad;

    cout << "Enter radius of a circle: ";
    cin >> rad;

    cout << endl << "Area = " << area(rad) << endl;

    return 0;
}

/*
Output:
Enter radius of a circle: 5

Area = 78.5398
*/
