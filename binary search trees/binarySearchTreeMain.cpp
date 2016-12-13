#include<iostream>
#include "binaryTreeNode.h"
#include<queue>
#include<climits>
using namespace std;

void printLevelOrder2(BinaryTreeNode*root){
	queue<BinaryTreeNode*> q;
	q.push(root);
	q.push(NULL);

	while(!q.empty()){
		BinaryTreeNode* temp = q.front();
		q.pop();
		if(temp==NULL ){
				cout<<endl;
				if(!q.empty())
					q.push(NULL);
		}
		else{
			cout<<temp->data <<" ";
			if(temp->left!=NULL){
				q.push(temp->left);
			}
			if(temp->right!=NULL){
				q.push(temp->right);
			}
		}
	}
}

BinaryTreeNode* insertBST(BinaryTreeNode*root,int data){
    if(root == NULL) {
        root = new BinaryTreeNode(data);
        return root;
    }
    if(root->data > data){
        root->left = insertBST(root->left,data);
    }
    if(root->data < data){
        root->right = insertBST(root->right,data);
    }
    return root;
}

BinaryTreeNode*array2Tree(int arr[],int start,int mid,int end){
    mid = (start+end)/2;
    if(start == end) {
        BinaryTreeNode* node = new BinaryTreeNode(arr[start]);
        return node;
    }
    if(start > end){
        return NULL;
    }
    BinaryTreeNode* root = new BinaryTreeNode(arr[mid]);
    root->left = array2Tree(arr,start,mid,mid-1);
    root->right = array2Tree(arr,mid+1,mid,end);
    return root;
}

void printRange(BinaryTreeNode*root,int k1,int k2){
    if(root==NULL) return ;
    if(k1 <= root->data && k2 >= root->data){
        printRange(root->left,k1,k2);
        cout<<root->data<<" "; /// if it lies in this range then we have to print that data
        printRange(root->right,k1,k2);
        //cout<<root->data<<" ";
    }if(k1 > root->data && k2 > root->data){
        printRange(root->right,k1,k2);
        return;
    }if(k1 < root->data && k2 < root->data){
        printRange(root->left,k1,k2);
    }

    return;
}

bool isBST(BinaryTreeNode*root,int max,int min){

}



int main(){
    BinaryTreeNode*root = NULL;
    int n;
    cout<<"enter no of elements you want to enter ";
    cin>>n;
    int data;
    for(int i=0;i<n;i++){
        cin>>data;
        root = insertBST(root,data);
    }
    /*int arr[7] = {1,2,3,4,5,6,7};
    root = array2Tree(arr,0,0,7);
    printLevelOrder2(root);*/
    printRange(root,1,20);
    return 0;
}
