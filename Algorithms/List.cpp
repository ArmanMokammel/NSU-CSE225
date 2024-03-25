#include <iostream>
using namespace std;

class Node{
	public:
	int key; //data field
	Node* next; // address field
	Node(int key){ //constructor
		this->key = key;
		this->next = NULL;
	}
};

Node* head = NULL;

void pushFront(int key){ //complexity = O(1) constant time complexity
	Node* newNode = new Node(key);
	newNode -> next = head;
	head = newNode;
}

void pushBack(int key){ // Complexity = O(n)
	Node* newNode = new Node(key);
	Node* cur = head;
	while(cur->next != NULL)
		cur = cur->next;
	// cur holds the addr of the last node
	cur -> next = newNode;
}

void popFront(){
	if(head==NULL){
		cout << "List is empty. Invalid operation." << endl;
		return;
	}
	Node* temp = head;
	head = head -> next;
	delete temp;

}

Node* find(int key)
{
    if(key == NULL)
        return NULL;

    Node* cur = head;
    while(cur->next != NULL)
    {
        if(cur->key == key)
        {
            return cur;
        }
        cur = cur->next;
    }
    return NULL;
}

Node* addAfter(Node* node, int key)
{
    Node* nd = find(node->key);

    if(nd != NULL)
    {
        Node* newNode = new Node(key);
        newNode->next = node->next;
        node->next = newNode;
    }
    return nd;
}

void printNode(){ //complexity = O(n) linear time complexity
	Node* cur = head;
	while(cur!=NULL){
		cout << cur -> key << " ";
		cur = cur -> next;
	}
	cout << endl;
}

int main() {
	// your code goes here

	popFront();
	pushFront(100); // 100
	pushFront(90); // 90 -> 100
	pushFront(80); // 80 -> 90 -> 100
	printNode();
	pushBack(110); // 80 -> 90 -> 100 -> 110
	pushBack(120); // 80 -> 90 -> 100 -> 110 -> 120
	printNode();
	popFront(); // 90 -> 100 -> 110 -> 120
	printNode();

	// This is where you start
	int searchKey;
	cout << "Enter the node key you want to search: ";
	cin >> searchKey;

	Node* node = find(searchKey);

	if(node != NULL)
    {
        cout << "The node is found " << node << " " << node->key << endl;
    }
    else
    {
        cout << "The node was not found" << endl;
    }

    addAfter(node, 1);

    printNode();

	return 0;
}
