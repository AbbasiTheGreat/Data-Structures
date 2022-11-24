#include<iostream>
using namespace std;
struct node{
	int info;
	node *next;
	node *previous;
};
class DLL{
	public:
		void insert();
		void del();
		DLL();
		~DLL();
		void display();
	private:
		node *head , *temp , *temp1;
};
DLL::DLL(){
	head = temp= temp1 = NULL;
}
void DLL::insert(){
	if(head==NULL){
		head=new node;
		cout<<"Enter value to insert "<<endl;
		cin>>head->info;
		head->next=head->previous=NULL;
		return ;
	}
	cout<<"Enter Key to insert after key "<<endl;
	int key;
	cin>>key;
	temp= head;
	while(temp!=NULL){
		if(temp->info==key){
			temp1=new node;
			cout<<"Enter Value to insert "<<endl;
			cin>>temp1->info;
			temp1->next=temp->next;
			temp->next=temp1;
			temp1->previous=temp;
			if(temp1->next !=NULL){
				temp1->next->previous= temp1;
			}
		}
		temp=temp->next;
	}
}
void DLL::del(){
	if(head==NULL){
		return;
	}
	temp=head;
	int key;
	cout<<"Enter Value to delete "<<endl;
	cin>>key;
	while(temp!=NULL){
		if(temp->info==key){
		temp->previous->next=temp->next;
		temp->next->previous=temp->previous;
		temp1=temp->previous;
		delete temp;
		temp=temp1;
		}
		temp=temp->next;
	}
	
}
void DLL:: display(){
	temp=head;
	while(temp!=NULL){
		cout<<endl<<temp->info<<" ";
		temp=temp->next;
	}
} 
DLL::~DLL(){
	delete  temp1;
	delete temp;
	delete head;
}
int main(){
	DLL l1;
	l1.insert();
	l1.insert();
	l1.insert();
	l1.del();
	l1.display();
}

