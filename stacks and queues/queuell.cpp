#include<iostream>
#include"queuell.h"
using namespace std;
int main() {
    Queuell <int> Q,s;
        for (int i = 0; i < 10; i++) {
            Q.enqueue(i*i);
            s.enqueue(i);
        }
        s.show();
        s = Q;  // copy constructor
        s.show();
        cout<<endl<<"------------"<<endl;
        for (int i = 0; i < 5; i++) {
            cout << Q.getFront() << endl;
            Q.dequeue();
        }
        Q.show();
}
