#include<iostream>
using namespace std;
struct node{
	int info;
	node *left ;
	node *right;
};
class AVL{
	public:
		node *root;
		
		void insert(int key , node *&temp);
		void Inorder(node *temp);
		int height(node *temp);
		int Balancing_Factor(node *temp);
		void singlerightrot(node *&temp);
		void singleleftrot(node *&temp);
		AVL(){
			
	 root = NULL;
		
		}
	
};
void AVL::singlerightrot(node *&temp){
			node *temp2 = temp->left;
			 temp->left = temp2->right;    // right rotation
			 temp2->right = temp;
			 temp = temp2; 
}
void AVL::singleleftrot(node *&temp){
			node *temp2 = temp->right;
			temp->right = temp2->left;
			temp2->left = temp;           //left rotation
			temp = temp2;
}
int AVL::Balancing_Factor(node *temp){
	int left = 0;
	int right = 0;
	if(temp != NULL){
		if(temp->left != NULL){
		left = height(temp->left);
	}
	if(temp->right != NULL){
		right = height(temp->right);
		
	}
}
		return left - right;
}
int AVL::height(node *temp){
	if(temp==NULL){
		return 0;
	}
	else{
		int left =height(temp->left);
		int right = height(temp->right);
		if(left>right){
			return left+1;
		}
		else{
			return right+1;
		}
	}
	

	
}
void AVL:: insert(int key,node *&temp){
	if(root == NULL){
		temp = new node;
		temp->info=key;
		temp->left=NULL;
		temp->right=NULL;
		root = temp;
		return; 
	}
	if(temp->info==key){
		cout<<"Duplication of Numbers is Not Allowed "<<endl;
	}
	if(key < temp->info){
		if(temp->left != NULL){
		insert(key ,temp->left);
	
		}
		else{
			temp->left = new node;
			temp->left->info=key;
			temp->left->left=NULL;
			temp->left->right=NULL;
		}
		
	}
	if(key > temp->info){
		if(temp->right != NULL){
			insert(key ,temp->right);
		}
		else{
			temp->right = new node;
			temp->right->info= key;
			temp->right->left=NULL;
			temp->right->right=NULL;
		
			
		}
	}
	
	int balance = Balancing_Factor(temp);
	if(balance == 2){
		if(key < temp->left->info){
			///////// lft lft
			 return singlerightrot(temp);                 //single right rotation
		}
		else{
			///// left right
			singleleftrot(temp->left);
			return singlerightrot(temp);
		}
	}
	if(balance == -2){
		if(key > temp->right->info){
			//// righ right
			return singleleftrot(temp);     // left rotation
		}
		else{
			/// right left
			singlerightrot(temp->right);
			return singleleftrot(temp);
		}
	}
}
void AVL:: Inorder(node *temp){
	if(root==NULL){
		cout<<"Empty "<<endl;             // root
		return;
	}
	
	if(temp->left!=NULL){
		Inorder(temp->left);             // left
	}
	cout<<temp->info<<" ";          
	if(temp->right != NULL){
		Inorder(temp->right);                // right
	}
}
int main(){
	AVL bt;
	bt.insert(45 , bt.root);
	bt.insert(66, bt.root);
	bt.insert(22, bt.root);
	bt.insert(11,bt.root);
	bt.insert(3,bt.root);
	bt.insert(2,bt.root);
	bt.insert(1,bt.root);
	bt.insert(56,bt.root);
	bt.insert(45,bt.root);
	bt.insert(89,bt.root);
	bt.insert(99,bt.root);
	bt.insert(23,bt.root);
	bt.insert(33,bt.root);
	bt.insert(10,bt.root);
	bt.insert(16,bt.root);
	bt.Inorder(bt.root);
	cout<<endl;
	cout<<"The balancing factor is "<<bt.Balancing_Factor(bt.root);
	return 0;
}

