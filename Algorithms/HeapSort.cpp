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


    // 3 steps

    // Step 1
    // left is the index of the left child
    // check to make sure its inside the bounds of the array
    // if the left child is larger than the parent then 
    // largest is now the index of the child

    int left = i * 2 + 1;
    int right = i * 2 + 2;
    int largest = i;

    if(left < N && arr[left] > arr[largest]){

        largest = left;

    }
    

    // Step 2
    // repeat step 1 but for the right child 
    // 
    
    if(right < N && arr[right] > arr[largest]){

        largest = right;

    }

    
    if(largest!=i){

        swap(&arr[i], &arr[largest]);

        heapify(arr, N, largest);

    }

   

    // If step 1 or 2 altered the value of largest 
    // swap the parent and the child then heapify 
    // largest, which traverse down the binary heap
    // to the next layer

} 






// N is the length of the array
// these loops are iterating over each half of the array backwards recursively
// the order of the second loop is reversed by the swap function
// Each instance of heapify should follow the binary heap down to the bottom

// first loop builds the heap
// because children are 2*i, we only need to do the first half of the array

// second array loops backwards over the entire array because it is changing
// the max heap into a min heap

void heapSort(int arr[], int N){


    for(int i = N/2 - 1; i>=0;i--){

        heapify(arr, N, i);

    }

    for(int i = N -1; i>=0; i--){

        swap(&arr[0], &arr[i]);

        heapify(arr, i, 0);

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

    int size = sizeof(arr)/ sizeof(arr[0]);

    heapSort(arr, size);

    printArray(arr, size);

}