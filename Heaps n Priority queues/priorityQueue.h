#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H
#include<vector>
#include<iostream>
using namespace std;
class PriorityQueue{
    vector<int> arr;
    int currentSize;
    int index;

    void heapify(int i){

      /*  while(i<index-1 ){
            int leftChild = 2*i;
            int rightChild = 2*i + 1;
            if( arr[leftChild] > arr[i] && arr[leftChild] > arr[rightChild]){
                swap(arr[i],arr[leftChild]);

            }
            if(arr[rightChild] > arr[i]  && arr[rightChild] > arr[leftChild]){
                swap(arr[i],arr[rightChild]);
                max = rightChild;
            }
            i = max;
        }*/
        int leftChild = 2*i;
        int rightChild = 2*i +1;
        int max = i;
        // If left child exists to uska index  index se kum hoga
        if(leftChild < index){
            if(arr[leftChild] > arr[i]){
                max = leftChild;
            }
        }
        if(rightChild < index){
            if(arr[rightChild] > arr[max]){
                max = rightChild;
            }
        }
        if(max != i){
            swap(arr[i],arr[max]);
            heapify(max);
        }
        return;
    }

    public:
    PriorityQueue() {
        index = 1;
        currentSize = 0;
        arr.push_back(-1);
    }
    void push(int data) {
        arr[index] = data;
        index++;
        int i = index - 1;
        while(i>1) {
            int parent = i/2;
            if(arr[i] > arr[parent]){
                swap(arr[i],arr[parent]);
                i = i/2;
            }else{
                break;
            }
        }
    }
    int getMax(){
        return arr[1];
    }
    int getIndex(){
        return index;
    }
    void removeMax(){
        swap(arr[index-1],arr[1]);
        index--;
        currentSize--;
        heapify(1);
    }

    void print(){
        for(int i=1;i<index;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};
#endif
