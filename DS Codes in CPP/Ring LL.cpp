#include<iostream>
using namespace std;
struct node{
	int info;
	node *next;
};
class R_List{
	private:
		node *head , *temp , * temp1;
	public:
		R_List();
		void Insert();
		void print();
	
};
R_List::R_List(){
	head=temp=temp1=NULL;
}
void R_List::Insert(){
	if(head == NULL){
		head = new node;
		cout<<"Enter the first Element "<<endl;
		cin>>head->info;
		head->next = head;
		return;
	}
	temp=head;
//	cout<<"Enter Key to enter value next to Key "<<endl;
//	int key;
//	cin>>key
	while(temp->next != head ){
		temp=temp->next;
		
	}
	temp1=new node;
	cin>>temp1->info;
	temp1->next=head;
	temp->next=temp1;
}
void R_List::print(){
	temp=head;
	while(temp->next!=head){
		cout<<temp->info<<"  ";
		temp=temp->next;
	}
	cout<<temp->info;
}
int main(){
	R_List l;
	l.Insert();
	l.Insert();
	l.Insert();
	l.Insert();
	l.Insert();
	l.print();
	
}
