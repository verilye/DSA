#include <iostream>

class Node
{
public:
    int value;
    Node(int value)
    {
        this->value = value;
    }

    Node *left = nullptr;
    Node *right = nullptr;
};

Node * createBinaryTree(){
    Node *head = new Node(20);
    head->right = new Node(50);
    head->right->right = new Node(100);
    head->right->left = new Node(30);
    head->right->left->right = new Node(45);
    head->right->left->left = new Node(29);
    head->left = new Node(10);
    head->left->right = new Node(15);
    head->left->left = new Node(5);
    head->left->left->right = new Node(7);
    return head;
}


int * walk(Node* node, int* path, int* counter){

    // base case - if children do not exist

    if(node == nullptr){
        return path;
    }

    // recursion steps
    // pre
    walk(node->left, path, counter);
    // recurse
    path[*counter] = node->value;
    *counter = *counter + 1;
    
    walk(node->right, path, counter);
    // post 
    return path;


}

int main()
{
    int * arr = new int[10];
    int counter = 0; 
    int* counterptr = &counter;
    Node* head = createBinaryTree();

    walk(head, arr, counterptr);

    for(int i =0; i<10; i++){
        std::cout<< arr[i] << ", ";
    }



}