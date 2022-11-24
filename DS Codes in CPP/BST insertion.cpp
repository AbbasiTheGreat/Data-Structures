#include<iostream>
using  namespace std;

struct node{
	int info;
	 node *left;
	 node *right;
};
class BST{
	private:
		node *temp;
	public:
		node *root;
		int number;
		BST();
		void Insertion(node *temp);
		void options();
		void Inorder(node *temp);
		
};
BST::BST(){
	root = temp = NULL;
}
void BST:: Insertion(node *temp){
	if(root == NULL){
		temp = new node;
		temp->info= number;
		temp->left=NULL;
		temp->right=NULL;
		root = temp;
		return; 
	}
	if(temp->info==number){
		cout<<"Duplication of Numbers is Not Allowed "<<endl;
		return;
	}
	if(number < temp->info){
		if(temp->left != NULL){
		Insertion(temp->left);
		return;
		}
		else{
			temp->left = new node;
			temp->left->info=number;
			temp->left->left=NULL;
			temp->left->right=NULL;
			return;
		}
		
	}
	if(number > temp->info){
		if(temp->right != NULL){
			Insertion(temp->right);
			return;
		}
		else{
			temp->right = new node;
			temp->right->info= number;
			temp->right->left=NULL;
			temp->right->right=NULL;
			return;
			
		}
	}
	
}
void BST::Inorder(node *temp){
	if(root == NULL){
		cout<<"Tree is Empty "<<endl;
		return;
	}
	if(temp->left != NULL){
		Inorder(temp->left);
	}
	cout<<temp->info<<" ";
	if(temp->right != NULL){
		Inorder(temp->right);
	}
	
}
int main(){
	BST bt;
		cout<<"enter Number to add in tree "<<endl;
		cin>>bt.number;
		bt.Insertion(bt.root);
	bt.Inorder(bt.root);
}
