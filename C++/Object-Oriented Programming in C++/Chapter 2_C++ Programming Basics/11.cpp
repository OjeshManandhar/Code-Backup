#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    cout << left; //left allignmentko lagi|
    cout << setw(12) << "Last name" << setw(13) << "First name" << setw(18) << "Street address" << setw(12) << "Town" << "State" << endl;
    cout << right << setfill('-') << setw(61) << '\n';
    /*
    setw() paxi khi print garena vane tesle kam gardaina|
    cout << right << setfill('-') << setw(61) << endl;
    mathiko kangardaina
    */
    cout << left << setfill(' ');

    cout << setw(12) << "Jones" << setw(13) << "Bernard" << setw(18) << "109 Pine Lane" << setw(12) << "Littletown" << "MI" << endl;
    cout << setw(12) << "O'Brian" << setw(13) << "Coleen" << setw(18) << "42 E. 99th Ave." << setw(12) << "Bigcity" << "NY" << endl;
    cout << setw(12) << "Wong" << setw(13) << "Harry" << setw(18) << "121-A Alabama St." << setw(12) << "Lakeville" << "IL" << endl;

    return 0;
}
