#include <iostream>
#include <conio.h>
#include <string>
using namespace std;
//node blueprint
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

// list
struct DoublelinkedList{
	
	Node *head;
  	
 
  	DoublelinkedList()
  	{
      head = NULL;
      
  	}
  		// inserting node at the 
  	void insertAtBeginning(string data){
  		Node *n1 = new Node();
  		n1->data = data;
  		if(head==NULL){
  			head = n1;
		  }
		  else
		  {
		  	n1->next = head;
		  	head->pre = n1;
		  	head = n1;
		  }
	  }

	// inserting node at the beginning
	void insertAtBeginning(Node *newNode){
		if(head==NULL)head=newNode;
		else
		{
			newNode->next = head;
			head->pre = newNode;
			head = newNode;
		}
		
	}
	
		// inserting node at the end
		void insertAtEnd(string name){
			Node *newNode = new Node();
			newNode->data = name;
			newNode->next = NULL;
			newNode->pre = NULL;
			if(head==NULL)
			{

				head = newNode;
				
			}
			else{
				
				Node *cur = head;
				while(cur->next != NULL){
					cur = cur->next;	
				}
			
			newNode->pre = cur;
			cur->next = newNode;
			
			}
			
				}
		// inserting node at the end
		void insertAtEnd(Node *newNode){
			if(head==NULL) head =newNode;
			else{
			
			Node *cur = head;
			while(cur->next!=NULL){
				cur = cur->next;
				}
				newNode->pre = cur;
				cur->next = newNode;
			}		
		}
	
			// inserting node after given name
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
						
						cur->next = newNode;
					}
					cur = cur->next;
				}
				
				
			}
			
		}
			// inserting node before given name
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
		// making list circular
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
		// printing all the nodes values
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
		//checking for loop in a list
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
		
	
};

int main(){
	
	DoublelinkedList *l1 = new DoublelinkedList();
	Node n1 = Node("bilal");
	Node n2 = Node("khan");
	Node n4 = Node("4");
	
	l1->insertAtEnd(&n1);
	l1->insertAtEnd(&n2);

	l1->insertBeforeName("bilal",&n4);
	
	l1->printAll();
	l1->makeCircular();
	cout<<l1->isCircular();
			
	return 0;
			
		}
