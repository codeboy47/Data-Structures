#ifndef STACK_H
#define STACK_H

#include "Node.h"

template<typename T>
class Stack{
	Node<T> *head;
public:
	Stack() : head(NULL) {}

	void push(T data){
		Node<T>*n = new Node<T>(data);
		n->next = head;
		head = n;
	}

	T pop(){
		if(head!=NULL){
			Node<T>*temp = head;
			T data = head->data;
			head = head->next;
			delete temp;
			return data;
		}else{
			return -1;
		}
	}

	T size(){
		Node<T>*temp = head;
		int count = 0;
		while(temp != NULL){
			count++;
			temp = temp->next;
		}
		return count;
	}

	T top(){
		return head->data;
	}

	bool isEmpty(){
		return head == NULL ? true : false;
	}
	
};

#endif