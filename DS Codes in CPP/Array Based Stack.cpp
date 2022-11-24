#include<iostream>
using namespace std;
class Stack{
	private:
	int *top;
	int *stk;
	int size;
	int *arr;
	int value;
	public:
	Stack(){
		cout<<"Enter size "<<endl;
		cin>>size;
		arr = new int[size];
		top=NULL;
		stk = arr;
	}
	void Push(){
		if(top==stk + size - 1){
			cout<<"Stack OverFlow "<<endl;
			return;
		}
		if(top==NULL){
	
	
			top=stk;
			cout<<"Enter Value "<<endl;
			cin>>value;
			*top=value;
			return;
		}
		top++;
		cout<<"Enter Value "<<endl;
		cin>>value;
		*top=value;
	}
	void Pop(){
		if(top==NULL){
			cout<<"Stack UnderFLow "<<endl;
			return;
		}
		if(top==stk){
			top=NULL;    // one element only
			return;
		}
		top--;
		
	}
	void print(){
		for(int i=0 ; i<size ; i++){
			cout<<*top<<" ";
			Pop();
		}
		cout<<endl;
	}
};
int main(){
	Stack St;
	St.Push();
	St.Push();
	St.print();
	St.Pop();
	
}

