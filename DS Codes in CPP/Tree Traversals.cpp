#include<iostream>
using namespace std;

// Tree Traversals
void Post_ord(node *temp){
	if(temp==NULL){
		cout<<"Tree is Empty "<<endl;
		return;
	}
	if(temp->left != NULL){
		Post_ord(temp->left);
	}
	if(temp->right != NULL){
		Post_ord(temp->right);
	}
	cout<<temp->info<<" ";
}

void Pre_ord(node temp){
	if(temp==NULL){
		cout<<"Tree is Empty "<<endl;
		return;
	}
	cout<<temp->info<<" ";
	
	
	if(temp->left != NULL){
		Post_ord(temp->left;)
	}
	if(temp->right != NULL){
		Post_ord(temp->right)
	}

	
}
void InOrder(node *temp){
	if(temp == NULL){
		cout<<"Tree is Empty "<<endl;
		return; 
	}
	if(temp->left !=NULL){
		InOrder(temp->left);
	}
	cout<<temp->info<<endl;
	if(temp->right != NULL){
		InOrder(temp->right)
	}
}
