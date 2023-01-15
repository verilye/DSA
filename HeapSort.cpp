#include <iostream>


// Find the minimum element then place the minimum element at the beginning,
// repeat 

void swap(int* a, int* b){

    int temp = *b;
    *b = *a;
    *a = temp;
    
}


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