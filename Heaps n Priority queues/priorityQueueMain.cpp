#include<iostream>
#include "priorityQueue.h"
using namespace std;
int main(){
    PriorityQueue pq;
    pq.push(1);
    pq.push(3);
    pq.push(5);
    pq.push(0);
    pq.print();
    pq.removeMax();
    pq.push(7);
    pq.print();
    cout<<pq.getIndex()<<endl;
    pq.removeMax();
    pq.removeMax();
    pq.print();
    cout<<"max no is : "<<pq.getMax();
    return 0;
}
