#include <iostream>

using namespace std;


// The quicksort finds the correct postion of 1 value
// by putting all lower values to the left, iterating once
// then swapping to that location. Repeat until all of these
// incorrect 'partitions' are sorted


//Swap two elements 
  
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
  

// 

int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // pivot
    int counter = (low - 1); //keep track of all small values sent to the front


    // iterate through values and swap all values lower than pivot to the front
  
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            counter++;
            swap(&arr[counter], &arr[j]);
        }
    }

    // moving the value to this position guarantees that it is in the correct postion
    // in the array, then we can quicksort every value before and after it

    swap(&arr[counter + 1], &arr[high]);
    return (counter + 1);
}



// A single quicksort finds the correct position of the pivot in the array
// by putting all smaller values before it
// Once we find the correct location of a single value, it creates 'partitions'
// that are incorrect around the correct value, breaking down the values that 
// need to be sorted into smaller groups

void quickSort(int arr[], int low, int high)
{
    if (low < high) {

        int correctIndex = partition(arr, low, high);

        quickSort(arr, low, correctIndex - 1);
        quickSort(arr, correctIndex + 1, high);
    }
}
  
/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
  
// Driver Code
int main()
{
    int arr[] = { 10, 7, 8, 9, 1, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1);
    cout << "Sorted array: \n";
    printArray(arr, n);
    return 0;
}