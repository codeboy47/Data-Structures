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
    //cout<<endl<<count<<endl;
    int c = count;
    for(i=0;i<count;i++){
        str[c-1] = 48+ (no%10);
        c--;
        no = no/10;
    }
    str[count] = '\0';
}
void compress(char *str){
    char str2[100],arr[100];
    int count =1,j=0;
	bool change = false;
	for(int i=0;i<=strlen(str)-1;i++){
        if(str[i] == str[i+1]){
            ++count;
        }
        //sprintf(arr, "%d", count);
        makeSprintf(count,arr);
        if(str[i] != str[i+1]){
            str2[j++] = str[i];
            for(int k = 0;k<strlen(arr);k++)
                str2[j++] = arr[k];
            //char t = count + 48;
            //str2[j++] = t;
            count = 1;
        }
	}
	str2[j] = '\0';
	strcpy(str,str2);
}
int main(){
	char str[1000];
	cin.getline(str, 1000);
	compress(str);
	for(int i =0;i<=strlen(str)-1;i++)
        cout<<str[i];
	return 0;
}
