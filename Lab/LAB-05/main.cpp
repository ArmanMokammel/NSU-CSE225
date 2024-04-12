#include "SortedType.cpp"
#include "TimeStamp.cpp"
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

    cout << "\n";
    

    SortedType<TimeStamp> timeStamps;

    timeStamps.InsertItem(TimeStamp(15, 34, 23));
    timeStamps.InsertItem(TimeStamp(13, 13, 02));
    timeStamps.InsertItem(TimeStamp(43, 45, 12));
    timeStamps.InsertItem(TimeStamp(25, 36, 17));
    timeStamps.InsertItem(TimeStamp(52, 02, 20));

    TimeStamp input2;
    for(int i = 0; i < timeStamps.LengthIs(); i++)
    {
        timeStamps.GetNextItem(input2);
        cout << input2;
    }

    cout << "\n";

    timeStamps.DeleteItem(TimeStamp(25, 36, 17));

    timeStamps.ResetList();
    for(int i = 0; i < timeStamps.LengthIs(); i++)
    {
        timeStamps.GetNextItem(input2);
        cout << input2;
    }
    
    return 0;
}