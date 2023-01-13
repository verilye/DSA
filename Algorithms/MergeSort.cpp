#include <iostream>

// Splitting the original array into two smaller arrays
// transcribe the values of the original array into the smaller ones
// Iterating along both sub arrays, while loop in case they arent even
// Does nothing on first recursion
// Work through both arrays, assigning the smallest values to the left
// catch edge cases where left array and right array are one index?
 // clear up memory of the two temp arrays;

void merge(int array[], int const left, int const mid, int const right){

    //get length of 2 arrays

    auto const subArrayLeftLength = mid - left +1;
    auto const subArrayRightLength = right - mid;

    //init 2 arrays

    auto* subArrayLeft = new int[subArrayLeftLength];
    auto* subArrayRight = new int[subArrayRightLength];

    //populate the arrays

    for(int i =0; i<subArrayLeftLength; i++){
        
        subArrayLeft[i] = array[left+i];
        
    }
    // for(int i =0; i<subArrayLeftLength; i++){
        
    //     std::cout<< subArrayLeft[i]<< " ";
        
    // }

    // std::cout<< "banana ";


    for(int j =0; j<subArrayRightLength; j++){
        
        subArrayRight[j] = array[mid+j+1];
        
    }

    //set iterators for arrays

    int leftArray = 0,
        rightArray = 0,
        mergedArray = left;


    while( leftArray < subArrayLeftLength &&
            rightArray < subArrayRightLength){
        
        if(subArrayLeft[leftArray]<= subArrayRight[rightArray]){


            array[mergedArray] = subArrayLeft[leftArray];

            leftArray++;
           

        }else{

            array[mergedArray] = subArrayRight[rightArray];

            rightArray++;
            

        }

        mergedArray++;
        
    }

    while(leftArray<subArrayLeftLength){

        array[mergedArray] = subArrayLeft[leftArray];
        leftArray++;
        mergedArray++;

    }

    while(rightArray< subArrayRightLength){

        array[mergedArray] = subArrayRight[rightArray];
        rightArray++;
        mergedArray++;

    }
    
    delete [] subArrayLeft;
    delete [] subArrayRight;

}


// end the recursion by returning when size of array is a single cell

// Mergesort both sides of the array Recursively

// find the mid point for each subarray by getting the end of the array
// subtract the beginning and divide by 2

// halve the array down into single cells
// merge the half arrays back together


void mergeSort(int array[], int const begin, int const end){

    if(begin>=end){
        return;
    }

    //find middle

    int mid = begin + (end - begin)/2;

    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
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

    int arr[] = { 12, 11, 13, 5, 6, 7, 12, 11, 13, 5, 6, 7, 100 };
    int arr_size = sizeof(arr) / sizeof(arr[0]);
 
    mergeSort(arr, 0, arr_size - 1);
    
    printArray(arr, arr_size);
    
    return 0;

}