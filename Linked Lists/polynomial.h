#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include<iostream>
using namespace std;
template <typename T> class Polynomial;
template <typename T>
class Node {
    T coeff;
    T power;
    Node * next;
    public:
    Node() : next(0) {}
    Node(const T & coeff,const T & pow) : coeff(coeff), power(pow),next(0) {}   // adding null always when we create new node
    Node(const T & coeff, const T & pow, Node * ad): coeff(coeff), power(pow), next(ad) {}
    T getCoeff() const {
        return coeff;
    }
    T getPower() const {
        return power;
    }
    template <typename V>
        friend class Polynomial;
    template<typename V>
       friend ostream & operator<<(ostream &, const Polynomial<V> &);
};

template <typename T>
class Polynomial {
    Node<T> * head;
    Node<T> * tail;
void clear() {
        while (head != NULL) {
            Node<T> * temp = head->next;
            delete head;
            head = temp;
        }
    }
    void copyAs(const Polynomial & L) {
        clear();
        const Node<T> * it = L.head;
        Node<T> * prev = 0;
        while (it != 0) {
            Node<T> * temp = new Node<T>(*it);
            temp->next = 0;
            if (head == NULL) {
                head = temp;
            } else {
                prev->next = temp;
            }
            it = it->next;
            prev = temp;
        }
    }
    public:
    Polynomial() : head(0) {}
    ~Polynomial() {
        clear();
    }
    Polynomial(const Polynomial & L) : head(0) {
        copyAs(L);
    }
    Polynomial & operator=(const Polynomial & L) {
        copyAs(L);
        return *this;
    }
    Polynomial operator+(const Polynomial & L) {
    }
    Polynomial & operator+=(const Polynomial & L) {
        Node<T> *it1=head,*it2=L.head;
        Node<T> *temp1=0,*temp2=0;
        while(it1!=0 && it2!=0){
            if(it1->power==it2->power){
                it1->coeff = it1->coeff + it2->coeff;
                it1=it1->next;
                it2=it2->next;
            }
            if(it1->power < it2->power){
                temp1=it1;
                it1=it1->next;
            }
            if(it1->power > it2->power){
                temp1->next=it2;
                temp2=it2;
                it2->next=it1;
                it1=it1->next;
                it2=temp2->next;
            }
        }
        return *this;
    }
    Polynomial operator-(const Polynomial & L) {
        copyAs(L);
        return *this;
    }
    Polynomial & operator-=(const Polynomial & L) {
        copyAs(L);
        return *this;
    }
    Polynomial operator*(const Polynomial & L) {
        copyAs(L);
        return *this;
    }
    Polynomial & operator*=(const Polynomial & L) {
        copyAs(L);
        return *this;
    }
/*    void operator~(const Polynomial & L) {
        copyAs(L);
        //return *this;
    }*/
    void insertTerm(const T & coeff,const T & power) {
        Node<T> *temp=new Node<T>(coeff,power); //creating new node + adding el in temp's data by calling constructor with one argm and pointing to NULL
        if (head == 0) {                            // pointing to NULL always so last node tail points to NULL
            head = temp;
            return;
        }
        Node<T> * it = head;
        if(temp->power < it->power){
            //while(it->power<i)
            temp->next=it;
            head=temp;
        }
        if(temp->power > it->power){
            Node<T> *ptr=it;
            it=it->next;
            while(temp->power > it->power && it!=0){
                ptr=it;
                it = it->next;
            }
            temp->next=it;
            //temp->next=ptr->next;
            ptr->next = temp;
            tail=temp;
        }
    }
// const Node * findElement(const T & el) const { }
    template<typename V>
       friend ostream & operator<<(ostream &, const Polynomial<V> &);
};

template <typename T>
ostream & operator<<(ostream & obj, const Polynomial<T> & L) {
    const Node<T> * it = L.head;
    while (it != NULL) {
        obj << it->coeff<< "x^"<<it->power<<" + ";
        it = it->next;
    }
    obj << "0" ;
    return obj;
}
#endif
