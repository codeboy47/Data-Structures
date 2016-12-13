#include<iostream>
#include "binaryTreeNode.h"
#include<queue>
#include<stack>
#include<cmath>
//#include<stdlib>
using namespace std;

class hdpair{
public:
	int diameter;
	int height;
};

class hbpair{
public:
    int height;
    bool balanced;
    hbpair() { }
    hbpair(int h,bool b) {
        balanced = b;
        height = h;
    }
};
///O(N)
 hbpair checkBalancedTree2(BinaryTreeNode*root){
     hbpair p;
     if(root==NULL){
        p.height = 0;
        p.balanced = true;
        return p;//(0,true);
    }
    hbpair leftAns = checkBalancedTree2(root->left);
    hbpair rightAns = checkBalancedTree2(root->right);
    if(abs(leftAns.height-rightAns.height) <= 1 && rightAns.balanced==1 && leftAns.balanced ==1){
        p.height = max(leftAns.height,rightAns.height) + 1;
        p.balanced = true;
        return p;
    }else{
        p.height = max(leftAns.height,rightAns.height) + 1;
        p.balanced = false;
        return p;
    }
   // return p;
 }
hdpair diameter2(BinaryTreeNode*root){
	hdpair p;

	if(root==NULL){
		p.diameter = 0;
		p.height = 0;
		return p;
	}

	hdpair leftAns = diameter2(root->left);
	hdpair rightAns = diameter2(root->right);

	int option1 = leftAns.diameter;
	int option2 = rightAns.diameter;
	int option3 = leftAns.height + rightAns.height;

	p.height = max(leftAns.height,rightAns.height) + 1;
	p.diameter = max(option1,max(option2,option3));

	return p;
}

void mirror(BinaryTreeNode*root){
	if(root==NULL)
			return;

	mirror(root->left);
	mirror(root->right);

	BinaryTreeNode* temp = root->left;
	root->left = root->right;
	root->right = temp;

}

BinaryTreeNode*findNode(BinaryTreeNode*root,int key){
	if(root==NULL)
			return NULL;

	if(root->data == key)
			return root;

	 BinaryTreeNode* leftAns = findNode(root->left,key);
	 if(leftAns!=NULL)
	 		return leftAns;

	 return findNode(root->right,key);
}

static void takeInputRecursivelyHelper(BinaryTreeNode*root){
    if(root == NULL){
        return;
    }
    int data;
    char ch;
    cout<<"want to enter data for left node of "<< root->data << " y/n : ";
    cin>>ch;
    if(ch == 'y' || ch =='Y'){
        cout<<"enter left node data of "<<root->data<<": ";
        cin>>data;
        root->left = new BinaryTreeNode(data);
    }
    cout<<"want to enter data for right node of "<<root->data<<" y/n : ";
    cin>>ch;
    if(ch == 'y' || ch =='Y'){
        cout<<"enter right node data of "<<root->data<<": ";
        cin>>data;
        root->right = new BinaryTreeNode(data);
    }
    takeInputRecursivelyHelper(root->left);
    takeInputRecursivelyHelper(root->right);
}

void takeInputRecursively(BinaryTreeNode**root){ /// we are changing/altering tree so we need address of root and not its copy
    //BinaryTreeNode*root ;
    int data;
    cout<<"enter the root data : ";
    cin>>data;
    *root = new BinaryTreeNode(data);
    takeInputRecursivelyHelper(*root);
    return ;
}

BinaryTreeNode* takeInputLevelOrder(){
	BinaryTreeNode*root ;
	int data;
	cout<<"Enter the root data ";
	cin>>data;

	root = new BinaryTreeNode(data);

	queue<BinaryTreeNode* > q;
	q.push(root);

	while(!q.empty()){
		BinaryTreeNode* frontNode = q.front();
		q.pop();
		int leftData,rightData;
		cout<<"Enter left child data for Node "<<frontNode->data <<":";
		cin>>leftData;
		cout<<endl;
		if(leftData!= -1){
			frontNode->left = new BinaryTreeNode(leftData);
			q.push(frontNode->left);
		}

		cout<<"Enter right child data for Node "<<frontNode->data<<":";			cout<<endl;
		cin>>rightData;

		if(rightData!=-1){
			frontNode->right = new BinaryTreeNode(rightData);
			q.push(frontNode->right);
		}
	}

return root;
}

void printPreorder(BinaryTreeNode*root){
		if(root==NULL)
			return;

		cout<<root->data<<" ";
		printPreorder(root->left);
		printPreorder(root->right);
}

void printInorder(BinaryTreeNode*root){
	if(root==NULL)
		return;

	printInorder(root->left);
	cout<<root->data<<" ";
	printInorder(root->right);

}

void printPostorder(BinaryTreeNode*root){
	if(root==NULL){
		return ;
	}
	printPostorder(root->left);
	printPostorder(root->right);
	cout<<root->data <<" ";
}

void printLevelOrder(BinaryTreeNode*root){
	queue<BinaryTreeNode*> q;
	q.push(root);

	while(!q.empty()){
		BinaryTreeNode* temp = q.front();
		q.pop();

		cout<<temp->data <<" ";
		if(temp->left!=NULL){
			q.push(temp->left);
		}
		if(temp->right!=NULL){
			q.push(temp->right);
		}
	}
}

int countNodes(BinaryTreeNode* root){
	if(root==NULL)
		return 0;
	return (countNodes(root->left) + 1 + countNodes(root->right));
}

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
		}else{
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

int height(BinaryTreeNode* root){
	if(root==NULL)
			return 0;

	return max(height(root->left),height(root->right)) + 1;
}

int diameter(BinaryTreeNode* root){
	if(root==NULL)
			return 0;
	int option1 = diameter(root->left);
	int option2 =  diameter(root->right);
	int option3 =  height(root->left) + height(root->right) + 1;

	return max(option1,max(option2,option3));
}

int sumOfAllNodes(BinaryTreeNode*root){
    if(root==NULL) return 0;
    return sumOfAllNodes(root->left) + root->data + sumOfAllNodes(root->right);
}
/// this index is for preorder
int pindex = 0;
/// start and end are for inorder array
BinaryTreeNode* buildTree(int preorder[],int inorder[],int start,int end){
    //cout<<index<<" ";
    if(start == end){
        BinaryTreeNode * node= new BinaryTreeNode(inorder[start]);
        return node;
    }
    if(start > end) return NULL;
    int data = preorder[pindex],k;
    for(int i = start;i<=end;i++){
        if(inorder[i] == data){
            k = i;
        }
    }
    pindex++;
    BinaryTreeNode* root = new BinaryTreeNode(data);
    root->left = buildTree(preorder,inorder,start,k-1);
    pindex++;
    root->right = buildTree(preorder,inorder,k+1,end);
    return root;
}

bool checkStructureIdentical(BinaryTreeNode*root1,BinaryTreeNode*root2){
    if(root1==NULL && root2==NULL){
        return true;
    }
    if(root1!=NULL && root2!=NULL){
    if((root1->data == root2->data) && checkStructureIdentical(root1->left,root2->left) && checkStructureIdentical(root1->right,root2->right))
        return true;
    }
        return false;
}
//my way of checking structure identical
bool checkNodesAreEqual(BinaryTreeNode*root1,BinaryTreeNode*root2){
    bool ans1,ans2;
   // root1 and root2 are both empty
    if(root1 == NULL && root2 == NULL) {
        return true;
    }
    // root1 and root2 are not empty check following conditions
    if(root1!=NULL && root2!=NULL){
        if(root1->data == root2->data){
            ans1 = checkNodesAreEqual(root1->left,root2->left);
            ans2 = checkNodesAreEqual(root1->right,root2->right);
            return (ans1 && ans2);
        }
    }else{
        return false;
    }
}
/// my way of code O(n^2)
bool checkBalancedTree(BinaryTreeNode*root){
    if(root==NULL) return true;
    int h1,h2,ans;
    h1 = height(root->left);
    h2 = height(root->right);
    //ans = h1-h2;
    if(abs(h1-h2) <= 1 ){
        //cout<<"h is"<<h1-h2;
        return true;
    }else{
        return false;
    }
}

void printNonSiblingNodes(BinaryTreeNode*root){
    if(root==NULL) return;
    if(root->left==NULL && root->right!=NULL){
        cout<<root->right->data<<" ";
    }
    if(root->right==NULL && root->left!=NULL){
        cout<<root->left->data<<" ";
    }
    printNonSiblingNodes(root->left);
    printNonSiblingNodes(root->right);
    return;
}

int removeLeaves(BinaryTreeNode*root){
    /*BinaryTreeNode* removeLeaves(BinaryTreeNode* root) {
    if (root != NULL)
    {
        if (root->left == NULL && root->right == NULL)
        {
            delete(root);
            return NULL;
        }
        else
        {
            root->left = removeLeaves(root->left);
            root->right = removeLeaves(root->right);
        }
    }
    return root;
    }*/
    if(root==NULL) return 0;
    if(root->left==NULL && root->right==NULL){
        delete(root);
        return 1;
    }
    int ansl = removeLeaves(root->left);
    if(ansl == 1){
        root->left=NULL;
    }
    int ansr = removeLeaves(root->right);
    if(ansr == 1){
        root->right=NULL;
    }
    return 0;
}

void printZigZag(BinaryTreeNode*root){
    stack<BinaryTreeNode*> s1,s2;
    s1.push(NULL);
    //s2.push(NULL);
    s1.push(root);
    while(!s1.empty() || !s2.empty()) {
        while(!s1.empty()){
        BinaryTreeNode*temp = s1.top();
        s1.pop();
            if(temp == NULL){
                cout<<endl;
                //s1.pop();
            }else{
                cout<<temp->data<<" ";
                if(!s1.empty() && s2.empty())
                s2.push(NULL);
                if(temp->left!=NULL){
                    s2.push(temp->left);
                }
                if(temp->right!=NULL){
                    s2.push(temp->right);
                }
            }
        }
        while(!s2.empty()){
        BinaryTreeNode*temp = s2.top();
        s2.pop();
            if(temp == NULL){
                cout<<endl;
                //s2.pop();
            }else{
                cout<<temp->data<<" ";
                if(!s2.empty() && s1.empty())
                s1.push(NULL);
                if(temp->right!=NULL){
                    s1.push(temp->right);
                }
                if(temp->left!=NULL){
                    s1.push(temp->left);
                }
            }
        }
    }
}

int main(){
BinaryTreeNode*root = NULL;
//BinaryTreeNode*root2 = NULL;
///root = takeInputLevelOrder();
takeInputRecursively(&root); /// giving address of root to takeInputRecussively(BinaryTreeNode**root1) so that root1 gets address of root hence
/// we can update or change that root or add children to it. *root is a BinaryTreeNode pointer so giving its address by &root to **root1, a pointer
/// storing address of other pointer(*root).
//takeInputRecursively(&root2);
printZigZag(root);
cout<<endl<<"tree is balanced or not : "<<checkBalancedTree2(root).balanced<<endl;
printPreorder(root); cout<<"Preorder "<<endl;
printInorder(root);	cout<<"Inorder "<<endl;
printPostorder(root);	cout<<" PostOrder "<<endl;
printLevelOrder2(root);	cout<< "Level Order "<<endl;

cout<<"Number of nodes is :"<<countNodes(root)<<endl;
cout<<"Diameter of Tree is :"<<diameter(root)<<endl;
cout<<"Faster Method : Diameter "<<diameter2(root).diameter<<endl;
cout<<"sum of all nodes : "<<sumOfAllNodes(root)<<endl;
mirror(root);
printLevelOrder2(root);
cout<<"nodes that don’t have a sibling are : ";
printNonSiblingNodes(root);
cout<<endl;
int preorder[8] = {1,2,4,5,7,8,3,6};
int inorder[8] =   {4,2,7,5,8,1,6,3};
root = buildTree(preorder,inorder,0,7);
printLevelOrder2(root);

//cout<<endl<<checkNodesAreEqual(root,root2);
//cout<<endl<<checkStructureIdentical(root,root2);
return 0;
///takeInputRecursively(&root);
///printLevelOrder2(root);	cout<< "Level Order "<<endl;
//removeLeaves(root);
//printLevelOrder2(root);	cout<< "Level Order "<<endl;*/
}
