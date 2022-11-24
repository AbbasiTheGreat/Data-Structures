#include<iostream>
using namespace std;
struct node{
	int info;
	node *left;
	node *right;
};
class heap{
	public:
		node *root , *temp;
		int flag;
		int countnode;
		int height;
		int localheight;
		heap(){
			root = temp = NULL;
			countnode= 0;
		}
		void insert(int key , node *temp);
		int power(int base , int p);
		void inorder(node *temp){
			if(root == NULL){
				cout<<"Empty tree "<<endl;
				return;
			}
			if(temp->left != NULL){
				inorder(temp->left);
			}
			cout<<temp->info<<" ";
			if(temp->right != NULL){
				inorder(temp->right);
			}
			return;
		}
};
int heap::power(int base , int p){
	int  result = 1;
	for(int i=0;i<p; i++ ){
		result = result * base;
	}
	return result;
}
void heap::insert(int key , node *temp){
	if(temp== root){
		flag = 0;
	}
	if(root == NULL){
		root = new node;
		root->info = key;
		root->left = root->right = NULL;
		countnode++;
		height = 0;
		return;
	}
	if(temp->info > key){
		int num = key ;
		key = temp->info;
		temp->info = num;
	}
	if(countnode == (power(2 , height + 1)-1)){
		
		while(temp->left != NULL){
			if(temp->info> key){
				int num = key;
				key = temp->info;
				temp->info = num;
			}
			temp= temp->left;
		}
		
		node *temp2 = new node;
		temp2->left = temp2->right=NULL;
		temp2->info = key;
		temp->left= temp2;
		height++;
		countnode++;
		flag = 1;
		if(temp->info > temp->left ->info){
			temp->left->info = temp->info;
			temp->info = key;
		}
		return;
	}
	if(height -  localheight == 1 && temp->left != NULL && temp->right == NULL){
		node *temp2 = new node;
		temp2->info = key;
		temp2->left = temp2->right = NULL;
		temp->right= temp2;
		countnode++;
		if(temp->info >  temp->right->info){
			temp->right->info = temp->info;
			temp->info = key;
		}
		return;
	}
	if(height - localheight ==1 && temp->left == NULL && temp->right == NULL){
		node *temp2=  new node;
		temp2->info= key;
		temp2->left = temp2->right = NULL;
		temp->left= temp2;
		countnode++;
		flag = 1;
		if(temp->info > temp->left->info){
			temp->left->info =  temp->info;
			temp->info = key;	
		}
		return;
	}
	if(temp->left != NULL && flag == 0){
		localheight++;
		insert(key , temp->left);
		localheight--;
	}
	if(temp->right != NULL && flag == 0){
		localheight++;
		insert(key , temp->right);
		localheight--;
		
	}
	if(temp==root){
		flag = 0;
	}
	return;
}
int main(){
	heap cbt;
	cbt.insert(12 , cbt.root);
	cbt.insert(13 , cbt.root);
	cbt.insert(10 , cbt.root);
	cbt.insert(76 , cbt.root);
	cbt.insert(56 , cbt.root);
	cbt.insert(34 , cbt.root);
	cbt.insert(33 , cbt.root);
	cbt.insert(23 , cbt.root);
	cbt.inorder(cbt.root);
	
}
