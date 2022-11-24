#include<iostream>
using namespace std;
void SelectionSort(int size , int *arr){
	for(int i = 0 ; i < size ; i++){
		
		int temp = arr[i];
		int count = i;
		for(int j = i ; j < size ; j++){
			if(temp > arr[j]){
				temp = arr[j];
				count = j;
			}
		}
		arr[count] = arr[i];
		arr[i] = temp;
	}
}
void print(int size , int *arr){
	for(int i=0 ; i < size ; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
int main(){
	int a[8] = {3,2,1,7,4,9,10 , 11};
	SelectionSort(8 ,a);
	print(8 , a);
}
