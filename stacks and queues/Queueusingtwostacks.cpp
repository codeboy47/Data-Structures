#include<iostream>
#include"stackll.h"
//include"Queueusingtwostacks.h"
using namespace std;
int main() {
    QueueusingStacks <int> Q,s;
        for (int i = 0; i < 10; i++) {
            Q.enqueue(i*i);
        }
        cout<<endl<<"------------"<<endl;
        for (int i = 0; i < 10; i++) {
            Q.dequeue();
        }
}
