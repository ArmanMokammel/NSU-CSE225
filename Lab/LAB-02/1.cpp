#include <iostream>
#include "dynarr.h"

using namespace std;

int main()
{
    dynArr obj1;
    dynArr obj2(5);

    cout << "Insert 5 values for Array: ";
    int temp;
    for(int i = 0; i < 5; i++)
    {
        cin >> temp;
        obj2.setValue(i, temp);
    }

    cout << "The created array is: "<<"\n";
    for(int i = 0; i < 5; i++)
    {
        cout << "Array["<<i<<"]: " << obj2.getValue(i)<<"\n";
    }

    return 0;
}
