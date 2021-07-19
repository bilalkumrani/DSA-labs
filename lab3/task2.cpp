#include<iostream>
#include<string>
using namespace std;

// Declare Node of linked list stack

struct Node
{
	int data;
	Node *next;
};

struct Stack{
	
 Node* top;
 
 Stack(){
 	top = NULL;
 }


void push(int data)
{	
	Node* temp;
	temp = new Node();
	temp->data = data;
	temp->next = top;
	top = temp;
	cout<<"Inserting ";
	cout<<data<<endl;
}

// Utility function to check if the stack is empty or not
int isEmpty()
{
	return top == NULL;
}

// Utility function to return top element
int peek()
{
		if (!isEmpty())
		return top->data;
}

// Utility function to pop top element from the stack
void pop()
{
	Node* temp;

	if (top == NULL)
	{
		cout << "there is nothing" << endl;
		
	}
	else
	{
		cout<<"Removing: "<< top->data<<endl;
		
		temp = top;
		top = top->next;
		temp->next = NULL;

		
	}
}

// print all the elements of the stack
void display()
{
	Node* cur;

	if (top == NULL)
	{
		cout << "there is nothing to show";
	}
	else
	{
		cur = top;
		while (cur != NULL)
		{
			cout << cur->data <<endl;
			cur = cur->next;
		}
	}
}

};
int main()
{
	Stack *stack = new Stack();
	
	stack->push(1);
	stack->push(2);
	stack->push(3);
	
	
	cout<<"top element is: ";
	cout<<stack->peek()<<endl;
	
	stack->pop();
	stack->pop();
	stack->pop();
	
	if(stack->isEmpty()){
		cout<<"Stack is Empty";
	}
	else{
		cout<<"stack is not empty";
	}
	
		
	return 0;
}


