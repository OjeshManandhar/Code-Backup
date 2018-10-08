#include <iostream>

using namespace std;

class counter
{
private:
    unsigned int c;

public:
    counter(): c(0)
    {}

    counter(unsigned int n)
    {
        c = n;
    }

    //copy constructor rakhe ni hunxa narakheni hunxa
    counter(counter &x)
    {
        c = x.c;
    }

    void showdata()
    {
        cout << "Count = " << c << endl;
    }
};

int main()
{
    counter c1, c2(5);
    counter c3(c2), c4 = c1;

    c1.showdata();
    c2.showdata();
    c3.showdata();
    c4.showdata();

    return 0;
}

/*
Output:
Count = 0
Count = 5
Count = 5
Count = 0
*/
