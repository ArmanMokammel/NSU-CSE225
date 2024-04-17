#include <iostream>

using namespace std;

class Node
{
    public:
        int key;
        Node* left;
        Node* right;
        Node(int key){
            this->key = key;
            this->left = NULL;
            this->right = NULL;
        }
};

Node* ROOT;

void preorder(Node* node)
{
    if(node == NULL) //Exit Condition
        return;

    cout << node->key << " ";
    preorder(node->left);
    preorder(node->right);
}

void inorder(Node* node)
{
    if(node == NULL) //Exit Condition
        return;

    inorder(node->left);
    cout << node->key << " ";
    inorder(node->right);
}

void postorder(Node* node)
{
    if(node == NULL) //Exit Condition
        return;

    postorder(node->left);
    postorder(node->right);
    cout << node->key << " ";
}

int main()
{
    ROOT = new Node(100);
    Node* leftOfRoot = new Node(50);
    ROOT->left = leftOfRoot;
    Node* rightOfRoot = new Node(150);
    ROOT->right = rightOfRoot;


    cout << "Pre-order: ";
    preorder(ROOT); // 100 50 150
    cout << "\nIn-order: ";
    inorder(ROOT); // 50 100 150
    cout << "\nPost-order: ";
    postorder(ROOT); // 50 150 100

    Node* a = new Node(25);
    leftOfRoot->left = a;

    Node* b = new Node(175);
    rightOfRoot->right = b;

    cout << "\n\n";

    cout << "Pre-order: ";
    preorder(ROOT); // 100 50 25 150 175
    cout << "\nIn-order: ";
    inorder(ROOT); // 25 50 100 150 175
    cout << "\nPost-order: ";
    postorder(ROOT); // 25 50 175 150 100

    cout << "\n";

    return 0;
}
