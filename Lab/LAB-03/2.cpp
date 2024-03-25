#include "complex.h"
#include <iostream>

using namespace std;

int main()
{
    Complex c1(3,5);
    Complex c2(4,7);
    Complex c3;

    c3 = c1+c2;  //c1.add(c2)

    cout << "The summation of the complex numbers is: ";
    c3.Print();

    bool r = c1==c2;

    if (r==true)
        cout << "c1 is equal to c2" << endl;
    else
        cout << "c1 is not equal to c2" << endl;

    return 0;
}
