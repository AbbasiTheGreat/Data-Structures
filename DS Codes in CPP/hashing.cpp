#include<iostream>
using namespace std;
class hashing{
	private:
		int *arr;
		int *temp1;
		int *temp2;
		int count;
		int flag;
		int percent;
	public:
		int size;
		hashing(int s);
		void insert(int num);
		void checking();
		int Searchprime(int num);
		void show();
};
hashing::hashing(int s){
	size = s;
	count = 0;
	flag = 0;
	arr = new int[size];
	percent = size/2;
}
void hashing::insert(int num){
	int remainder = num % size;
	
	if(arr[remainder] == 0){
		arr[remainder] = num;
		count++;
		if(flag == 0){
			checking();
		}
		
	}
	
	if(arr[remainder] != 0){
		while(arr[remainder] != 0){
			remainder++;
		}
		arr[remainder] = num;
		count++;
		if(flag == 0){
			checking();
			
		}
		
	}
}

void hashing::checking(){
	if(percent == count){
		flag = 1;
		temp1 = arr;
		int newsize = Searchprime(size*2);
		temp2 = new int[newsize];
		
		int presize = size;
		size = newsize;
		percent = size / 2;
		arr = temp2;
		count = 0;
		for(int i=0 ; i< presize ; i++){
			if(temp1[i] != 0){
				insert(temp1[i]);
			}
		}
		flag = 0;
	}
}
int hashing::Searchprime(int num){
	int flag1 = 0;
	while(true){
		for(int i=2; i < (num+1)/2; i++){
			
			if(num % i == 0){
				flag1 = 1;
				break;
			}
		}
		if(flag1==1){
			num++;
			flag1 = 0;
		}
		else{
		return num;
	}
	
	}
}
void hashing::show(){
	for(int i=0 ; i<size ; i++){
		cout<<arr[i]<<endl;
	}
	cout<<endl;
}
int main(){
	hashing hsh(5);
	hsh.insert(1);
	hsh.insert(2);
	hsh.insert(3);
	hsh.insert(4);
	hsh.insert(5);
	hsh.show();
}
