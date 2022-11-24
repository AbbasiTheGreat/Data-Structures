#include<iostream>
using namespace std;
class Queue{
	private:
		int *front , *rear , *que;
		int size;
	public:
		void Enque();
		void print();
		void Deque();
		Queue(){
			size = 4;
			que = new int[size];
			front = rear =  NULL;
		}
		
};
void Queue::Enque(){
	if(rear == NULL){
		front = rear = que;
		cout<<"Enter Value "<<endl;
		cin>>*rear;
		return;
		
	}
	if(((rear==(size-1)+que) && front == que) ||(rear+1==front)){
		cout<<"Queue is Full "<<endl;
		return; 
		
	}
	
	rear++;
	cout<<"Enter Value "<<endl;
	cin>>*rear;
	return;
}
void Queue::print(){
	int *val=front;
	while(val!=rear){
		cout<<*val<<" ";
		val++;
	}
	cout<<*val<<endl;
	return;
}
void Queue::Deque(){
	if(front==NULL){
		cout<<"Que is Empty "<<endl;
		return;
	}
	if(front==rear){
		front = rear = NULL;    // one element only
		return;
	}
	if(front==(size-1)+que){
		front = que;         
		return;
	}
	front++;
}
int main(){
	Queue q1;
	q1.Deque();
	q1.Enque();
	q1.Deque();
	q1.Enque();
	q1.Enque();
	q1.Enque();
	q1.Enque();
	q1.Enque();
	q1.Deque();
	q1.Deque();
	q1.Enque();
	q1.print();
}
