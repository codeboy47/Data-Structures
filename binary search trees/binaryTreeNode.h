#ifndef BINARY_TREE_NODE_H
#define BINARY_TREE_NODE_H

class BinaryTreeNode{
public:
	int data;
	BinaryTreeNode* left;
	BinaryTreeNode*right;

	BinaryTreeNode():data(0),left(NULL),right(NULL){}
	
	BinaryTreeNode(int d):data(d),left(NULL),right(NULL){}

	~BinaryTreeNode(){
		if(left!=NULL)
			delete left;
		if(right!=NULL)
			delete right;
	}

};
#endif
