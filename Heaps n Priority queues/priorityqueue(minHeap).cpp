#include<iostream>
#include<vector>
using namespace std;
/// we are creating min heap
class pq{
    int index;
    int currentSize;
    vector<int> arr;
    void Heapify(int i){
        int min = i;
        while(i<index && ((2*i < index) && (2*i+1 < index))){
            int leftChild = 2*i;
            int rightChild = 2*i + 1;
            if(arr[i] > arr[leftChild]){
                min = leftChild;
            }
            if(arr[min] > arr[rightChild]){
                min = rightChild;
            }
            if(min!=i){
                swap(arr[i],arr[min]);
            }
            i = min;
        }
        /*
        int leftChild = 2*i;
        int rightChild = 2*i +1;
        int min = i;
        // If left child exists to uska index  index se kum hoga
        if(leftChild < index){
            if(arr[leftChild] < arr[i]){
                min = leftChild;
            }
        }
        if(rightChild < index){
            if(arr[rightChild] < arr[min]){
                min = rightChild;
            }
        }
        if(min != i){
            swap(arr[i],arr[min]);
            Heapify(min);
        }
        */
        return;
    }
public:
    pq(){
        currentSize = 0;
        index = 1;
        arr.push_back(-1);
    }
    void push(int data){
        arr[index] = data;
        currentSize++;
        int i = index;
        while(i>1){
            int parent = i/2;
            if(arr[parent] > arr[i]){
                swap(arr[parent],arr[i]);
                i = i/2;
            }else{
                break;
            }
        }
        index++;
    }
    int getMin(){
        return arr[1];
    }
    void removeMin() {
        swap(arr[1],arr[index-1]);
    //    arr[index-1] = -1;
        index--;
        currentSize--;
        Heapify(1);
        return;
    }
    int getIndex(){
        return index;
    }
    void print() {
        for(int i = 1;i < index;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

int main(){
    pq pq;
    pq.push(1);
    pq.push(3);
    pq.push(5);
    pq.push(0);
    pq.print();
    pq.removeMin();
    pq.push(7);
    pq.print();
    cout<<pq.getIndex()<<endl;
    pq.removeMin();
    pq.removeMin();
    pq.print();
    cout<<"minimum no in an array is : "<<pq.getMin()<<endl;
    return 0;
    /// 0 1 5 3  -> 1 3 5 7 -> 5 7
}
