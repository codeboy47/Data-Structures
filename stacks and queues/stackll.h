#ifndef stackll
#define stackll
#include<iostream>
#include<exception>
using namespace std;
class StackEmptyException : public exception {
    public:
        virtual char const * what() const throw () { return "Stack is Empty";}
};
template <typename T>
class Node {
    T data;
    Node * next;
    public:
    Node() : next(0) {}
    Node(const T & el) : data(el), next(0) {}
    Node(const T & el, Node * ad): data(el), next(ad) {}
    T getData() const {
        return data;
    }
    template <typename V>
        friend class Stackll;
    template <typename Y>
        friend class QueueusingStacks;
};
template <typename T>
class Stackll {
    public:
    Node<T>  *top;
    void clear(){
        while(top!=0){
            Node<T> * it=top->next;
            delete top;
            top=it;
        }
    }
    void copy(Stackll & s){
        clear();
        Node<T> * it=s.top,*prev=0;
        while(it!=0){
            Node<T> * temp = new Node<T>(*it);
            if(top==NULL){
                top=s.top;
            }
             else{
                prev->next=temp;
            }
            prev=temp;
            it=it->next;
        }
    }
    //public:
    Stackll() : top(0) { }
    Stackll(Stackll & s) : top(0) {
        copy(s);
    }
    ~Stackll(){
        clear();
    }
    void pop(){
        if(top==NULL){
          return;
          //  throw StackEmptyException();
        }
        Node<T> *it=top;
        top=top->next;
        delete it;
    }
    void push(const T & el){
        Node<T> * temp = new Node<T>(el);
        temp->next=top;
        top=temp;
    }
    T & Top()  {
        if(top==NULL){
            cout<<"hb";
        }
        else
        return top->data;
    }
    template <typename V>
        friend class QueueusingStacks;
};
template <typename T>
class QueueusingStacks {
    Stackll<T> s1;
    Stackll<T> s2;
    public:
    void enqueue(const T & el) {
        s1.push(el);
    }
    void dequeue() {
        while (s1.top!=0) {
            s2.push(s1.Top());
            s1.pop();
        }
        cout<<s2.Top()<<endl;
        s2.pop();
        while (s2.top!=0) {
            s1.push(s2.Top());
            s2.pop();
        }
    }
    T & getFront(){
        return s2.Top();
    }
};
#endif
