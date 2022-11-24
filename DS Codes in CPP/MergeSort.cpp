#include<iostream>
using namespace std;
class Mergesort{
	public:
		int *arr;
		int size;
		MergeSort(int *a , int s){
			arr = a;
			size = s;
		}
		void mergesort(int size , int *start , int *end);
		void merging(int size , int *start1 , int *start2);
		void print(int *arr , int size);
};
void Mergesort::mergesort(int size  , int *start , int *end){
	if(size <=1){
		return;
	}
	int mid = size/2;
	int	size2 = size-mid;
	int *start1 = start; 
	int *end1 = start + mid-1;
	int *start2 = start+mid;
	int *end2 = end;
	mergesort(mid , start1 , end1);
	mergesort(size2 , start2 , end2);
	merging(size2 , start1 , start2);
}
void Mergesort:: merging(int size , int *start1 , int *start2){
	for(int i= 0 ; i < size ; i++){
		int *st1 = start1;
		int *st2 = start2;
		for(int j=0 ; j < size ; j++){
			
			if(*st1 > *st2){
				int temp = *st1;
				*st1 = *st2;
				*st2 = temp;
				st1++;
				st2++;
			}
			else{
				st1++;
			}
		}
	}
}
void Mergesort::print(int *arr , int size){
	for(int i=0 ; i< size ; i++){
		cout<<arr[i]<<" ";
}
	cout<<endl;
}
int main(){
	
	int arr[10]={40,2,33,41,12,55,34,23,5,65};
	Mergesort ms;
	int *start = arr;
	int *end = arr+9;
	ms.mergesort(10, start , end);
	ms.print(arr , 10);
}
