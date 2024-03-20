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

    cout << "\nEnter updated array size: ";
    int new_size;
    cin >> new_size;
    obj2.allocate(new_size);

    cout << "Insert "<<new_size-5<<" more values for Array: ";
    for(int i = 5; i < new_size; i++)
    {
        cin >> temp;
        obj2.setValue(i, temp);
    }

    cout << "The updated array is: "<<"\n";
    for(int i = 0; i < new_size; i++)
    {
        cout << "Array["<<i<<"]: " << obj2.getValue(i)<<"\n";
    }

    return 0;
}
