//
// Created by elshi on 12/22/2023.
//
#include <iostream>
int GetLeftChild(int i){
    return 2*i + 1;
}
int GetRightChild(int i){
    return 2*i + 2;
}
int GetParent(int i){
    return (i-1)/2;
}
using namespace std;
template <class T>
class MaxHeap{
private:
    T* Array;
    int size;
public:
    void MaxHeapfiy(int index){
    int left = GetLeftChild(index);
    int right = GetRightChild(index);
    int MaxElement = index;

    // Corrected comparisons
    if(left < size && Array[left] > Array[MaxElement]) MaxElement = left;
    if(right < size && Array[right] > Array[MaxElement]) MaxElement = right;

    if (MaxElement != index) {
        std::swap(Array[index], Array[MaxElement]);
        MaxHeapfiy(MaxElement);
    }
}

    void BulidMaxHeap(T arr[] ,int size ){
        this->size = size;
        Array = arr;
        for(int i = (size/2)-1 ; i >= 0; i--){
            MaxHeapfiy(i);
        }

    }
    void Print(){
        for(int i =0 ; i<size ;i++){
            cout<<Array[i]<<" ";
        }
    }
    void HeapSort(){
        int tmp=size;
        for(int i = size - 1;i>=0;i--){
            std::swap(Array[0],Array[i]);
            size--;
            MaxHeapfiy(0);
        }
        size=tmp;
    }
    bool NeedsBubleUp(int index){
        int parent = GetParent(index);
        if(index < size && Array[index] > Array[parent]){
            return true;
        }
        return false;
    }
    void push(T val){
        Array[size] = val;
        size++;
        int index = size-1;
        while (NeedsBubleUp(index)){
            std::swap(Array[index],Array[GetParent(index)]);
            index = GetParent(index);

        }
    }
    bool NeedsBubbleDown(int index) {
        int left = GetLeftChild(index);
        int right = GetRightChild(index);

        return (left < size && Array[left] > Array[index]) ||
               (right < size && Array[right] > Array[index]);
    }

    void pop() {
        if (size == 0) return;

        Array[0] = Array[size - 1];
        size--;

        int index = 0;
        while (true) {
            int maxIndex = index;
            int left = GetLeftChild(index);
            int right = GetRightChild(index);

            if (left < size && Array[left] > Array[maxIndex]) {
                maxIndex = left;
            }

            if (right < size && Array[right] > Array[maxIndex]) {
                maxIndex = right;
            }

            if (maxIndex != index) {
                std::swap(Array[index], Array[maxIndex]);
                index = maxIndex;
            } else {
                break;
            }
        }
    }
};


int main(){
    MaxHeap<int> maxHeap;
    int arr[5] = {1,2,3,4,5};
    maxHeap.BulidMaxHeap(arr,5);
    maxHeap.Print();
    cout<<"\n";
    maxHeap.push(99);
    maxHeap.Print();
    maxHeap.pop();
    cout<<"\n";
    maxHeap.Print();
}