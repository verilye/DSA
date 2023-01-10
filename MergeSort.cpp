#include <iostream>


void merge(int array[], int const left, int const mid, int const right){

    int const subArrayOne = mid - left +1;
    int const subArrayTwo = right - mid;

    int *leftArray = new int[subArrayOne],
        *rightArray = new int[subArrayTwo];

    for(int i = 0; i<subArrayOne; i++){
        leftArray[i] = array[left+i];
    }
    for(int j = 0; j<subArrayTwo; j++){
        rightArray[j] = array[mid+1+j];
    }

    int indexOfSubArrayOne = 0,
        indexOfSubArrayTwo = 0,
        indexOfMergedArray = left;


    while(indexOfSubArrayOne < subArrayOne
        && indexOfSubArrayTwo < subArrayTwo)
    {
        if(leftArray[indexOfSubArrayOne]
            <=rightArray[indexOfSubArrayTwo]){
            
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;

        }
        else {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }

    while(indexOfSubArrayOne<subArrayOne){

        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;

    }

    while(indexOfSubArrayTwo< subArrayTwo){

        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;

    }

    delete[] leftArray;
    delete[] rightArray;

}

// Declare left and right var which will mark the extreme indices of the array
// Left will be assigned to 0 and right will be assigned to n-1
// Find mid = (left+right)/2
// Call mergeSort on (left,mid) and (mid+1,rear)
// Above will continue till left<right
// Then we will call merge on the 2 subproblems

void mergeSort(int array[], int const begin, int const end){

    if(begin>=end)
        return;

    auto mid = begin + (end - begin)/2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid+1, end);
    merge(array, begin, mid, end);



}


void printArray(int arr[], int arraySize){

    for(int i =0; i<arraySize; i++){

        std::cout<<arr[i]<<" ";

    }

    std::cout<<std::endl;

    return;
}


int main(){

    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int arr_size = sizeof(arr) / sizeof(arr[0]);
 
    mergeSort(arr, 0, arr_size - 1);
    
    printArray(arr, arr_size);
    
    return 0;

}