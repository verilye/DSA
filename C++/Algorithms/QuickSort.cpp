#include <iostream>

int partition(int arr[], int lo, int hi)
{
    int pivot = arr[hi];
    int index = lo -1;

    for(int i =lo;i<hi;i++){
        if(arr[i]<=pivot){
            index++;
            int temp = arr[i];
            arr[i] = arr[index];
            arr[index] = temp;
        }
    }

    index++;
    arr[hi] = arr[index];
    arr[index] = pivot; 

    return index;
}

void quick_sort(int arr[], int lo, int hi)
{
    if(lo >=hi){
        return;
    }

    int pivotIndex = partition(arr,lo,hi);

    quick_sort(arr,lo,pivotIndex -1);
    quick_sort(arr,pivotIndex + 1, hi);

    return;
};

int main()
{
    int arr[] = {9, 3, 7, 4, 96, 420, 42};
    int arrLength = (sizeof(arr) / sizeof(arr[0]));

    quick_sort(arr, 0, arrLength - 1);

    for (int i = 0; i < arrLength; i++)
    {
        std::cout << arr[i]<<",";
    }

    std::cout<< std::endl;

    return 1;
}; 