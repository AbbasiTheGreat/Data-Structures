#include<iostream>
using namespace std;
struct node{
	int info;
	node *left , *right;
	int leftflag , rightflag;
};
class Threaded_BT{
	public:
		node *temp , *root , *dummy;
		
		Threaded_BT()
		{
		dummy = new node;
		dummy->left=dummy;
		dummy->right=dummy;
		dummy->leftflag = 0;     
		dummy->rightflag = 1;
		root=temp=NULL;	
		}
		
		void Insert(int key ,node *temp);
		void Inorder(node *temp);
};
void Threaded_BT::Insert(int key ,node *temp)
{
	if(root == NULL)
	{
		root = new node;
		root->info=key;
		root->left=root->right=dummy;
		root->leftflag = root->rightflag = 0;
		dummy->left = root;
		dummy->leftflag=1;
		return;
	}
	if(temp->info==key){
		cout<<"Duplicate Value "<<endl;
		return;
	}
	if(key<temp->info)
	{
		if(temp->leftflag==0){
				node *n = new node;   // for pionting to parent
				n->info = key;
				n->left = temp->left;
				n->leftflag = temp->leftflag;        //insertion
				n->right = temp;
				n->rightflag=0; 	
				temp->left = n;
				temp->leftflag =1;
				return;
		}
		else{
			Insert(key , temp->left);
		}
		if(key>temp->info){
			if(temp->rightflag==0){
				node *n = new node;
				n->info = key;
				n->right = temp->right;
				n->rightflag = temp->rightflag;
				n->left=temp;
				n->leftflag=0;
				temp->right=n;
				temp->rightflag=1;    
				return;            
			}
			else{
				Insert(key , temp->right);
			}
		}
	}
}
void Threaded_BT::Inorder(node *temp){
	if(root==NULL){
		cout<<"Empty "<<endl;             // root
		return;
	}
	
	if(temp->leftflag != 0){
		Inorder(temp->left);             // left
	}
	cout<<temp->info<<" ";          
	if(temp->rightflag != 0){
		Inorder(temp->right);                // right
	}
}
int main(){
	Threaded_BT bt;
	bt.Insert(6,bt.root);
	bt.Insert(3,bt.root);
	bt.Insert(5,bt.root);
	bt.Insert(1,bt.root);
	bt.Insert(8,bt.root);
	bt.Insert(7,bt.root);
	bt.Insert(11,bt.root);
	bt.Insert(9,bt.root);
	bt.Insert(13,bt.root);
	bt.Inorder(bt.root);
}
