#include <iostream>
#include "QueueType.cpp"

using namespace std;

template<class ItemType>
void printQueue(QueueType<ItemType>* queue, int size)
{
    int temp;
    QueueType<int> tempQ(size);

    while(!queue->IsEmpty())
    {
        queue->Dequeue(temp);
        cout<<temp<<" ";
        tempQ.Enqueue(temp);
    }
    cout<<"\n";
    while(!tempQ.IsEmpty())
    {
        tempQ.Dequeue(temp);
        queue->Enqueue(temp);
    }
}

int main()
{   
    QueueType<int> queue(5);

    if(queue.IsEmpty())
        cout << "Queue is Empty!" << endl;
    else
        cout << "Queue is not Empty!" << endl;

    queue.Enqueue(5);
    queue.Enqueue(7);
    queue.Enqueue(4);
    queue.Enqueue(2);

    if(queue.IsEmpty())
        cout << "Queue is Empty!" << endl;
    else
        cout << "Queue is not Empty!" << endl;

    if(queue.IsFull())
        cout << "Queue is Full!" << endl;
    else
        cout << "Queue is not Full!" << endl;

    queue.Enqueue(6);

    printQueue(&queue, 5);

    if(queue.IsFull())
        cout << "Queue is Full!" << endl;
    else
        cout << "Queue is not Full!" << endl;

    try
    {
        queue.Enqueue(8);
    }
    catch(FullQueue e)
    {
        cout << "Queue Overflow!" << endl;
    }

    int temp;
    queue.Dequeue(temp);
    queue.Dequeue(temp);

    printQueue(&queue, 5);

    queue.Dequeue(temp);
    queue.Dequeue(temp);
    queue.Dequeue(temp);

    if(queue.IsEmpty())
        cout << "Queue is Empty!" << endl;
    else
        cout << "Queue is not Empty!" << endl;

    try
    {
        queue.Dequeue(temp);
    }
    catch(EmptyQueue e)
    {
        cout << "Queue Underflow!" << endl;
    }   

    return 0;
}