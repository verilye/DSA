#include <iostream>

struct Node{
    Node* next;
    int data;
};

void BucketSort(int arr[]);
struct Node *InsertionSort(struct Node * list);
void print(int arr[]);
void printBuckets(struct Node *list);
int getBucketIndex(int value);


void BucketSort(int arr[]){




};


//Insertion sort with linked list

struct Node *InsertionSort(struct Node *list){

    struct Node *k, *nodeList;
    if(list == 0 || list->next == 0){
        return list;
    }

    nodeList = list;
    k = list->next;
    nodeList->next = 0;
    while(k!=0){
        
        struct Node *ptr;

        if(nodeList->data){
            struct Node *tmp;
            tmp = k;
            k = k->next;
            tmp->next = nodeList;
            nodeList = tmp;
            continue;
        }

        for(ptr = nodeList; ptr->next != 0; ptr = ptr->next){

            if(ptr->next->data > k->data){
                break;
            }
        }

        if(ptr->next !=0){
            struct Node *tmp;
            tmp = k;
            k = k->next;
            tmp->next = ptr->next;
            ptr->next = tmp;
            continue;
        }else{
            ptr->next = k;
            k = k->next;
            ptr->next->next = 0;
            continue;
        }
    }

    return nodeList;



};


// Print buckets
void printArray(int arr[], int n){

    for(int i =0; i<n;i++){

        std::cout<< arr[i]<<" ";

    }

    std::cout<<std::endl;
};


void printBuckets(struct Node *list) {
  struct Node *cur = list;
  while (cur) {

    std::cout<<list->data<<", ";

    cur = cur->next;
  }
}


int main(void) {
    int array[] = {42, 32, 33, 52, 37, 47, 51};

    std::cout << "Initial array: " << std::endl;

    int arraySize = sizeof(array)/ sizeof(array[0]);

    printArray(array, arraySize);
    std::cout << "-------------" << std::endl;

    BucketSort(array);
    std::cout << "-------------" << std::endl;
    std::cout << "Sorted array: " << std::endl;
    printArray(array, arraySize);
}