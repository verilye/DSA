#include <iostream>

// insert, delete, search, traversal


class LinkedList{

    public:
        int length;
        Node* head;
        LinkedList(){
            length = 0;
        };
        void insert(Node* givenNode, int data){
            Node* newNode = new Node(data);

            newNode->next = givenNode->next;

            givenNode->next = newNode;

        };
        void remove(int index){

        };
        void search(){

        };
        void traversal(){

        };
        

};

class Node{
    
    public:
    Node* next;
    int data;
    Node(int d){
        data = d;
    };

};

int main(){



};