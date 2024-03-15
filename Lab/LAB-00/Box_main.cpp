#include <iostream>
#include "Box.h"

using namespace std;

int main()
{
    Box b1;
    Box b2(5,5,5);

    cout << "The volume of box 1 is: " << b1.volume() << endl;
    cout << "The volume of box 1 is: " << b2.volume() << endl;

    return 0;
}
