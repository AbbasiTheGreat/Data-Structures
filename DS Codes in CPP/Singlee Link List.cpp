#include<iostream>
using namespace std;
// singlee link list
struct node{
	int data;
	node *next;
};
class list{
	public:
	list();
	~list();
	void disp();
	void insert();
	void del();
	private:
		node *head , *temp , * temp1;
	
};
list::list(){
	head = temp = temp1 = NULL;
}
void list::insert(){
	if(head==NULL){
	head = new node;
	cout<<"Enter an element to insert "<<endl;
	cin>>head->data;
	head->next=NULL;
		return ;
}
	temp = head;
	cout<<"Enter Key to add number after key "<<endl;
	int key;
	cin>>key;
	while(temp!=NULL){
		if(temp->data==key){
			temp1= new node;
			cout<<"Enter element you want to insert"<<endl;
			cin>>temp1->data;
			temp1->next=temp->next;
			temp->next=temp1;
			break;
			 
		}
		temp=temp->next;
	}
	

	
}
void list::del(){
	if(head==NULL){
		return;
	}
	temp=head;
	cout<<"Enter Number to delete "<<endl;
	int key;
	cin>>key;
	if(head->data==key){  // if key is at first node
		head=head->next;      
		delete temp;
		temp=head;
	}
	while(temp!=NULL){
		if(temp->next!=NULL){
			if(temp->next->data==key){
				temp1=temp->next;
				temp->next=temp->next->next;
				delete temp1; //deletes the value the pointer is pointing to,
				temp1=NULL; // pointer equals to null to avoid a dangling pointer
			}
		}
		temp=temp->next;

}
}

list::~list(){
	delete head;
	delete temp1;
	delete temp;
}
void list::disp(){
	temp=head;
	while(temp!=NULL){
	cout<<temp->data<<" ";
	temp=temp->next;
}
}
int main(){
	list a;
	a.insert();
	a.insert();
	a.disp();
	a.del();
	a.disp();
}
