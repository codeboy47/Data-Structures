#include<iostream.h>
#include "Stack.h"
using namespace std;

bool isBalanced(char input[]){
    Stack<char> s;
    for(int i=0;input[i]!='\0';i++){
        switch(ch) {
            char ch = input[i];
            case '{' :  s.push(ch);
                            break;
            case '}' :  if(!s.isEmpty() && s.pop() == '{') { }
                           else return false;
                           break;
            case '[' :  s.push(ch);
                            break;
            case ']' :  if(!s.isEmpty() && s.pop() == '[') { }
                           else return false;
                           break;
            case '(' :  s.push(ch);
                            break;
            case ')' :  if(!s.isEmpty() && s.pop() == '(') { }
                           else return false;
                           break;
            default : continue;
        }
    }
}
int main(){
}
