#include <iostream>
#include <math.h>

// ALSO KNOWN AS A PRIORITY QUEUE

class Heap
{

    public:
    int length;
    int* data;

    Heap()
    {
        this->length = 0;
        this->data = new int[10];
    }

    void insert(int value)
    {
        this->data[this->length] = value;
        this->heapifyUp(this->length);
        this->length++;
    }

    int pop()
    {
        if(this->length == 0){
            return -1;
        }

        int out = this->data[0];
        this->length--;

        if(this->length == 0){
            delete this->data;
            this->data = new int[10];
            return out;
        }
        this->data[0] = this->data[this->length];
        this->heapifyDown(0);
        return out; 
    }

    private:

    int parent(int idx){
        return floor((idx-1)/2);
    }

    int leftChild(int idx){
        return idx*2+1;
    }

     int rightChild(int idx){
        return idx*2+2;
    }
    
    void heapifyUp(int idx){
         
        // pre
        if(idx == 0){
            return;
        }

        int p = this->parent(idx);
        int pV = this->data[p];
        int v = this->data[idx];

        // recurse
        if(pV > v){
            this->data[idx] = pV;
            this->data[p] = v;
            this->heapifyUp(p);
        }
    }

    void heapifyDown(int idx){
       
        int leftIdx = this->leftChild(idx);
        int rightIdx = this->rightChild(idx);

        if(leftIdx >= this->length || idx >= this->length){
            return;
        }

        int lV = this->data[leftIdx];
        int rV = this->data[rightIdx];
        int v  = this->data[idx];

        if(lV >rV && v >rV){
            this->data[idx] = rV;
            this->data[rightIdx] = v;
            this->heapifyDown(rightIdx);
        }else if(rV>lV && v>lV){
            this->data[idx] = lV;
            this->data[leftIdx] = v;
            this->heapifyDown(leftIdx);
        }       
    }

};

int main()
{
    Heap* heap = new Heap();

    heap->insert(20);
    heap->insert(40);
    heap->insert(60);
    heap->insert(80);
    heap->insert(100);
    heap->insert(1);
    heap->insert(2);
    heap->insert(3);

    heap->pop();
    heap->pop();
    heap->pop();

    for(int i  = 0; i<heap->length;i++){
        std::cout<< heap->data[i] << ", ";
    }
};