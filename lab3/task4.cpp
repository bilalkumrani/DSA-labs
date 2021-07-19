#include<iostream>
#include<string>
using namespace std;
struct Node
{
    int data;
    Node *next ;
};

struct Queue{
	Node *front, *rear;
	
	Queue()
    {
        front = rear = NULL;  //   Initially
    }
    void enqueue(int item)    // for insertion from rear
    {
    	cout<<"Inserting "<< item<<endl;
        Node *newnode;
        newnode = new Node;
        newnode->data = item;
        newnode->next = NULL;
        if(front == NULL)
            front = rear = newnode;
        else
        {
            rear->next = newnode;
            rear = newnode;
        }
    }
    
    
    void dequeue()            // for deletion from front
    {
    	cout<<"Removing "<<front->data<<endl;
        Node *temp;
        if(front == NULL)
            cout<<"Queue is Empty";
        else
        {
            temp= front;
            front = front->next;
            delete temp;
        }
    }
    bool isEmpty(){
    	return front==NULL;
	}
    
    int peek(){
    	if(!isEmpty())
    	{
    		return rear->data;
		}
		return -1;
	}
};

int main(){
	Queue *q = new Queue();
	q->enqueue(1);
	q->enqueue(2);
	q->enqueue(3);
	q->enqueue(4);
	
	cout<<"Front element is: "<< q->peek()<<endl;
	
	q->dequeue();
	q->dequeue();
	q->dequeue();
	q->dequeue();
	
	if(q->isEmpty()){
		cout<<"Queue is Empty "<<endl;
	}
	else{
		cout<<"Queue is not Empty "<<endl;
	}
}
