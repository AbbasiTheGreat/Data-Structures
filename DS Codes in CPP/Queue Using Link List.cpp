#include<iostream>
using namespace std;
struct node{
	int info;
	node *next;
};
class Queue{
	private:
		node *front , *rear , *temp;
	public:
		void Eque(); // insertion of elements
		void Deque(); // deletion of elements
		void print();
		Queue(){
			front=rear=temp=NULL;
		}
};
void Queue::Eque(){
	if(rear==NULL){
		rear = new node;
		cout<<"Enter Data "<<endl;
		cin>>rear->info;
		front = rear;
		rear->next=NULL;
		return;
	}
	if(rear != NULL){
		rear->next= new node;
		cout<<"Enter Data "<<endl;
		cin>>rear->next->info;
		rear=rear->next;
		rear->next=NULL;
		return;
	}
}
void Queue:: Deque(){
	if(front == NULL){
		cout<<"Queue Is Empty "<<endl;
		return;
	}
	else{
		temp= front;
		front  = front->next;
		if(front==NULL){  // if there was only one element then the next would be NULL  
			rear=NULL;     // so we need to nullify rear also to empty the queue;
		}
		delete temp;
		temp = NULL;
	}
}
void Queue::print(){
	if(front == NULL && rear == NULL){
		cout<<"List is empty "<<endl;
		return;
	}
	else{
		while(front != NULL){
			cout<<front->info<<" ";
			front = front->next;
		}
	}
}
int main(){
	Queue q1;
	q1.Eque();
	q1.Deque();
	q1.print();
	q1.Eque();
	q1.Eque();
	q1.print();
}

