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

Node *binaryTreeOne()
{
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
};

Node *binaryTreeTwo()
{
    Node *head = new Node(20);
    head->right = new Node(50);
    head->right->right = new Node(100);
    head->right->left = new Node(30);
    head->right->left->right = new Node(49);
    head->right->left->left = new Node(29);
    head->left = new Node(10);
    head->left->right = new Node(15);
    head->left->left = new Node(5);
    head->left->left->right = new Node(7);
    return head;
};

bool compare(Node *tree1, Node *tree2)
{
    // Depth first preserves the structure of the tree
    // Depth first on both trees simultaneosly and compare values
    if (tree1 == nullptr && tree2 == nullptr)
    {
        return true;
    }

    if (tree1 == nullptr || tree2 == nullptr)
    {
        return false;
    }

    if (tree1->value != tree2->value)
    {
        return false;
    }

    if(compare(tree1->left, tree2->left) == false){
        return false;
    };

    if(compare(tree1->right, tree2->right)==false){
        return false;
    };
   

    return true;
}

int main()
{

    Node *tree1 = binaryTreeOne();
    Node *tree2 = binaryTreeTwo();

    bool test1 = compare(tree1, tree2);
    bool test2 = compare(tree1, tree1);

    std::cout << "Test 1 :" << test1 << std::endl;
    std::cout << "Test 2 :" << test2 << std::endl;
}