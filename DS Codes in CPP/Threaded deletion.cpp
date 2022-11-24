#include<iostream>
using namespace std;
struct node{
	int info;
	node *right , *left;
	int leftflag , rightflag;	
};

class Thread{
	public:
		node *root , *temp , *dummy;
		void Delete(int key , node *temp);
		void Delete_Node(node *temp , node *parent);
		node* find_successor(node *temp  ,node *&parent); 
		Thread(){
			root = temp =dummy = NULL;
		}
};
node* Thread::find_successor(node *temp , node *&parent){
	if(temp->leftflag == 0){
		return temp;
	}
	parent = temp;
	return find_successor(temp->left , parent);
}
void Thread::Delete(int key , node *temp){
	if(root==NULL){
		cout<<"Tree is Empty "<<endl;
		return;
	}
	if(temp->left->info == key ){
		Delete_Node(temp->left , temp );
		return;
	}
	if((temp != dummy)&& (temp->right->info == key)){
		Delete_Node(temp->right , temp);
		return;
	}
	if(temp==dummy){
		Delete(key , temp->left);
		return;
	}
	if((key > temp->info)&&(temp->rightflag == 1)){
		Delete(key , temp->right);
		return;
	}
	if((key < temp->info)&&(temp->leftflag == 1)){
		Delete(key , temp->left);
		return;
	}
	cout<<"Value Doesnt Exist "<<endl;
	return;
	
}
void Thread::Delete_Node(node *temp , node *parent){
	if((temp->leftflag == 1)&&(temp->rightflag == 1)){
		node *successor_parent = temp;
		node *successor = find_successor(temp->right , successor_parent);
		temp->info = successor->info;
		Delete_Node(successor , successor_parent);      //1
		return;
	}
	if((temp->leftflag == 1)&&(temp->rightflag == 0)){
		if(temp->info < parent->info){
			parent->left = temp->left;
			parent->leftflag = temp->leftflag;
		}
		else{                                               //2
			parent->right = temp->left;
			parent->rightflag = temp->leftflag;
		}
		node *temp2 = temp->left;
		while(temp->rightflag != 0){
			temp2 = temp->right;
		}
		temp2->right = temp->right;
		delete temp;
		return; 
	}
	
	if((temp->leftflag == 0)&&(temp->rightflag == 1)){
		if(temp->info > parent->info){
			parent->right = temp->right;
			parent->rightflag = temp->rightflag;
		}
		else{
			parent->left = temp->left;
			parent->leftflag = temp->leftflag;
		}
		node *temp2 = temp->right;
		while(temp->leftflag != 0){
			temp2 = temp->left;
		}
		temp2->left = temp->left;
		delete temp;
		return;
	}
	
	if((temp->leftflag == 0)&&(temp->rightflag == 0)){
		if(parent->left = temp){
			parent->left  =  temp->left;     // i
			parent->leftflag = 0;
		}
		
		if((parent->right == temp)&&(parent != dummy)){
			parent->right =temp->right;
			parent->rightflag = 0;                   // ii
		}
		
		if(temp == root){
			root = NULL;
			dummy->left = dummy;
			dummy->leftflag= 0;
		}
		delete temp;
		
	}
	
}
int main(){
	Thread Bt;
	Bt.
}
