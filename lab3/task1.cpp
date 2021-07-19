#include<iostream>
#include<string>
using namespace std;

struct Stack{
	int *arr;
	int capacity;
	int top;
	
	Stack(int size){
		arr = new int[size];
		capacity = size;
		top = -1;
	}
	
	
	// adding data in stack and checking for stack overfollow
	void push(int x){
		
		if(top<capacity){
			cout<<"Inserting ";
			cout<<x<<endl;
			arr[++top] = x;	
		}
		
	}
	
	// getting top element and checking for stack overfollow
	int pop(){
		if(top!= -1)
		{
		cout<<"Removing ";
		cout<<arr[top]<<endl;
		int r = arr[top];
		--top; 
		return r;
		}
	}
	
	// function to get top element
	
	int peek(){
		return arr[top];
	}
	
		int size(){
			return top+1;
		}
		bool isEmpty(){
			return top==-1;
		}
		
		bool isFull(){
			return top == capacity;
		}
};


int main(){
	
	Stack *stack = new Stack(3);
	
	stack->push(1);
	stack->push(2);
	
	cout<<stack->pop()<<endl;
	cout<<stack->pop()<<endl;

	stack->push(3);
	

	cout<<"top element is: ";
	cout<<stack->peek()<<endl;

	cout<<"Stack size is: ";
	cout<<stack->size()<<endl;

	
	stack->pop();
	
	if(stack->isEmpty())
	{
		cout<<"stack is empty"<<endl;
	}
	else
	{
		cout<<"stack is not empty "<<endl;
	}
}
