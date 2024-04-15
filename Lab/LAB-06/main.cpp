#include <iostream>
#include "StackType.cpp"

using namespace std;

int main()
{
    StackType<int> obj;

    if(obj.IsEmpty())
    {
        cout << "The Stack is Empty" << endl;
    }
    else
    {
        cout << "The Stack is Not Empty" << endl;
    }

    obj.Push(5);
    obj.Push(7);
    obj.Push(4);
    obj.Push(2);

    if(obj.IsEmpty())
    {
        cout << "The Stack is Empty" << endl;
    }
    else
    {
        cout << "The Stack is Not Empty" << endl;
    }

    if(obj.IsFull())
    {
        cout << "The Stack is Full" << endl;
    }
    else
    {
        cout << "The Stack is Not Full" << endl;
    }

    StackType<int> temp;
    while(!obj.IsEmpty())
    {
        temp.Push(obj.Top());
        obj.Pop();
    }

    while(!temp.IsEmpty())
    {
        cout << temp.Top() << " ";
        obj.Push(temp.Top());
        temp.Pop();
    }

    cout << "\n";

    obj.Push(3);

    while(!obj.IsEmpty())
    {
        temp.Push(obj.Top());
        obj.Pop();
    }

    while(!temp.IsEmpty())
    {
        cout << temp.Top() << " ";
        obj.Push(temp.Top());
        temp.Pop();
    }

    cout << "\n";

    if(obj.IsFull())
    {
        cout << "The Stack is Full" << endl;
    }
    else
    {
        cout << "The Stack is Not Full" << endl;
    }

    obj.Pop();
    obj.Pop();

    cout << obj.Top() << endl;

    return 0;
}
