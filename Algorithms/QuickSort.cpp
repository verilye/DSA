#include <iostream>

using namespace std;


// The quicksort finds the correct postion of 1 value
// by putting all lower values to the left, iterating once
// then swapping to that location. Repeat until all of these
// incorrect 'partitions' are sorted


//Swap two elements 
  
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
  

// sort each value between low and high that arent the pivot
// store the low values in a counter

int partition(int arr[], int low, int high)
{

    int pivot = arr[high];
    int counter = (low - 1);

    for(int j = low; j<= high - 1; j++){

        if(arr[j] < pivot){
            counter++;
            swap(&arr[counter], &arr[j]);
        }
    }

    swap(&arr[counter + 1], &arr[high]);
    return counter + 1;

}



// A single quicksort finds the correct position of the pivot in the array
// by putting all smaller values before it
// Once we find the correct location of a single value, it creates 'partitions'
// that are incorrect around the correct value, breaking down the values that 
// need to be sorted into smaller groups

void quickSort(int arr[], int low, int high)
{
    //break point when low and high intersect
    //find the partion, quicksort both sides recursively


    if(low<high){

        int p = partition(arr, low, high);

        quickSort(arr, low, p -1);
        quickSort(arr, p + 1, high);
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