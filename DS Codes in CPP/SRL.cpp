#include<iostream>
using namespace std;
struct node{
	int info;
	node *next;
};
class SRL{
	private:
	 node *head , *temp , *temp1;
	public:
		void insert();
		void del();
		void print();
		SRL(){
			temp=temp1=head=NULL;
			
		}
		
};
void SRL::insert(){
	if(head==NULL){
		head = new node ;
		cout<<"Enter 1st Val "<<endl;
		cin>>head->info;
		head->next=head;
	}
	temp=head;
	int key;
	cout<<"Enter Key "<<endl;
	cin>>key;
	if(head->next==head){
		if(temp->info==key){
			temp1= new node;
			cout<<"Enter Value "<<endl;
			cin>>temp->info;
			temp1->next=temp->next;
			temp->next=temp1;
			return;
		}
	}
	while(temp->next!=head){
		if(temp->info==key){
			temp1=new node;
			cout<<"Enter Value "<<endl;
			cin>>temp1->info;
			temp1->next=temp->next;
			temp->next=temp1;
		}
		temp=temp->next;
	}
}
void SRL::print(){
	temp=head;
	while(temp->next!=head){
		cout<<temp->info<<" ";
		temp=temp->next;
	}
	cout<<temp->info;
	cout<<endl;
}
void SRL::del(){
	int key;
	cout<<"Enter key to delete "<<endl;
	cin>>key;
	if(head==NULL){
		return;
	}
	do{
		if(temp->info==key){
			temp1=temp->next;
			temp->next=temp1->next;
			if(temp==head){
				head=head->next;
			}
			delete temp1;
			
		}
		temp=temp->next;
	}while(temp!=head);
}
int main(){
	SRL l;
	l.insert();
	l.insert();
	l.print();
	
	l.del();
	l.print();
}
