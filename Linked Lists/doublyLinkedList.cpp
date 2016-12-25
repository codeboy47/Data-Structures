#include<iostream>
using namespace std;
 
class Node{
public:
	int data;
	Node*next;
	Node*prev;

	Node() : data(0),next(NULL),prev(NULL) {}
	Node(int d) : data(d),next(NULL),prev(NULL) {}
	
	friend class DoublyLL;
};

class DoublyLL{
public:
	Node*head;
	Node*tail;
	
	DoublyLL() : head(NULL),tail(NULL) {}

	void insertFront(int d){
		if(head == NULL){
			Node*n = new Node(d);
			head = n;
			tail = n;
		}else{
			Node*n = new Node(d);
			n->next = head;
			head->prev = n;
			head = n;
		}		
	}

	void insertMiddle(int pos,int d){
		Node*n = new Node(d);
		if(head == NULL){
			head = n;
			tail = n;
		}else{
			int i = 1;
			Node*temp = head;
			while(i < pos-1){
				i++;
				temp = temp->next;
			}
			n->prev = temp;
			n->next = temp->next;
			temp->next->prev = n;
			temp->next = n;
		}
	}

	void insertBack(int d){
		Node*n = new Node(d);
		if(head == NULL){
			head = n;
			tail = n;
		}else{
			Node*temp = head;
			while(temp->next != NULL){
				temp = temp->next;
			}
			temp->next = n;
			n->prev = temp;
			tail = n;
			n->next = NULL;
		}
	}

	void deleteFront(){
		Node*temp = head,*it;
		if(head == NULL){
			return;
		}
		it = temp->next;
		delete temp;
		head = it;
		it->prev = NULL;
	}

	void deleteMiddle(int pos){
		Node*temp = head,*it;
		int i = 1;
		if(pos < 1){
			cout<<"entered wrong position";
			return;
		}
		if(head == NULL) return;
		while(i < pos){
			i++;
			it = temp;
			temp = temp->next;
		} 
		if(i == 1){
			it = temp->next;
			it->prev = NULL;
			delete temp;
			head = it;
		}else{
			temp->next->prev = it;
			it->next = temp->next;
			delete temp;
		}
	}

	void deleteBack(){
		Node*temp = head,*it;
		if(head == NULL) return;
		while(temp->next != NULL){
			it = temp;
			temp = temp->next;
		} 
		temp->prev = NULL;
		it->next = NULL;
		tail = it;
		delete temp;
	}

	int position(int data){
		Node*temp = head;
		int pos = 1;
		while(temp != NULL){
			if(data == temp->data){
				return pos;
			}
			pos++;
			temp =temp->next;
		}
		return -1;
	}

	void print(){
		Node*temp = head;
		while(temp!=NULL){
			cout<<temp->data<<"<==>";
			temp = temp->next;
		}
		cout<<"NULL"<<endl;
	}

	void printReverse(){
		Node*temp = tail;
		while(temp!=NULL){
			cout<<temp->data<<"<==>";
			temp = temp->prev;
		}
		cout<<"NULL"<<endl;
	}

	void mergesort(){

	}

};

int main(){
	DoublyLL l;
	l.insertFront(3);
	l.insertFront(2);
	l.insertFront(1);
	l.insertMiddle(3,100);
	l.insertBack(4);
	l.insertBack(5);
	l.insertBack(6);
	l.print();
	l.deleteFront();
	l.deleteBack();
	l.deleteMiddle(3);
	l.print();
	l.printReverse();
	cout<<"Element 2 is found at position "<<l.position(2)<<endl;
	cout<<"tail data is "<<l.tail->data<<endl;
	return 0;
}