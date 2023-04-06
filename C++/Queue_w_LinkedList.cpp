#include <iostream>

class Node{
    public:
    int data;
    Node* next;
    Node(int d){
        data = d;
    }
};

Node* head = NULL;
Node* tail = NULL;

void enQueue(int data){

    if(tail == NULL){
        Node* newNode = new Node(data);
        tail = newNode;
        tail->next = NULL;
        head = tail;

        return;
    }else{

        Node* newNode = new Node(data);

        tail->next = newNode;

        newNode->next = NULL;

        tail = newNode;

        return;
    }

};

int deQueue(){

    // get node head is pointing to
    // assign head data to temp variable
    // assign head to next node
    // free the memory of the old head
    // return the data
    
    Node* temp = head;

    int data = temp->data;

    head = head->next;

    delete temp;

    return data;

};

int main(){

    enQueue(1);
    enQueue(2);
    enQueue(3);
    std::cout<<deQueue()<<std::endl;
    std::cout<<deQueue()<<std::endl;
    std::cout<<deQueue()<<std::endl;

}