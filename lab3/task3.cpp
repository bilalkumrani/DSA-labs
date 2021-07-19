#include<iostream>
#include<string>
using namespace std;

struct Queue{
	int *arr, capacity, front, rear, count;
	
	// constructor to initialize queue
	Queue(int size){
		arr = new int[size];
		capacity = size;
		front = -1;
		rear = -1;
		count = 0;
	}
	
	bool isFull(){
		return (rear == capacity - 1);
	}
	
	bool isEmpty(){
		return (front == - 1 || front > rear);
   	   }
	
	
	void enqueue(int val) {
    if (isFull())
    cout<<"Queue is full"<<endl;
    else {
       if (front == - 1)
       front = 0;
       cout<<"Inserting the element "<< val <<endl;
       rear++;
       arr[rear] = val;
    }
}


	void dequeue() {
   	if (isEmpty()) {
   	   cout<<"Queue is empty";
    	  return ;
   	} else {
    	  cout<<"Element dequeued from queue is : "<< arr[front] <<endl;
      	front++;
  	 }
	}

	int peek(){
		if(!isEmpty()){
			return arr[front];
		}
	
	}
	int size(){
		return rear;
	}

	
};

int main()
{	
	Queue *q = new Queue(5);	
	q->enqueue(1);
	q->enqueue(2);
	q->enqueue(3);
	
	cout<< "front elelemt is: "<< q->peek()<<endl;
	q->dequeue();
	cout<< "front elelemt is: "<< q->peek()<<endl;
	
	cout<<"Queue size is: "<< q->size()<<endl;
	
	q->dequeue();
	q->dequeue();
	
	if(q->isEmpty()){
		cout<<"Queue is empty"<<endl;
		
	}
	else{
		cout<<"Queue is not empty"<<endl;
	}
}

