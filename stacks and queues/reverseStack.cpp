#include<iostream>
#include "Stack.h"
using namespace std;

void insertAtBottom(Stack<int> &s,int data){
	if(s.isEmpty()){
		s.push(data);
		return;
	}else{
		int d = s.pop();
		insertAtBottom(s,data);
		s.push(d);
		return;
	}
}

void reverse(Stack<int> &s){
	if(s.isEmpty()){
		return;
	}
	int top = s.pop();
	reverse(s);
	insertAtBottom(s,top);
	return;
}

int main(){
	Stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	cout<<"actual stack : "<<endl;
	while(!s.isEmpty()){
		cout<<s.pop()<<endl;
	}
	
	s.push(1);
	s.push(2);
	s.push(3);
	reverse(s);
	cout<<"reverse stack : "<<endl;
	while(!s.isEmpty()){
		cout<<s.pop()<<endl;
	}
	
	return 0;	
}