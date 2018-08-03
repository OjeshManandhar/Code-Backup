#include <iostream>

using namespace std;

int main()
{
    int i,a='a',b='B',c='c',d='D';
    int* ptr_arr[4];
    char ch;
    ptr_arr[0]=&a;
    ptr_arr[1]=&b;
    ptr_arr[2]=&c;
    ptr_arr[3]=&d;
    for (i=0;i<4;i++)
    {
        ch=i+97;
        cout << "Value of " << ch << " is: " << *ptr_arr[i] << endl;
    }
    return 0;
}
