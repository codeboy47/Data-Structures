#ifndef queuell
#define queuell
#include<iostream>
#include<exception>
using namespace std;
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
        friend class Queuell;
    template <typename W>
        friend class stackusing2queues;
};
template <typename T>
class Queuell {
    public:
    Node<T>  *front;
    Node<T>  *rear;
    void clear(){
        while(front!=0){
            Node<T> * it=front->next;
            delete front;
            front=it;
        }
    }
    void copy(Queuell & s){
        clear();
        Node<T> * it=s.front,*prev=0;
        while(it!=0){
            Node<T> * temp = new Node<T>(*it);
            if(front==NULL){
                front=s.front;
            }
             else{
                prev->next=temp;
            }
            prev=temp;
            it=it->next;
        }
    }
    //public:
    Queuell() : front(0) ,rear(0) { }
    Queuell(Queuell & s) : front(0), rear(0) {
        copy(s);
    }
    ~Queuell(){
        clear();
    }
    void dequeue(){
        if(front==NULL){
            return;
            //throw "queue is empty";
        }
        Node<T> *it=front;
        front=front->next;
        delete it;
    }
    void enqueue(const T & el){
        Node<T> * temp = new Node<T>(el);
        temp->next=0;
        if(rear==NULL){
            rear=front=temp;
        }
        else{
            rear->next=temp;
            rear=temp;
        }
    }
    T & getFront() {
        if (front==NULL) {
            cout<<"f";
            //throw "queue is empty";
        }
        else
        return front->data;   // we are returning value at node front
    }
    bool isEmpty() {
        return front=0;
    }
    void show(){
        Node<T> *temp=front;
        cout<<endl<<"Queue is : ";
        while(temp!=0){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }
    template <typename V>
        friend class stackusing2queues;
};
template <typename T>
class stackusing2queues{
    Queuell<T> Q1;
    Queuell<T> Q2;
    public:
    void push(const T & el){
        Q1.enqueue(el);
    }
    void pop(){
        while(Q1.front->next!=NULL){
            Q2.enqueue(Q1.getFront());
            Q1.dequeue();
        }
        cout<<Q1.getFront()<<endl;
        Q1.dequeue();
        Q1.front=Q1.rear=0;
        while(Q2.front!=0){
            Q1.enqueue(Q2.getFront());
            Q2.dequeue();
        }
        Q2.front=Q2.rear=0;
    }
};
#endif
