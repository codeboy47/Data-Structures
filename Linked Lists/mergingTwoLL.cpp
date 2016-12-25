/// -> if temp is pointing to NULL i.e. temp = NULL and if we do temp = temp->next
/// 	then we will get segmentation fault
/// -> if we free any pointer and do not allocate anything we get an error as it is
///		pointing to nothing so we point head pointer of l1 and l2 linked lists to NULL
#include<iostream>
using namespace std;

class Node{
public:
	int data;
	Node*next;

	Node():data(0),next(NULL){}
	Node(int d):data(d),next(NULL){}

	friend class linkedList;

};

class linkedList{
public:
	Node*head;

	linkedList():head(NULL){}

	void takeInput(){
		int data;
		cout<<"enter the first element : ";
		cin>>data;
		while(data != -1){
			Node*temp = new Node(),*it;
			temp->data = data;
			if(head == NULL){
				head = temp; 
				it = temp;
			}else{
				it->next = temp;
				it = temp;
			}
			cout<<"enter the next data : ";
			cin>>data;
		}
	}


	Node*mergeTwoSortedLists(Node*head1,Node*head2){
		Node*temp1=head1,*temp2=head2,*head;
		Node*prev1=head1,*prev2=head2;
		bool flag = true;
		
		if(head1 == NULL){
			return head2;
		}if(head2 == NULL){
			return head1;
		}

		while(temp1!=NULL && temp2!=NULL){
			if(flag == true){
				if(head1->data > head2->data){
					head = head2;
				}else{
					head = head1;
				}
				flag = false;
			}
			else if(temp1->data <= temp2->data) {
				prev1 = temp1->next;
				if( temp1->next != NULL && temp1->next->data <= temp2->data) {
					temp1 = temp1->next;
				}else{
					//prev1 = temp1->next;
					temp1->next = temp2;
					temp1 = prev1;
				}
			}
			else if(temp2->data <= temp1->data){
				prev2 = temp2->next;
			 	if(temp2->next != NULL && temp2->next->data < temp1->data) {
					temp2 = temp2->next;
				}else{
					//prev2 = temp2->next;
					temp2->next = temp1;
					temp2 = prev2;
				}
			}	
		}
		return head;
	}

	void print(){
		Node*temp = head;
		while(temp!=NULL){
			cout<<temp->data<<"-->";
			temp = temp->next;
		}
		cout<<"NULL"<<endl;
	}
	void deleteList(){
		Node*temp = head;
		while(temp!=NULL){
			temp = head->next;
			delete head;
			head = temp;
		}
	}

	~linkedList(){
		Node*temp = head;
		while(temp!=NULL){
			temp = head->next;
			delete head;
			head = temp;
		}
	}
};

int main(){
	linkedList l1;
	linkedList l2;
	linkedList l3;
	cout<<"enter elements for first sorted linked list :"<<endl;
	l1.takeInput();
	l1.print();
	cout<<"enter elements for second sorted linked list :"<<endl;
	l2.takeInput();
	l2.print();
	Node*t = l2.head;
	l3.head = l3.mergeTwoSortedLists(l1.head,l2.head);
	//l1.deleteList();
	l1.head = NULL; // -> if we free any pointer and do not allocate anything we get an error as it is 
	l2.head = NULL; // -> pointing to nothing so we point head pointer of l1 and l2 linked lists to NULL
	l1.print();
	l2.print();
	l3.print();
	return 0;
}