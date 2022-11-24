#include<iostream>
using namespace std;
struct node{
	int info;
	node *left , *right;
};
class BST{
	public:
		node *temp1 , *temp2;
		void deletion(int key , node *temp);
};
void BST::deletion(int key , node *temp){
	if(temp->info < key){
		if(temp->right->info==key){
			if((temp->right->right == NULL)&&(temp->right->left==NULL)){    //case 1: node having no children (leaf)
				delete temp->right;
				temp->right= NULL;
			}
			if((temp->right->right != NULL)&&(temp->right->left == NULL)){
				 
				 
				 temp1 = temp->right;                                     // case 2(i): node having right child
				temp->right= temp->right->right;
				delete temp1;                                  
				temp1=NULL;
			}
			if((temp->right->right == NULL)&&(temp->right->left != NULL)){
				temp1= temp->right;                                       // case 2(ii): node having left child
				temp->right= temp->right->left;
				delete temp1;
				temp1 = NULL;
			}
			if((temp->right->right != NULL)&&(temp->right->left != NULL)){
				// finding successor
				temp1= temp->right->right;
				if(temp1->left !=NULL){
					while(temp1->left->left != NULL){
						temp1 = temp1->left;
					}
				}
				temp->right->info = temp1->left->info;
				temp2 = temp1->left;
				delete temp2;
				temp2 = NULL;
			}
		}
	}
	if(temp->info > key){
		if(temp->left->info==key){
			if((temp->left->right == NULL)&&(temp->left->left == NULL)){
				delete temp->left;
				temp->left = NULL;
			}
			if((temp->left->left == NULL)&&(temp->left->right != NULL)){
				temp1= temp->left;
				temp->left= temp->left->left;
				delete temp1;
				temp1 = NULL;
			}
			if((temp->left->left != NULL)&&(temp->left->right == NULL)){
				temp1= temp->left;
				temp->left = temp->left->right;
				delete temp1;
				temp1 = NULL;
			}
			if((temp->left->left  != NULL)&&(temp->left->right != NULL)){
				temp1 = temp->left->left;
				if(temp1->right != NULL){
					while(temp1->right->right != NULL){
						temp1= temp1->right;
					}
					
				}
				temp->right->info = temp->right->info;
				temp2 = temp1->right;
				delete temp2;
				temp2 = NULL;
			}
		}
	}
}
int main(){
	BST bt;
	
}
