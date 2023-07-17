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

Node *createBinaryTree()
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

class QueueNode
{
public:
    Node *data;
    QueueNode *next = nullptr;
    QueueNode(Node *data)
    {
        this->data = data;
    };
};

class Queue
{
public:
    int counter = 0;
    QueueNode *head = nullptr;
    QueueNode *tail = nullptr;

    void enqueue(Node *node)
    {
        QueueNode *next = new QueueNode(node);
        counter++;

        if (tail == nullptr)
        {
            
            tail = next;
            tail->next = nullptr;
            head = tail;
            
        }else
        {
            tail->next = next;
            tail = tail->next;
            tail->next = nullptr;
        }
    }

    Node *dequeue()
    {
        if (head->next == nullptr)
        {
            counter = 0;
            return head->data;
        }

        QueueNode *temp = head;
        Node* data = temp->data;
        head = head->next;

        delete temp;
        return data;
    }
};

bool BFS(Node *head, int needle, Queue *queue)
{

    queue->enqueue(head);

    while (queue->counter > 0)
    {

        Node *current = queue->dequeue();

        if (current->value == needle)
        {
            delete queue;
            return true;
        }

        if (current->left != nullptr)
        {
            queue->enqueue(current->left);
        }
        if (current->right != nullptr)
        {
            queue->enqueue(current->right);
        }
    }

    delete queue;
    return false;
};

int main()
{
    Node *head = createBinaryTree();
    Queue *queue = new Queue();

    std::cout << BFS(head, 45, queue) << std::endl;
    queue = new Queue();
    std::cout << BFS(head, 7, queue) << std::endl;
    queue = new Queue();
    std::cout << BFS(head, 69, queue) << std::endl;
}