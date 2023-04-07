#include <stdio.h>
#include <stdlib.h>


void insertionSort(int arr[], int n){

    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
 
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }

};


void printArr(int arr[], int size){

    for(int i = 0; i<size; i++){
        printf("%d ,", arr[i]);
    }

};

int main(){

    

    int arr[] = { 12, 11, 13, 5, 6 };
    int size = sizeof(arr)/sizeof(arr[0]);

    printArr(arr, size);


    return 1;
};