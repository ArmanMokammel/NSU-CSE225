#include "SortedType.h"
#include <iostream>

using namespace std;

template <class ItemType>
SortedType<ItemType>::SortedType()
{
    length = 0;
    currentPos = -1;
}

template <class ItemType>
void SortedType<ItemType>::MakeEmpty()
{
    length = 0;
}

template <class ItemType>
bool SortedType<ItemType>::IsFull()
{
    return (length == MAX_ITEMS);
}

template <class ItemType>
int SortedType<ItemType>::LengthIs()
{
    return length;
}

template <class ItemType>
void SortedType<ItemType>::ResetList()
{
    currentPos = -1;
}

template <class ItemType>
void SortedType<ItemType>::GetNextItem(ItemType& item)
{
    currentPos++;
    item = arr[currentPos];
}

template <class ItemType>
void SortedType<ItemType>::RetrieveItem(ItemType& item, bool &found)
{
    int midPoint, first = 0, last = length - 1;
    found = false;
    while ((first <= last) && !found)
    {
        midPoint = (first + last) / 2;
        if(item < arr[midPoint])
        {
            last = midPoint - 1;
        }
        else if(item > arr[midPoint])
        {
            first = midPoint + 1;
        }
        else
        {
            found = true;
            item = arr[midPoint];
        }
    }
}

template <class ItemType>
void SortedType<ItemType>::InsertItem(ItemType item)
{
    if (IsFull())
    {
        cout << "Cannot insert item. List is full" << endl;
        return;
    }

    int index = 0;
    while (index < length)
    {
        if (item > arr[index])
        {
            index++;
        }
        else if (item < arr[index])
        {
            break;
        }
    }

    for(int i = length; i > index; i--)
    {
        arr[i] = arr[i-1];
    }

    arr[index] = item;
    length++;
}

template <class ItemType>
void SortedType<ItemType>::DeleteItem(ItemType item)
{
    int index = 0;

    while (item != arr[index])
    {
        index++;
    }
    
    for (int i = index + 1; i < length; i++)
    {
        arr[i-1] = arr[i];
    }
    length--;
}