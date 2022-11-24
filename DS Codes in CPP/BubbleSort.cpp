#include<iostream>
using namespace std;

class Bubblesort{
	public:
		int size;
		int *arr;
		void bubblesort();
		void print(){
			for(int i=0 ; i< size ; i++){
				cout<<arr[i]<<" ";
			}
			cout<<endl;
		}
		Bubblesort(int *a , int s){
			arr = a;
			size = s;
		}
};
void Bubblesort::bubblesort(){
	for(int i = 0 ; i < size-1 ; i++){
		
		for(int j = size-1 ;  j > i ; j-- ){
			if(arr[j] > arr[j-1]){
				int temp = arr[j];
				arr[j] = arr[j-1];
				arr[j-1] = temp;
			}
		}
	}
}
int main(){
	int array[6] = {2,3,1,89,21,33};
	Bubblesort bs(array , 6);
	bs.bubblesort();
	bs.print();
}
