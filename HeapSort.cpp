#include <iostream>


// max heaps are good for heapsorts 
// min heaps are good for priority queues

// Heaps are stored in an array top to bottom left to right
// a node's left child is the index *2
// a node's right child is the index *2 +1
// a node's parent is index/2 rounded down
// normally the root is left at index 1 rather than 0?



//swap 2 values

void swap(int* a, int* b){

    int temp = *b;
    *b = *a;
    *a = temp;
    
}


// is called recursively for each value in the array
// is is a node

void heapify(int arr[], int N, int i){

    int largest = i;

    int left = 2*i+1;

    int right = 2*i+2;

    if(left<N && arr[left]> arr[largest]){

        largest = left;
    }

    if(right<N && arr[right]> arr[largest]){

        largest = right;
    }

    if(largest!= i){

        swap(&arr[i], &arr[largest]);

        heapify(arr,N,largest);

    }

}



// 
// N is the length of the array
// these loops are iterating over each half of the array backwards recursively
// the order of the second loop is reversed by the swap function

void heapSort(int arr[], int N){

    for(int i = N/2 -1; i>=0;i--){
        heapify(arr,N,i);
    }

    for(int i =N-1;i>=0;i--){

        swap(&arr[0], &arr[i]);

        heapify(arr,i,0);
    }


}

void printArray(int arr[], int n){

    for(int i =0; i<n;i++){

        std::cout<< arr[i]<<" ";

    }

    std::cout<<std::endl;

};

int main(){

    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int N = sizeof(arr) / sizeof(arr[0]);
  
    // Function call
    heapSort(arr, N);
    printf("Sorted array is\n");
    printArray(arr, N);

}