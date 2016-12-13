#include<iostream>
#include<map>
#include<cstring>
using namespace std;

int main(){
    map<string,int> m;
    m["Akshit"] = 95;
    m["Pranav"] = 86;
    cout<<m["Pranav"]<<endl;
    cout<<sizeof(m.count(""))<<endl;
    if(m.count("Akshit") ==1){  /// count function finds if this exists
        cout<<"found";
    }else{
        cout<<"not found";
    }
    return 0;
}
