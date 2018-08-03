#include <iostream>

using namespace std;

int main()
{
    float gallons,cubic_foot;
	
    cout << "Enter volume in gallons: ";
    cin >> gallons;
	
    cubic_foot=gallons/7.481;
	
    cout << endl << "The entered volume in cubic foot is: " << cubic_foot << '.' << endl;
    return 0;
}
