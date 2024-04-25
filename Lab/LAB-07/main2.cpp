#include <iostream>
#include "QueueType.cpp"

using namespace std;

int main()
{
    QueueType<string> queue;

    int input;
    cout << "Enter a number: 10" << endl;
    input = 10;

    queue.Enqueue("1");
    int r;
    string temp;

    for(int i = input; i > 0; i--)
    {
        queue.Dequeue(temp);
        cout<<temp<<endl;
        queue.Enqueue(temp+"0");
        queue.Enqueue(temp+"1");
    }

    return 0;
}