#include<iostream>
using namespace std;
struct node{
	int info;
	node *next;
};
class Stack{
	private:
	 node *top , *temp ;
	 int limit;
	 int count;
	public:
		void push();
		void pop();
		Stack();
};
Stack::Stack(){
	top = temp = NULL;
	cin>>limit;
	count = 0;
}
void Stack::push(){
	if(count == limit){
		cout<<"Stack is Full "<<endl;
		return;
	}
	temp = new node;
	cin>>temp->info;
	temp->next = top;
	top = temp;
	count++;
	
}
void Stack::pop(){
	if(top==NULL){
		return;
	}
	temp = top;
	top= top->next;
	delete temp;
	temp=NULL;
	return;
		
}
int main(){
	Stack s;
	s.push();
	s.push();
	s.pop();
}
