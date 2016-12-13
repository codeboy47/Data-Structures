#ifndef TREENODE_H
#define TREENODE_H
#include<iostream>
using namespace std;

template<typename T>
class TreeNode{
public:
	T data;
	TreeNode<T> **children;
	int children_count;

	TreeNode(T d):data(d),children(NULL),children_count(0){}

	~TreeNode(){
		//Baaad mein.
		cout<<"Deleting Node "<<data<<" and its children"<<endl;
		for(int i=0;i<children_count;i++)
			delete children[i];
		delete [] children;
	}
};
#endif
