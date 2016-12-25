#include<iostream>
#include"stackll.h"
using namespace std;
int main() {
    Stackll<int> S;
        for (int i = 0; i < 10; i++) {
            S.push(i*i);
        }
        cout<<"------------";
        for (int i = 0; i < 10; i++) {
            cout << S.Top() << endl;
            S.pop();
        }
}
