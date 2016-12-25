/*
http://stackoverflow.com/questions/7271647/
what-is-the-reason-for-using-a-double-pointer-when-adding-a-node-in-a-linked-list
http://www.geeksforgeeks.org/how-to-write-functions-that-modify-the-head-pointer-of-a-linked-list/
*/
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
private:

	static int searchRecursiveHelper(Node *start,int key){
		if(start ==  NULL) return -1;
		if(start->data == key)	return 0;
		int answer = searchRecursiveHelper(start->next,key);
		if(answer == -1){
			return -1;
		}else{
			return answer + 1;
		}
	}

	/* --- OR --
	int searchRecursiveHelper(Node *start,int key){
		static int count = 1;
		if(start ==  NULL) return -1;
		if(start->data == key)	return count;
		if(start->data != key){
			count++;
			return searchRecursiveHelper(start->next,key);
		}
	}*/
public : 

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

	void insertFront(int d){
		if(head == NULL){
			Node*n = new Node(d);
			head = n;
		}else{
			Node*n = new Node(d);
			n->next = head;
			head = n;
		}
	}

	void insertMiddle(int pos,int d){
		Node*n = new Node(d);
		if(head == NULL){
			head = n;
		}else{
			int i = 1;
			Node*temp = head;
			while(i < pos-1){
				i++;
				temp = temp->next;
			}
			n->next = temp->next;
			temp->next = n;
		}
	}

	void insertBack(int d){
		Node*n = new Node(d);
		if(head == NULL){
			head = n;
		}else{
			Node*temp = head;
			while(temp->next != NULL){
				temp = temp->next;
			}
			temp->next = n;
			n->next = NULL;
		}
	}

	void deleteFront(){
		Node*temp = head,*it;
		if(head == NULL){
			return;
		}
		it = temp->next;
		delete temp;
		head = it;
	}

	void deleteMiddle(int pos){
		Node*temp = head,*it;
		int i = 1;
		if(pos < 1){
			cout<<"entered wrong position";
			return;
		}
		if(head == NULL) return;
		while(i < pos ){
			i++;
			it = temp;
			temp = temp->next;
		} 
		if(i == 1){
			it = temp->next;
			delete temp;
			head = it;
		}else{
			it->next = temp->next;
			delete temp;
		}
	}

	void deleteBack(){
		Node*temp = head,*it;
		if(head == NULL) return;
		while(temp->next != NULL){
			it = temp;
			temp = temp->next;
		} 
		it->next = NULL;
		delete temp;
	}
/* not effective made by me	
	Node* midPointOfLL(){
		Node*temp=head,*it=head;
		int i = 0,mid;
		while(temp!=NULL){
			i++;
			temp = temp->next;
		}
		if(i%2 == 1) mid = (i+1)/2;
		if(i%2 == 0) mid = i/2 ;
		temp = head;
		i = 1;
		while(i < mid){
			i++;
			temp = temp->next;
		}
		return temp;
	}
*/
	Node* midPointOfLL(){
		Node*it1 = head;
		Node*it2 = head->next;
		while(it2 != NULL && it2->next != NULL){
			it2 = it2->next->next;
			it1 = it1->next;
		}
		return it1;
	}

	void removeDuplicatesRecursively(Node*temp,Node*ptr,Node*prev){
		if(temp == NULL){
			return;
		}
		if(ptr == NULL){
			return;
		}
		if(temp->data == ptr->data){
			Node*it2 = ptr;
			prev->next = ptr->next;
			delete it2;
			ptr = prev->next;
			removeDuplicatesRecursively(temp,ptr,prev);
			return;
		}
		if(temp->data != ptr->data){
			removeDuplicatesRecursively(temp,ptr->next,prev->next);
			//return;
		}
		removeDuplicatesRecursively(temp->next,temp->next->next,temp->next);
		return;
	}

	// O(N^2)
	void removeDuplicates(){
		Node*temp = head,*prev,*ptr;
		while(temp != NULL){
			ptr = temp->next;
			prev = temp;
			while(ptr != NULL){
				if(ptr->data == temp->data){
					Node*it = ptr;
					prev->next = ptr->next;
					delete it;
					ptr = prev->next;
				}else{
					prev = prev->next;
					ptr = ptr->next;
				}
			}
			temp = temp->next;
		}
	}

	//  IMPORTANT
	void evenAfterOdd(){
		Node*start = head,*prev = head,*next;
		if(head == NULL){
			cout<<"enter right data except -1 "<<endl;
			return;
		}
		next = start->next;
		while(next != NULL){
			if((next->data)%2 == 1 && (prev->data)%2 == 1){
				start = start->next;
				prev = next;
				next = next->next;
			}
			else if((next->data)%2 == 1){
				prev->next = next->next;
				if((head->data)%2 == 0){
					next->next = head;
					head = next;
					//-- reset
					start = head;
					prev = head;
					next = prev->next;
				}
				else{
					next->next = start->next;
					start->next = next;
				
					start = start->next;
					next = prev->next;
				}
			}
			else if((next->data)%2 == 0){
				prev = next;
				next =next->next;
			}
		}
	}

// IMPORTANT Returns true if elements in the LL make it palindrome e.g: 1->13->4->5->4->13->1	
// Passing single pointer is as good as pass-by-value, and we will pass the same pointer again and again.
// We need to pass the address of head pointer for reflecting the changes in parent recursive calls.
// This is same as pass by value *temp = *head like int x = int a means x or temp changes in function
// but actual head or value of a remains intact/unchanged so pass by reference to see actual change in 
// variable of main() i.e. **temp for &head like int *x for int &a	this will actually change values 
// this can also be done by reversing the mid list then matching 2 sublists then merge them again	
	bool isPalindrome(Node**left,Node*right){
		Node*temp = head;
		bool ans2 = false;
		if(right == NULL){
			return true;
		}
		bool ans = isPalindrome(left,right->next);
		if(ans == false){
			return false;
		}
		if(right->data == (*left)->data){
			ans2 = true;
		}
		*left = (*left)->next;
		return ans2;

		/*	OR
		bool ans1 = (right->data == (*left)->data);
		*left = (*left)->next;
		return ans1;*/
	}

	Node* nthElementFromBack(int n){
		Node*it1 = head,*it2 = head;
		int i = 0;
		while(i < n){
			i++;
			it1 = it1->next;
		}
		while(it1 != NULL){
			it1 = it1->next;
			it2 = it2->next;
		}
		return it2;
	}

	void appendLastNElementsToFront(int n){
		Node*temp = head,*it;
		int l = size();
		int i = 1;
		while(i < l-n+1){
			i++;
			it = temp;
			temp = temp->next;
		}
		it->next = NULL;
		Node*ptr = head;
		head = temp;
		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = ptr;
	}

	void reverse(){
		Node*temp = head;
		Node*it1 = head;
		Node*it2 = NULL; 
		while(it1 != NULL){
			it1 = it1->next;
			temp->next = it2;
			it2 = temp;
			temp = it1; 
		}
		head = it2;
	}

	void reverseRecursive(Node*first,Node*rest){
		if(rest->next == NULL){
			head = rest;
			rest->next = first;
			return;
		}
		reverseRecursive(first->next,rest->next);
		rest->next = first;
		first->next = NULL;
	}	

//									first	   	   prev
//									 |				|
	///  	IMPORTANT not made by me 1->2->3->4->5->6->7->8->9 to 3->2->1->6->5->4->9->8->7 and k = 3
	Node*kReverseRecursive(Node*first,int k){
		Node*current = first;
		Node*next = NULL,*prev = NULL;
		int i = 0;
		while(current != NULL && i < k){
			next = current->next;
			current->next = prev;
			prev = current;
			current = next; 
			i++;
		}
		if(current != NULL)
			//	1 	   -->   6 	(return prev which is 6)
			first->next = kReverseRecursive(next,k);
		return prev;
	}

	int search(int key){
		Node*temp = head;
		int pos = 1;
		while(temp != NULL){
			if(key == temp->data){
				return pos;
			}
			pos++;
			temp =temp->next;
		}
		return -1;
	}

	int searchRecursive(int key){
		int ans = searchRecursiveHelper(head,key);
		return ans + 1;
	}

	/* Bubble Sort Code in c++
	#include <iostream>
	using namespace std;

	int main() {
	// your code goes here
	int i,j,n,arr[100],swap;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>arr[i];
	}
	for(i=0;i<n-1;i++){
		for(j=0;j<n-i-1;j++){
			if(arr[j]>arr[j+1]){
				swap = arr[j];
        		arr[j] = arr[j+1];
        		arr[j+1] = swap;
			}
		}
	}
	
	for(i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	
	return 0;
	}
	*/
	void bubbleSort(){
		bool flag = true;
		int n = size();
		Node *it1,*it2 = NULL,*temp = head;
		int i = 0,j = 0;
		while(i < n-1){
			while(temp->next!=NULL){
			// wrong approach -> while(j < n-1){
				if(temp->data > temp->next->data){
					if(temp == head){
						it1 = temp->next;
						temp->next = it1->next;
						it1->next = temp;
						if(flag == true){
							head = it1;
							flag = false;
						}
						it2 = it1;	
					}else{
						it1 = temp->next;
						temp->next = it1->next;
						it1->next = temp;
						it2->next = it1;
						it2 = it1;
					}
				}else{
					it2 = temp;
					temp = temp->next;
				}
			}
			i++;
			flag = true;
			temp = head;
			it2 = NULL;
		}
	}

	int size(){
		Node*temp = head;
		int i = 0;
		while(temp != NULL){
			temp = temp->next;
			i++;
		}
		return i;
	}

	void print(){
		Node*temp = head;
		while(temp!=NULL){
			cout<<temp->data<<"-->";
			temp = temp->next;
		}
		cout<<"NULL"<<endl;
	}

	void printReverse(Node*temp){
		if(temp == NULL)	return;
		if(temp != NULL){
			printReverse(temp->next);
		}
		cout<<temp->data<<"-->";
		return;
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

	~linkedList(){
		Node*temp = head;
		while(temp!=NULL){
			temp = head->next;
			delete head;
			head = temp;
		}
	}

};
					/**** CRUX *****/
/// -> if temp is pointing to NULL i.e. temp = NULL and if we do temp = temp->next
/// 	then we will get segmentation fault
/// -> if we free any pointer and do not allocate anything we get an error as it is pointing to nothing 
///		so we point head pointer of l2 linked list to NULL i.e. l2.head = NULL
/// -> head gets changed if we pass &head(pass by reference) not head(pass by value) as parameter
///	    then we need to set back head to first node otherwise we may lost linked list elements

int main(){
	linkedList l;
	linkedList l2;
	l.takeInput(); // enter sorted list for merging part with atleast one duplicate element please
	l.print();
	l2.insertFront(13);
	l2.insertFront(12);
	l2.insertFront(11);
	l2.insertMiddle(3,14);
	l2.insertBack(15);
	l2.insertBack(16);
	l2.print();
	l.reverseRecursive(l.head,l.head->next);
	l.print();
	cout<<"Key 2 is found at position "<<l.search(2)<<endl;
	cout<<"Key 2 is found recursively at position "<<l.searchRecursive(2)<<endl;
	cout<<"size of Linked list is "<<l.size()<<endl;
	l.bubbleSort();
	l.print();
	l.deleteMiddle(2);
	l.print();
	Node*mid = l.midPointOfLL();
	cout<<"data of mid point of LL is "<<mid->data<<endl;
	Node*nthElement = l2.nthElementFromBack(5);
	cout<<"nth element from back is "<<nthElement->data<<endl;
	l.printReverse(l.head);
	cout<<"NULL"<<endl;
	l.removeDuplicatesRecursively(l.head,l.head->next,l.head);
	l.print();
	l.appendLastNElementsToFront(2);
	l.print();
	l.head = l.kReverseRecursive(l.head,3);
	l.print();
	Node*headRef = l.head; // this is done for isPalindrome as head gets changed
	cout<<l.isPalindrome(&l.head,l.head)<<" -> this is palindrome/noPalindrome"<<endl;
	// now head is pointing to NULL if list is palindrome 
	l.head = headRef; // head is again set back to first node otherwise we may lost list elements
	l.evenAfterOdd();
	l.print();
	l.head = l.mergeTwoSortedLists(l.head,l2.head);
	l2.head = NULL;//-> if we free any pointer and do not allocate anything we get an error 
				   //   as it is pointing to nothing so we point head pointer of l2 linked list to NULL 
	l.print();
	
	return 0;
}