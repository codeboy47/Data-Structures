#include<iostream>
#include<stack>

using namespace std;
bool isOperand(char ch)
{
    return ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'));
}
int precedence(char a)
{
    if(a=='/'||a=='*')
        return 2;
    if(a=='+'||a=='-')
        return 1;
    if(a=='^')
        return 3;
    return -1;

}
void infixtopostfix(string a,string & b)
{
    stack <char> s1;
    string::iterator it;
    cout<<"Infix: "<<a<<endl;
    //string b;
    for(it=a.begin();it!=a.end();it++)
    {
       // cout<<b<<endl;
        if(isOperand(*it))
        {
           // cout<<"sa";
            b+=(*it);
            //cout<<*it<<endl;
        }
        else if(*it=='(')
        {
            s1.push(*it);
        }
        else if(*it==')')
        {
            while(!s1.empty()&&s1.top()!='(')
            {
                b+=s1.top();
               // cout<<s1.top();
                s1.pop();
            }
            if(!s1.empty()&&s1.top()!='(')
            {
                cout<<"Invalid exp";
                return;
            }
            s1.pop();
        }
        else{
            while(!s1.empty()&&precedence(s1.top())>=precedence(*it))
            {
             //   cout<<"asd";
                //cout<<s1.top();
                b+=s1.top();
                s1.pop();
            }
            s1.push(*it);
        }
    }
    while(!s1.empty())
    {
        //cout<<s1.top();
        b+=s1.top();
        s1.pop();
    }
}
int main()
{
    string a="(A+B)*(C+D)";

    string b="";
    infixtopostfix(a,b);
    cout<<"Postfix :"<<b;
    return 0;
}
