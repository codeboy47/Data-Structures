/*#ifndef QUEUE_USING_TWO_STACKS_H
#define QUEUE_USING_TWO_STACKS_H
//#include"stackll.h"
#include<stack>
template <typename T>
class QueueusingStacks {
    stack<T> s1;
    stack<T> s2;
    public:
    void enqueue(const T & el) {
        s1.push(el);
    }
    void dequeue() {
        while (s1.top!=0) {
            s2.push(s1.top());
            s1.pop();
        }
        s2.pop();
        while (s2.top!=0) {
            s1.push(s2.top());
            s2.pop();
        }
    }
};
#endif*/
class QueueusingStacks {
    stack<int> s1;
    stack<int> s2;

    void enqueue(const T & el) {
        s1.push(el);
    }
    void dequeue() {
        while (!s1.isEmpty()) {
            s2.push(s1.top());
            s1.pop();
        }
        s2.pop();
        while (!s2.isEmpty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }
}
