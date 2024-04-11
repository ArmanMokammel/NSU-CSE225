#include "SortedType.cpp"
#include <iostream>

using namespace std;

int main()
{
    SortedType<int> obj;

    cout << obj.LengthIs() << endl;

    obj.InsertItem(5);
    obj.InsertItem(7);
    obj.InsertItem(4);
    obj.InsertItem(2);
    obj.InsertItem(1);
    //obj.InsertItem(3);

    int input;
    for(int i = 0; i < obj.LengthIs(); i++)
    {
        obj.GetNextItem(input);
        cout << input << " ";
    }

    cout << "\n";

    bool found = false;
    int search = 6;
    obj.RetrieveItem(search, found);

    if (found)
    {
        cout << "The item is found" << endl;
    }
    else
    {
        cout << "The item is not found" << endl;
    }

    found = false;
    search = 5;
    obj.RetrieveItem(search, found);

    if (found)
    {
        cout << "The item is found" << endl;
    }
    else
    {
        cout << "The item is not found" << endl;
    }

    if (obj.IsFull())
    {
        cout << "The list is full" << endl;
    }
    else
    {
        cout << "The list is not full" << endl;
    }

    obj.DeleteItem(1);

    obj.ResetList();
    for(int i = 0; i < obj.LengthIs(); i++)
    {
        obj.GetNextItem(input);
        cout << input << " ";
    }

    cout << "\n";

    if (obj.IsFull())
    {
        cout << "The list is full" << endl;
    }
    else
    {
        cout << "The list is not full" << endl;
    }
    
    return 0;
}