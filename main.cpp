#include <iostream>

// Linked List
// A series of nodes that are contiguously connected by next pointers
// A doubly linked list can have a previous pointers which allows for 
// reverse traversal

// Hash Table
// A linked list which has a second dimension of arrays or nodes

// Queue
// A queue is filo. When waiting in a queue, you cant push ahead
// and have to wait for everyone ahead of you to be processed first

// Stack 
// A stack is fifo. Place the pancake on the stack, you have to take the
// top one off first

// Insertion Sort
// Iterate through array and compare iterator value to previous values
// Compare to see if larger or smaller
// Throw small values back to their correct position in the array

// Merge Sort
// half array down into smallest possible pieces then re assemble in order
// Set up recursion by if(left = right) return
// mergesort(arr, left, mid)
// mergesort(arr,mid+1, right ) 
// merge(arr, begin, mid, end)
// break down left and right of subarrays
// Compare left and right subarrays in the merge function and swapsidaisies values
// so that they are in the correct position in the original array. 

// Quick Sort
// Mark a pivot value, find how many values its higher than to find its 
// correct spot in the array, repeat with recursion
// if(low>=high)
// int p = getPivot()
// quickSort(arr, p+1, r)
// quicSort(arr, l, p+1)



int isEmpty(int* top){

    return !top;

};

int main(){

    int* top = nullptr;

    std::cout<< isEmpty(top)<<std::endl;
    std::cout<< !isEmpty(top)<<std::endl;

};