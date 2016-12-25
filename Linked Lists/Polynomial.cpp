#include<iostream>
#include "polynomial.h"
using namespace std;
int main() {
    Polynomial<int> P1;
       P1.insertTerm(1,0);
       P1.insertTerm(2,2);
       P1.insertTerm(3,4);
       P1.insertTerm(3,1);
    Polynomial<int> P2;
        P2.insertTerm(2,1);
        P2.insertTerm(4,3);
    P1+=P2;
    cout << P1 << endl ;
}
