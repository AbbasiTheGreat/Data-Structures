#include<iostream>
using namespace std;
struct node{
	int info;
	node *next , *previous;
};
class Doubly_Ring{
	private:
		node *head , *temp , *temp1;
	public:
		void insert();
		void del();
		Doubly_Ring();
		void print();
		
};
Doubly_Ring::Doubly_Ring(){
	head = temp = temp1 = NULL;
}
void Doubly_Ring::insert(){
	if(head==NULL){
		head = new node;
		cout<<"Enter first entry "<<endl;
		cin>>head->info;
		head->next=head->previous=head;
	}
	temp = head;
	cout<<"Enter key to add next "<<endl;
	int key;
	cin>>key;
	if(head->next== head){
		if(head->info==key){
			temp1= new  node;
			cin>>temp1->info;
			temp1->next= head;
			temp1->next->previous= temp1;
			temp1->previous= head;
			return;
		}
	}
	while(temp->next != head){
		if(temp->info==key){
			temp1 = new node;
			cin>>temp1->info;
			temp1->next=temp->next;
			temp1->previous= temp;
			temp->next= temp1;
			temp1->next->previous= temp1;
			
			
		}
		temp = temp->next;
	}
	

}
void Doubly_Ring::del(){
	if(head == NULL){
		return;
	}
	int key;
	cout<<"Enter Value you want to delete "<<endl;
	cin>>key;
	temp= head;
	do{
		if(temp->info==key){
			temp->previous->next =  temp->next;
			temp->next->previous =  temp->previous;
			temp1 = temp;
			temp= temp->previous;
			if(temp1==head){
				head = head->next;
			}
			delete temp1;
		}
		temp= temp->next;
	}while(temp != head);
}
void Doubly_Ring::print(){
	temp= head;
	while(temp->next != head){
		cout<<temp->info<<" ";
		temp= temp->next;
	}
	
	cout<<endl;
}
int main(){
	Doubly_Ring l1;
	int i=0;
	while(i<5){
		l1.insert();
		i++;
	}
	l1.print();
}
