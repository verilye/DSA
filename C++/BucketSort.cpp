// Bucket sort in C++

#include <iomanip>
#include <iostream>
using namespace std;

#define NARRAY 7    // Array size
#define NBUCKET 6   // Number of buckets
#define INTERVAL 10 // Each bucket capacity

struct Node
{
    int data;
    struct Node *next;
};

void BucketSort(int arr[]);
struct Node *InsertionSort(struct Node *list);
void print(int arr[]);
void printBuckets(struct Node *list);
int getBucketIndex(int value);

// Sorting function
void BucketSort(int arr[])
{
    int i, j;

    //Create an array that fits pointers to Node structs inside
    struct Node **buckets;
    buckets = (struct Node **)malloc(sizeof(struct Node *) * NBUCKET);

    // Initialize empty buckets
    for (i = 0; i < NBUCKET; ++i)
    {
        buckets[i] = NULL;
    }

    

    for (i = 0; i < NARRAY; ++i)
    {
        struct Node *current;
        // Divide value in array by the number of buckets to sort
        // value into its correct bucket 
        int pos = getBucketIndex(arr[i]);

        // Allocate mem for empty node
        current = (struct Node *)malloc(sizeof(struct Node));
        // Set empty node's data to array value
        current->data = arr[i];
        // set new node's next to the linked list that is contained
        // in the bucket
        current->next = buckets[pos];
        // set new node as the head of the linked list in the bucket
        buckets[pos] = current;
    }

    // // Print the buckets along with their elements
    // for (i = 0; i < NBUCKET; i++)
    // {
    //     cout << "Bucket[" << i << "] : ";
    //     printBuckets(buckets[i]);
    //     cout << endl;
    // }

    // Do the insertion sort w/Linked List
    for (i = 0; i < NBUCKET; ++i)
    {
        buckets[i] = InsertionSort(buckets[i]);
    }

    // cout << "-------------" << endl;
    // cout << "Bucktets after sorted" << endl;
    // for (i = 0; i < NBUCKET; i++)
    // {
    //     cout << "Bucket[" << i << "] : ";
    //     printBuckets(buckets[i]);
    //     cout << endl;
    // }

    // Go through each bucket and spit linked lists
    // out into array
    for (j = 0, i = 0; i < NBUCKET; ++i)
    {
        struct Node *node;
        node = buckets[i];
        while (node)
        {
            arr[j++] = node->data;
            node = node->next;
        }
    }

    // go through and delete the memory that was taken up by the node structs
    for (i = 0; i < NBUCKET; ++i)
    {
        struct Node *node;
        node = buckets[i];
        while (node)
        {
            struct Node *tmp;
            tmp = node;
            node = node->next;
            free(tmp);
        }
    }

    //delete the array
    free(buckets);
    return;
}

// Function to sort the elements of each bucket
struct Node *InsertionSort(struct Node *list)
{
    struct Node *k, *nodeList;
    if (list == 0 || list->next == 0)
    {
        return list;
    }

    nodeList = list;
    k = list->next;
    nodeList->next = 0;
    while (k != 0)
    {
        struct Node *ptr;
        if (nodeList->data > k->data)
        {
            struct Node *tmp;
            tmp = k;
            k = k->next;
            tmp->next = nodeList;
            nodeList = tmp;
            continue;
        }

        for (ptr = nodeList; ptr->next != 0; ptr = ptr->next)
        {
            if (ptr->next->data > k->data)
                break;
        }

        if (ptr->next != 0)
        {
            struct Node *tmp;
            tmp = k;
            k = k->next;
            tmp->next = ptr->next;
            ptr->next = tmp;
            continue;
        }
        else
        {
            ptr->next = k;
            k = k->next;
            ptr->next->next = 0;
            continue;
        }
    }
    return nodeList;
}

int getBucketIndex(int value)
{
    return value / INTERVAL;
}

// Print buckets
void print(int ar[])
{
    int i;
    for (i = 0; i < NARRAY; ++i)
    {
        cout << setw(3) << ar[i];
    }
    cout << endl;
}


void printBuckets(struct Node *list)
{
    struct Node *cur = list;
    while (cur)
    {
        cout << setw(3) << cur->data;
        cur = cur->next;
    }
}

// Driver code
int main(void)
{
    int array[NARRAY] = {42, 32, 33, 52, 37, 47, 51};

    // cout << "Initial array: " << endl;
    // print(array);
    // cout << "-------------" << endl;

    BucketSort(array);
    // cout << "-------------" << endl;
    // cout << "Sorted array: " << endl;
    print(array);
}