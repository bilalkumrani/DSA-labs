#include<iostream>
#include <string.h>
using namespace std;




class Node
{
	public:
	int data;
	Node *next;
	Node()
	{
		this->data = 0;
		this->next = NULL;
	}
	
};
class linkedList
{
	
	Node *head;
	int total;
	public:
	List()
	{
		head = NULL;
		total = 0;  
	}
	
	bool isEmpty()
	{
		return head == NULL;
	}
	
	int size()
	{
		return total;
	}
	
	void add(int data)
	{
		Node *n = new Node();
		n->data = data;
		if(isEmpty()){
			head = n;
			total++;
		}
		else
		{
			Node *cur = head;
			while(cur->next!=NULL){
				cur = cur->next;
			}
			cur->next = n;
			total++;
		}
	}
	
	void addAt(int data, int index)
	{
		Node *n = new Node();
		n->data = data;
		n->next=NULL;
		if(isEmpty()){
			head = n;
			total++;
		}
		else
		{
			int i=0;
			Node *cur = head;
			while(cur->next!=NULL){
				
				if(i==index)
				{
					break;
				}
				cur = cur->next;
				i++;
			}
			n->next = cur->next;
			cur->next = n;
			total++;
		}
	}
	
	
	void ToString()
	{
		
		Node *cur = head;
		while(cur->next!=NULL)
		{
			
			cout<<cur->data;
			cout<<"_";
			cur = cur->next;
		}
		cout<<cur->data;
	}
	
	
	
	
	 void remove(int index){
	 	if(isEmpty())
	 	{
	 		return;
		 }
	 	Node *cur = head;
		for(int i=0; i<index;i++ )
		{
			cur = cur->next;
		}
		Node *temp = cur;
		cur = cur->next;
		delete temp;

	}
	
	
};


int main(){
	
	linkedList *l1 = new linkedList();
	cout<<l1->isEmpty()<<endl;
	l1->add(10);
	l1->add(11);
	l1->add(12);
	l1->add(13);
	l1->add(14);
	l1->add(15);
	
	l1->addAt(16,0);
	
	
	
	
	cout<<l1->size()<<endl;
	l1->remove(3);
	
	l1->ToString();
}
