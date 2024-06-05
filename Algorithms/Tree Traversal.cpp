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

Node* insert(Node* node, int key){
	if(node==NULL){
		Node* newNode = new Node(key);
		return newNode;
	}
	if(key < node->key){
		node->left = insert(node->left, key);
	}
	else{
		node->right = insert(node->right, key);
	}
 
	return node;
 
}
 
Node* search(Node* node, int key){
	if(node==NULL)
		return node;
	if(node->key == key)
		return node;
 
	if(key < node->key){
		return search(node->left, key);
	}
	else{
		return search(node->right, key);
	}
 
}
 
Node* findMinimum(Node* node){
	if(node==NULL)
		return node;
	Node* cur = node;
	while(cur->left!=NULL)
		cur = cur->left;
	return cur;
}

Node* findMaximum(Node* node){
	if(node==NULL)
		return node;
	Node* cur = node;
	while(cur->right!=NULL)
		cur = cur->right;
	return cur;
}

Node* deleteNode(Node* root, int key)
{
    if(root==NULL)
        return root;
    else if(key < root->key) 
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else
    {
        //No child
        if(root->right == NULL && root->left == NULL)
        {
            delete root;
            root = NULL;   
        }
        //One child 
        else if(root->right == NULL)
        {
            Node* temp = root;
            root= root->left;
            delete temp;
        }
        else if(root->left == NULL)
        {
            Node* temp = root;
            root= root->right;
            delete temp;
        }
        //two child
        else
        {
            Node* temp = findMinimum(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }
    return root;
}

int main()
{
    // ROOT = new Node(100);
    // Node* leftOfRoot = new Node(50);
    // ROOT->left = leftOfRoot;
    // Node* rightOfRoot = new Node(150);
    // ROOT->right = rightOfRoot;


    // cout << "Pre-order: ";
    // preorder(ROOT); // 100 50 150
    // cout << "\nIn-order: ";
    // inorder(ROOT); // 50 100 150
    // cout << "\nPost-order: ";
    // postorder(ROOT); // 50 150 100

    // Node* a = new Node(25);
    // leftOfRoot->left = a;

    // Node* b = new Node(175);
    // rightOfRoot->right = b;

    // cout << "\n\n";

    // cout << "Pre-order: ";
    // preorder(ROOT); // 100 50 25 150 175
    // cout << "\nIn-order: ";
    // inorder(ROOT); // 25 50 100 150 175
    // cout << "\nPost-order: ";
    // postorder(ROOT); // 25 50 175 150 100

    // cout << "\n";




    ROOT = insert (ROOT, 100);
    insert(ROOT, 50);
    insert(ROOT, 150);
    insert(ROOT, 20);
    insert(ROOT, 70);
    insert(ROOT, 200);
    insert(ROOT, 75);
    insert(ROOT, 25);
 
    //                  100
    //                  / \
    //                50   150
    //               /  \    \
    //              20  70    200
    //                \   \
    //                25   75
 
    deleteNode(ROOT, 100);
	cout << "pre-order: ";
	preorder(ROOT); // 100 50 20 10 70 75 150 200
	cout << endl << "in-order: ";
	inorder(ROOT); // 10 20 50 70 75 100 150 200
    cout << endl << "post-order: ";
    postorder(ROOT);
 
	Node* node = search(ROOT, 200);
	if(node!=NULL)
		cout << endl <<"Value exists" << endl;
	else
		cout << endl <<"Value doesn't exist" << endl;
 
 
	node = findMinimum(ROOT);
	if(node!=NULL)
		cout << "Minimum Value: " << node->key << endl;
    node = findMaximum(ROOT);
	if(node!=NULL)
		cout << "Maximum Value: " << node->key << endl;

    return 0;
}
