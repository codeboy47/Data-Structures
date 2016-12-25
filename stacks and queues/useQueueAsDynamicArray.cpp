#include<iostream>
#include"QueueAsDynamicArray.h"
using namespace std;
int main() {
    QueueAsDA<int> Q;
    for (int i =0; i < 30; i++) {
//        cout << " Enqueue" << endl;
        Q.enqueue(i);
    }
    for (int i = 0;i < 10;i++) {
        cout << Q.getFront() << endl;
        Q.dequeue();
    }
    for (int i = 0; i < 10; i++) {
        Q.enqueue(i*i);
    }
    while (!Q.isEmpty()) {
        cout << Q.getFront() <<" ";
        Q.dequeue();
    }
    cout << endl;
    for (int i =0; i < 32; i++) {
        Q.enqueue(i*i);
    }
    Q.reverse();
    while (!Q .isEmpty()) {
        cout << Q.getFront() <<" ";
        Q.dequeue();
    }
    cout << endl;
    return 0;
}
