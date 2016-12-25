// stack using 2 queues
#include<iostream>
#include<stack>
#include<queue>
using namespace std;
class Stack{
	queue<int> q1;
	queue<int> q2;
public:	
	void push(int data){
		q1.push(data);
	}

	int pop(){
		int i = 0;
		int size = q1.size();
		while(i < size-1){
			q2.push(q1.front());
			q1.pop();
			i++;
		}
		int top = q1.front();
		q1.pop();
		while(!q2.empty()){
			q1.push(q2.front());
			q2.pop();
		}

		return top;
	}

	int size(){
		return q1.size();
	}

	int top(){
		return q1.back();
	}
};

int main(){

	Stack s1;
	s1.push(1);
	s1.push(2);
	s1.push(3);
	cout<<"top most element of stack is "<<s1.top()<<endl;
	cout<<"size of stack is "<<s1.size()<<endl;
	cout<<s1.pop()<<endl; 
	cout<<s1.pop()<<endl;
	cout<<s1.pop()<<endl;

	return 0;
}
