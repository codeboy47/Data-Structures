///making sprintf function
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
void makeSprintf(int no,char *str){
   int i=no,count=0;
    while(i!=0){
        i = i/10;
        count++;
    }
    cout<<endl<<count<<endl;
    int c = count;
    for(i=0;i<count;i++){
        str[c-1] = 48+ (no%10);
        c--;
        no = no/10;
    }
    str[count] = '\0';
}
int main(){
    char str[100];
    makeSprintf(5000,str);
    cout<<str;
}
