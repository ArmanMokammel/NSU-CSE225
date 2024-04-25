#ifndef QUEUETYPE_INCLUDED
#define QUEUETYPE_INCLUDED

class FullQueue
{};

class EmptyQueue
{};

template<class ItemType>
class QueueType
{
    public:
        QueueType();
        QueueType(int max);
        ~QueueType(); // Destructor
        void MakeEmpty();
        bool IsEmpty();
        bool IsFull();
        void Enqueue(ItemType);
        void Dequeue(ItemType&);

    private:
        int front;
        int rear;
        ItemType* items;
        int maxQueue;
};

#endif