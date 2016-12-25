#ifndef NODE_H
#define NODE_H

template<typename T>
class Node{
public:
	T data;
	Node<T> *next;

	Node() : data(0) , next(NULL) {} 
	Node(T d) : data(d) , next(NULL) {}

};

#endif