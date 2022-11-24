	void print(node* point,int lev,int n){
	
		
		if(n == lev){
		
			cout<<point->value;
		
			return;
		}
	
		if(point->left != NULL){
		
			print(point->left,lev,n+1);
		}
	
		if(point->right != NULL){
		
			print(point->right,lev,n+1);
		}
		
	
	}



	void level_traversal(node* point,int lev){
	
		for(int i=0;i<lev;i++){
		
			print(point,i,0); 
			cout<<endl;
		}

	}
