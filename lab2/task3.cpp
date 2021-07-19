#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

struct Node
{
  string data;  
  Node *next, *pre;
  Node(string data){
  	this->data = data;
  	next = NULL;
  	pre = NULL;
  }
  Node(){
  	
  }
};


struct DoublelinkedList{
	
	Node *head;
	Node *tail;
  	
 
  	DoublelinkedList()
  	{
      head = NULL;
      
  	}
  	
  	
  	// inserting node at the beginning 
  	void insertAtBeginning(string data){
  		Node *n1 = new Node();
  		n1->data = data;
  		if(head==NULL){
  			head = n1;
  			tail = n1;
		  }
		  else
		  {
		  	n1->next = head;
		  	head->pre = n1;
		  	head = n1;
		  }
		  
	  }


// inserting node at beginning 
	void insertAtBeginning(Node *newNode){
		if(head==NULL)head=newNode;
		else
		{
			newNode->next = head;
			head->pre = newNode;
			head = newNode;
		}
		
	}
	
	// inserting new node at the end of the linked list
		void insertAtEnd(string name){
			Node *newNode = new Node();
			newNode->data = name;
			newNode->next = NULL;
			newNode->pre = NULL;
			if(head==NULL)
			{

				head = newNode;
				tail = newNode;
				
			}
			else{
				
				Node *cur = head;
				while(cur->next != NULL){
					cur = cur->next;	
				}
			
			newNode->pre = cur;
			cur->next = newNode;
			tail = newNode;
			
			}
			
				}
		// inserting new node at the end of the linked list
		void insertAtEnd(Node *newNode){
			if(head==NULL) {
				head =newNode;
				tail = newNode;
			}
			else{
			
			Node *cur = head;
			while(cur->next!=NULL){
				cur = cur->next;
				}
				newNode->pre = cur;
				cur->next = newNode;
				tail = newNode;
			}		
		}
	
			// inserting new node after the given name
		void insertAfterName(string name, Node *newNode){
			Node *cur = head;
			if(head==NULL){
				head = newNode;
			}
			else
			{
				while(cur != NULL)
				{
					if(name == cur->data){
						newNode->pre = cur;
						newNode->next = cur->next;
						if(cur->next)cur->next->pre = newNode;
						else tail = newNode;
						
						cur->next = newNode;
						return;
					}
					cur = cur->next;
				}
				
				
			}
			
		}
		// inserting new node before the given name
		void insertBeforeName(string name, Node *newNode){
		
				if(head==NULL)head = newNode;
				else{
					Node *cur = head;
					
					while(cur!=NULL){
						if(cur->data == name){
							newNode->next = cur;
							newNode->pre = cur->pre;
							if(cur->pre)cur->pre->next = newNode;
							cur->pre = newNode;
							if(head->data == name) head = newNode;
							break;
						}
						cur = cur->next;
					}
				
				}
		}
		
		
		// making linkedlist circular
		void makeCircular(){
			if(head==NULL){
				cout<<"List is empty";
			}
			else{
				Node *cur = head;
				while(cur->next!=NULL){
					cur = cur->next;
				}
				cur->next = head;
				head->pre = cur;
			}
			
		}
		// printing all the nodes in linkedlist
		void printAll(){
			if(head==NULL)return;
			int x=0;
			Node *cur = head;
			while(cur->next!=NULL){
				cout<<cur->data<<endl;
				cur = cur->next;
			}
			cout<<cur->data<<endl;
		}
		
		//checking wether linked list is circular or not
		bool isCircular(){
			Node *cur = head;
			while(cur->next!=NULL)
			{
				if(cur->next == head)
				{
					return true;
				}
				cur = cur->next;
			}

		}
		// checking if there is a cycle/ loop in the linked list by moving two pointers at different speed
		bool hasCycle(Node *headNode){
			if(headNode==NULL)
			{
				return false;
			}
			Node *cur = headNode;
			Node *fast = cur;
			Node *slow = cur;
			while(true){
				
				slow = slow->next;
				if(fast->next!=NULL){
					fast = fast->next->next;
				}
				else
				return false;
				
				if(slow == NULL || fast == NULL)
				{
					return false;
				}
				
				if(slow == fast){
					return true;
				}
			}
			
			
		}
		
	
};

int main(){
	
	DoublelinkedList *l1 = new DoublelinkedList();
	
	Node n1 = Node("bilal");
	Node n2 = Node("khan");
	Node n4 = Node("etc");
	
	
	l1->insertAtEnd(&n1);
	l1->insertAtEnd(&n2);

	l1->insertBeforeName("bilal",&n4);
	l1->insertAtEnd("abdulQudoos");
	l1->insertAtBeginning("hseeb");
	
	l1->printAll();
	
	l1->makeCircular();
	cout<<l1->isCircular()<<endl;
	cout<<l1->tail->data<<endl;
	cout<<l1->hasCycle(l1->head);
	
	
			
	return 0;
			
		}
