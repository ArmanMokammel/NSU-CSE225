#include <iostream>
using namespace std;

class Node
{
	public:
        int key; //data field
        Node* next; // address field
        Node(int key){ //constructor
            this->key = key;
            this->next = NULL;
        }
};

class Stack
{
    public:
        Node* head = NULL;
        void printStack()
        {
            Node* cur = head;
            while(cur!=NULL)
            {
                cout << cur->key << " ";
                cur = cur->next;
            }
            cout << endl;
        }

        void push(int key)
        {
            Node* newNode = new Node(key);
            newNode -> next = head;
            head = newNode;
            cout << "Pushing " << newNode->key << endl;
        }

        void pop()
        {
            if(head==NULL)
            {
                cout << "Stack is empty" << endl;
                return;
            }
            Node* temp = head;
            head = head->next;
            cout << "Popping " << temp->key << endl;
            delete temp;
        }
};

int main()
{
    Stack* s1 = new Stack();

    s1->push(1);
    s1->push(2);
    s1->push(3);

    s1->printStack();

    s1->pop();
    s1->pop();

    s1->printStack();

    return 0;
}
