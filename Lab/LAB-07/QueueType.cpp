#include "QueueType.h"

template<class ItemType>
QueueType<ItemType>::QueueType(int max)
{
    maxQueue = max + 1;
    front = maxQueue - 1;
    rear = maxQueue - 1;
    items = new ItemType[maxQueue];
}

template<class ItemType>
QueueType<ItemType>::QueueType()
{
    maxQueue = 501;
    front = maxQueue - 1;
    rear = maxQueue - 1;
    items = new ItemType[maxQueue];
}

template<class ItemType>
QueueType<ItemType>::~QueueType()
{
    delete [] items;
}

template<class ItemType>
void QueueType<ItemType>::MakeEmpty()
{
    front = maxQueue - 1;
    rear = maxQueue - 1;
}

template<class ItemType>
bool QueueType<ItemType>::IsEmpty()
{
    return (rear == front);
}

template<class ItemType>
bool QueueType<ItemType>::IsFull()
{
    return ((rear+1) % maxQueue == front);
}

template<class ItemType>
void QueueType<ItemType>::Enqueue(ItemType newItem)
{
    if (IsFull())
    {
        throw FullQueue();
    }
    else
    {
        rear = (rear +1) % maxQueue;
        items[rear] = newItem;
    }
}

template<class ItemType>
void QueueType<ItemType>::Dequeue(ItemType& item)
{
    if (IsEmpty())
    {
        throw EmptyQueue();
    }
    else
    {
        front = (front + 1) % maxQueue;
        item = items[front];
    }
}
