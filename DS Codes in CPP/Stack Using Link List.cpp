#include<iostream>
using namespace std;
struct node{
	int info;
	node *next;
};
class Stack{
	private:
		node *top, *temp;
		int count;
	public:
		void Pop();
		void Push();
		void print();
	Stack(){
		temp=top=NULL;
		count=0;
	} 
};
void Stack::Push(){
	if(top==NULL){
		top=new node;
		cout<<"Enter Value "<<endl;
		cin>>top->info;
		top->next=NULL;
		count++;
		return;
	}
	temp=new node;
	cout<<"Enter Value "<<endl;
	cin>>temp->info;
	temp->next=top;
	top=temp;
	temp=NULL;
	count++;
	
}
void Stack::Pop(){
	if(top==NULL){
		cout<<"Stack UnderFlow "<<endl;
		return;
	}
	temp=top;
	top=top->next;
	delete temp;
	temp=NULL;
	count--;
	return;
}
void Stack::print(){
	for(int i=0; i<count ; i++){
		cout<<top->info<<" ";
		Pop();
		count++;
	}
}
int main(){
	Stack st;
	st.Push();
	st.Push();
	st.Push();
	st.print();
	st.Pop();
	
}
