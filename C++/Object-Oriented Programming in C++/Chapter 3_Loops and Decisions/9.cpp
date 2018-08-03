#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int guests, chairs, i;
    long int ways=1;

    cout << "Enter number of guests: ";
    cin >> guests;
    cout << "Enter number of chairs: ";
    cin >> chairs;

    if (chairs >= guests)
    {
        cout << endl << "Wrong input." << endl;
        exit(EXIT_FAILURE);
    }

    for (i=chairs; i>=1; i--)
    {
        ways *= guests;
        guests--;
    }

    cout << endl << "Number of ways in which the guests can be seated is: " << ways << '.' << endl;

    return 0;
}
