#include<iostream>
#include<string.h>
#include "Stack.h"
using namespace std;

bool checkParanthesis(char *str){
	Stack<char> s;
	while(*str != NULL){
		if(*str == '{' ||  *str == '[' || *str == '('){
			s.push(*str);
		}else if(*str == '}'){
			if(s.pop() == '{'){
			}else{
				return false;
			}
		}else if(*str == ']'){
			if(s.pop() == '['){
			}else{
				return false;
			}
		}else if(*str == ')'){
			if(s.top() == '('){  // sometimes top is not given so make codes using push and pop only
				s.pop();
			}else{
				return false;
			}
		}
		*str++;
	}

	return s.isEmpty() == 1 ? true : false;
	
}

int main(){
	char str[100];
	cin.getline(str,100);
	checkParanthesis(str)==1? cout<<"brackets are balanced"<<endl : cout<<"brackets are not balanced"<<endl;
	return 0;
}