#include<iostream>
using namespace std;
struct node{
	int info;
	node *left ;
	node *right;
};
class AVL{
	public:
		node *root ,*temp , *temp2 , *temp3;
		
		int val;
		
		void insert(int key , node *&temp);
		
		void Inorder(node *temp);
		
		int height(node *temp);
		
		int Balancing_Factor(node *temp);
		
		void singlerightrot(node *&temp);
		
		void singleleftrot(node *&temp);
		
		node* Successor(node *temp);
		
		void AVL_Del(int key , node *&temp);
		AVL(){
			
	 root = temp = temp2 = temp3 = NULL;
	 val=0;
		
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
	if(temp==NULL){
	temp=new node;
	temp->info=key;
	temp->left=temp->right=NULL;

	return;
	}
	
		if(key==temp->info){
		cout<<"Number already exists"<<endl;
		
		}
	
		else if(key<temp->info){
		insert(key,temp->left);
		}

		else if(key>temp->info){
		insert(key,temp->right);
		}
	
	/////
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
		if(key > temp->right->info){      //ambiguity in < > signs btw key and  info
			//// right right
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

node* AVL::Successor(node *temp){ 
	if(temp->left==NULL){
		return temp;
	}
	temp3=temp;
	return Successor(temp->left);
}

void AVL::AVL_Del(int key , node *&temp){
	if(root==NULL){
		cout<<"Tree is empty "<<endl;
		return;
	}
	if(temp==NULL){
		cout<<"Not Found "<<endl;
		return;
	}
	
	if(temp->info==key){
		
		if((temp->left==NULL)&&(temp->right==NULL)){    //leaf case
			
			if(temp==root){
				root=NULL;
				delete temp;
				temp=NULL;        // if only root is there
				return;
			}
			else{
				delete temp;
				temp=NULL;
			}
		}
		if((temp->left==NULL)&&(temp->right != NULL)){
			temp2=temp;
			temp=temp->right;
			delete temp2;
			temp2=NULL;
			}
		if((temp->right==NULL)&&(temp->left != NULL)){
			temp2 = temp;
			temp=temp->left;
			delete temp2;
			temp2=NULL;
		}
		if((temp->left != NULL)&&(temp->right != NULL)){
			temp2=Successor(temp->right);
			
			val = temp2->info;
			
			AVL_Del(temp2->info , root);
			
			temp->info = val;
			
		}

			 
		}
	
	if(key<temp->info){
	AVL_Del(key ,temp->left);
	}

	if(key>temp->info){
	AVL_Del(key, temp->right);
	}
    int balance = Balancing_Factor(temp);
 
 
    // Left Left Case
    if (balance ==2 && Balancing_Factor(temp->left) >= 0)
        return singlerightrot(temp);
 
    // Left Right Case
    if (balance ==2 && Balancing_Factor(temp->left) < 0)
    {
        singleleftrot(temp->left);
        return singlerightrot(temp);
    }
 
    // Right Right Case
    if (balance == -2 && Balancing_Factor(temp->right) <= 0)
        return singleleftrot(temp);
 
    // Right Left Case
    if (balance == -2 && Balancing_Factor(temp->right) > 0)
    {
    	singlerightrot(temp->right);
        return singleleftrot(temp);
    }
}
int main(){
	AVL bt;
	bt.insert(45 , bt.root);
	bt.insert(66, bt.root);
	bt.insert(22, bt.root);
	bt.insert(11,bt.root);
	bt.insert(54,bt.root);
	bt.insert(55,bt.root);
	bt.Inorder(bt.root);
	cout<<endl;
	cout<<"The balancing factor is "<<bt.Balancing_Factor(bt.root)<<endl;
	cout<<"The Height of tree is "<<bt.height(bt.root)<<endl;
	bt.AVL_Del(66,bt.root);
	bt.AVL_Del(55,bt.root);
	
	cout<<endl;
	bt.Inorder(bt.root);
	
	return 0;
}

