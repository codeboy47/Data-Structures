#include<iostream>
#include "Queue.h"
using namespace std;

int main(){
	Queue q1;
	q1.enQueue(1);
	q1.enQueue(2);
	q1.enQueue(3);
	q1.enQueue(4);
	q1.enQueue(5);
	q1.enQueue(6);
	cout<<"last element is "<<q1.getRear()<<endl;
	cout<<"front is "<<q1.getFront()<<endl;
	cout<<"last element is "<<q1.getRear()<<endl;
	cout<<q1.deQueue()<<endl;
	cout<<"now front is "<<q1.getFront()<<endl;
	cout<<"last element is "<<q1.getRear()<<endl;
	cout<<q1.deQueue()<<endl;
	cout<<q1.deQueue()<<endl;
	cout<<q1.deQueue()<<endl;
	cout<<"now front is "<<q1.getFront()<<endl;
	cout<<q1.deQueue()<<endl;
	cout<<q1.deQueue()<<endl;
	cout<<"now front is "<<q1.getFront()<<endl;
	cout<<"last element is "<<q1.getRear()<<endl;

	cout<<endl;
	Queue q3(100);
	q3.enQueue(5);
	q3.enQueue(6);
	q3.enQueue(7);
	cout<<"front is "<<q3.getFront()<<endl;
	cout<<"last element is "<<q3.getRear()<<endl;
	q3.deQueue();
	cout<<"front is "<<q3.getFront()<<endl;
	cout<<"last element is "<<q3.getRear()<<endl;
	q3.deQueue();
	q3.enQueue(8);
	q3.enQueue(9);
	q3.enQueue(10);
	cout<<"front is "<<q3.getFront()<<endl;
	cout<<"last element is "<<q3.getRear()<<endl;
	q3.deQueue();
	q3.deQueue();
	q3.enQueue(1);
	q3.enQueue(2);
	q3.enQueue(3);
	q3.deQueue();
	cout<<"front is "<<q3.getFront()<<endl;
	cout<<"last element is "<<q3.getRear()<<endl;
	cout<<endl;

	return 0;
}