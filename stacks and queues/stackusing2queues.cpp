#include<iostream>
#include"queuell.h"
//#include"QueueAsDynamicArray.h"
using namespace std;
int main() {
    stackusing2queues<int> S;
        for (int i = 0; i < 10; i++) {
            S.push(i*i);
        }
        cout<<"------------";
        for (int i = 0; i < 10; i++) {
            //cout << S.Top() << endl;
            S.pop();
        }
}
