#include<iostream>
#include "treenode.h"
#include<queue>
using namespace std;

TreeNode<int>* takeInputLevelByLevel(){
int data;
cout<<"Enter the root data";
cin>>data;

TreeNode<int> *root = new TreeNode<int>(data);

queue<TreeNode<int>* > q;
q.push(root);
	while(!q.empty()){
		TreeNode<int> * node = q.front();
		q.pop();

cout<<"Enter the children_count for Node with data "<<node->data<<" : ";
		int count;
		cin>>count;
		node->children_count = count;
		node->children = new TreeNode<int>*[count];

		for(int i=0;i<count;i++){
			int data;
			cout<<"Enter the data for "<<i<<"children of node "<<node->data<<" : ";
			cin>>data;
			node->children[i] = new TreeNode<int>(data);
			q.push(node->children[i]);
		}
	}
return root;
}

TreeNode<int>* takeInput(){
	int  data;
	cout<<"Enter the node data : ";
	cin>>data;
	TreeNode<int> *node = new TreeNode<int>(data);
	int count;
        cout<<"Enter the child count for node "<<data<<" : " ;
	cin>>count;
	node->children_count = count;
	node->children = new TreeNode<int>*[count]; /// an array storing the address of its children
	for(int i=0;i < count;i++){
		node->children[i] = takeInput();  /// node->children[0] stores the address of its zeroth children of node
	}
return node;
}

int height(TreeNode<int> * root){
 if(root==NULL){
	return 0;
 }
 int maxHeightSoFar = 0;
 for(int i=0;i<root->children_count; i++){   /// leaf node(last node) will not enter this loop
	int child_height = height(root->children[i]);
	if(child_height > maxHeightSoFar){
		maxHeightSoFar = child_height;
	}
  }
return maxHeightSoFar + 1;
}

int sumOfNodes(TreeNode<int>* root){
	if(root==NULL){
		return 0;
	}
	int currentSum = root->data;
	for(int i=0;i<root->children_count;i++){
		currentSum = currentSum + sumOfNodes(root->children[i]);
	}
return currentSum;
}

void print(TreeNode<int>*root){
	cout<<root->data<<" -> ";
	for(int i=0; i <root->children_count ; i++){
		cout<< root->children[i]->data <<",";
	}
	cout<<endl;
	for(int i=0;i <root->children_count ; i++){
		print(root->children[i]);
	}
return;
}

void printK(TreeNode<int>*root,int k){
	 if(root==NULL)
		return;
	 if(k==0){
		cout<<root->data;
     		return;
	 }
	for(int i=0;i<root->children_count;i++){
		printK(root->children[i], k-1);
	}
}

int largestData(TreeNode<int>*root){
    if(root == NULL){
        return 0;
    }
    int largest = root->data;
    for(int i=0;i<root->children_count;i++){
        int d = largestData(root->children[i]);
        if(d > largest){
            largest = d;
        }
    }
    return largest;
}

int nodesGreaterThanX(TreeNode<int>*root,int X){
    if(root==NULL){
        return 0;
    }
    int count = 0;
    for(int i=0;i<root->children_count;i++){
        count = count + nodesGreaterThanX(root->children[i],X);
    }
    if(root->data > X){
        count++;
    }
    return count;
}

int main(){
TreeNode<int> *root = NULL;
root = takeInput();
print(root);
cout<<"height : "<<height(root);
cout<<endl<<"largest data of tree : "<<largestData(root);
cout<<endl<<"sum of all nodes of tree : "<<sumOfAllNodes(root);
cout<<endl<<"nodes greater than integer X : "<<nodesGreaterThanX(root,2);
//delete root;
return 0;
}
