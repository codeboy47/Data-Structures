#include<iostream>
#include<cstring>
using namespace std;

int stringsearchBruteForce(char *str1,char *str2){
    int start=0,last=strlen(str1)-1,i,j,k;
    for(i=0,j=0;i<=last,j<=strlen(str2)-1;){
        if(str1[i] != str2[j]){
            i++;
            if(j>0){
                j=0;
                i--;
            }
        }
        if(str1[i] == str2[j]){
            i++;
            j++;
        }
        if(j == strlen(str2)){
            return j;
        }
        if(i == strlen(str1)) break;
    }
    return -1;
}

int main(){
    char str1[100],str2[100];
    cout<<"enter string : ";
    cin.getline(str1,100);
    cout<<"enter substring : ";
    cin.getline(str2,100);
    cout<<stringsearchBruteForce(str1,str2);
}

