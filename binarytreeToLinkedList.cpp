/// my code binary search tree to linked list
#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node*left;
    Node*right;
    Node(int d) : data(d) ,left(NULL),right(NULL) { }
};

class LinkedList{
public:
    Node*head;
    Node*tail;
};

LinkedList treeToLl(Node*root){
    LinkedList l;
    if(root==NULL){
        l.head = root;
        l.tail = root;
        return l;
    }
    LinkedList left = treeToLl(root->left);
    LinkedList right = treeToLl(root->right);
    if(left.head!=NULL){
        l.head = left.head;
        //l.head->right = right.tail;
        left.tail->right = root;
    }else{
        l.head = root;
    }
    if(right.head!=NULL){
        l.tail = right.tail;
        root->right = right.head;
    }else{
        l.tail = root;
    }
    return l;
}

void print(LinkedList l){
    Node *temp = l.head;
    while(temp!=NULL){
        if(temp==l.tail) {
            cout<<temp->data;
        }else{
            cout<<temp->data<<"-->";
        }
        temp = temp->right;
    }
}

int main(){
Node*root = new Node(10);
root->left = new Node(8);
root->right = new Node(12);
root->left->left = new Node(6);
root->left->right = new Node(9);
root->right->left = new Node(11);
root->right->right = new Node(13);
root->right->right->right = new Node(15);

LinkedList l = treeToLl(root);
print(l);

return 0;
}
