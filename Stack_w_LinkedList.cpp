#include <iostream>


class Node{
    public:
    int data;
    Node* next;  
    Node(int d){
        data=d;
    }
};

int isEmpty(Node* top){

    return !top;

}

void push(Node** top, int data){

    Node* newNode = new Node(data);

    newNode->next = *top;

    *top = newNode;

    std::cout<< data << std::endl;

    return;

}

int pop(Node** top){

    if(isEmpty(*top))
    return -1;

    Node* temp = *top;

    *top = (*top)->next;

    int data = temp->data;

    delete temp;

    return data;

}


int main(){

    Node* top = NULL;

    push(&top,1);
    push(&top,2);
    push(&top,3);

    while(!isEmpty(top)){

        std::cout<< pop(&top) << std::endl;

    }
}