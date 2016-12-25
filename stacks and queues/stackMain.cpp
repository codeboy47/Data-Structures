#include<iostream>
#include "Stack.h"
using namespace std;


int main(){
	Stack<int> s1;
	s1.push(1);
	s1.push(2);
	s1.push(3);
	cout<<"top most element of stack is "<<s1.top()<<endl;
	cout<<"size of stack is "<<s1.size()<<endl;
	cout<<s1.pop()<<endl; 
	cout<<s1.pop()<<endl;
	cout<<s1.pop()<<endl;

	Stack<char> s2;
	s2.push('a');
	s2.push('b');
	s2.push('c');
	cout<<s2.pop()<<endl; 
	cout<<s2.pop()<<endl;
	cout<<s2.pop()<<endl;

	Stack<int> s3;
	cout<<s3.pop()<<endl;

	s1.isEmpty() == 1 ? cout<<"stack is empty "<<endl : cout<<"stack is not empty"<<endl;

	return 0;	
}