#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

void printList(struct Node* head){

    while(head!=NULL){
        
        printf("%d \n", head->data);
        head = head->next;

    }

}

int main(){

    struct Node* head = NULL;
    struct Node* two = NULL;
    struct Node* three = NULL;


    // allocate space to heap

    head = (struct Node*)malloc(sizeof(struct Node));
    two = (struct Node*)malloc(sizeof(struct Node));
    three = (struct Node*)malloc(sizeof(struct Node));

    head->next = two;
    head->data = 1;

    two->next = three;
    two->data = 2;

    three->next = NULL;
    three->data = 3;

    printList(head);

};