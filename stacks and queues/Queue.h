#ifndef QUEUE_H
#define QUEUE_H
#include<iostream>
using namespace std;

// circular queue of array implementation
class Queue{
	int *arr;
	int currentSize; // total elements in queue is actual size but less than or equal to capacity
	int capacity; // max size or limit 

	int front;
	int rear;
public:
	Queue(){
		arr = new int[5];
		currentSize = 0; // since elements inserted are zero 
		capacity = 5;	// length or limit upto which elements can be filled
		front = 0;
		rear = 4;
	}
	Queue(int size){
		arr = new int[size];
		currentSize = 0;	// min : 0  & max : size - 1
		capacity = size;
		front = 0;
		rear = size - 1;
	}

	bool isFull(){
		return currentSize == capacity? true : false;
	}

	bool isEmpty(){
		return currentSize == 0? true : false;
	}

	void enQueue(int data){
		if(isFull()){
			cout<<"Sorry queue is full. Overflow condition !!"<<endl;
		}else{
			rear = ((rear + 1) % capacity); // we change rear first 
			arr[rear] = data;
			//rear = ((rear + 1) % capacity); this is wrong because arr[rear] will get garbage value
			// and point to position 0 i.e. arr[rear] = arr[0] in case of full queue 
			currentSize++;
		}
	}

	int deQueue(){
		if(isEmpty()){
			cout<<"Sorry queue is empty. Underflow condition !!"<<endl;
			return -1;
		}else{
			int temp = arr[front];
			front = (front+1)%capacity;
			currentSize--;
			return temp;
		}
	}

	int getFront(){
		if(isEmpty()){
			cout<<"Underflow condition !!! "<<endl;
			return -1;
		}
		return arr[front];
	}

	int getRear(){
		if(isEmpty()){
			cout<<"Underflow condition !!! "<<endl;
			return -1;
		}
		return arr[rear];
	}

	int actualSize(){
		return currentSize;
	}

	~Queue(){
		delete [] arr;
		arr = NULL;
	}
};

#endif
