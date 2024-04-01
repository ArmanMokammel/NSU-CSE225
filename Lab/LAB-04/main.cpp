#include <iostream>
#include "UnsortedType.cpp"

using namespace std;

int main()
{
    UnsortedType<int> obj;

    obj.InsertItem(5);
    obj.InsertItem(7);
    obj.InsertItem(6);
    obj.InsertItem(9);

    int input;
    for(int i = 0; i < obj.LengthIs(); i++)
    {
        obj.GetNextItem(input);
        cout << input << " ";
    }

    //obj.ResetList();

    return 0;
}
