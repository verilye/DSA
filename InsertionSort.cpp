#include <iostream>

// Pseudocode

// for i:1 to length(A)-1
// j=1
// while j>0 and A[j-1] > A[j]
//      swap A[j] and A[j-1]
//      j = j-1;

//Big O(n^2)


void insertionSort(int arr[], int arraySize){

    for(int i = 1; i< arraySize; i++){

        int key = arr[i];
        int j = i-1;

        while(j>=0 && arr[j] > key){

            arr[j+1] = arr[j];

            j = j-1;

        }

        arr[j+1] = key;

    }
    
};


void printArray(int arr[], int n){

    for(int i =0; i<n;i++){

        std::cout<< arr[i]<<" ";

    }

    std::cout<<std::endl;

};


int main(){

    int arr[] = { 12, 11, 13, 5, 6 };
    int N = sizeof(arr) / sizeof(arr[0]);
 
    insertionSort(arr, N);
    printArray(arr, N);
 
    return 0;

};