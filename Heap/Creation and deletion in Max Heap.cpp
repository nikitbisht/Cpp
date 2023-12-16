/*
_____________Heap-->MaxHeap____________
For 1 indexing
left child = 2*i
righ child = 2*i+1
parent = i/2
leaf node star = (size / 2)+ 1
__________________________________________________

For 0 indexing
left child = 2*i+1
righ child = 2*i+2
parent = (i-1)/2 //not confirm
leaf node star = size / 2
*/
#include<iostream>
#define Max_Size 100
using namespace std;

class maxheap{
	public:
		int arr[Max_Size];
		int size;
	//consturctor
	maxheap(){
		size=0;
	}
	//insert function int max heap
	void insert(int val){
		size = size + 1;
		int index=size;
		arr[index]=val;
		while(index > 1){
			int parent = index/2;
			if(arr[index] > arr[parent]){
				swap(arr[index],arr[parent]);
				index=parent;
			}else{
				return ;
			}
		}
	}
	//delete function in max heap
	void deletetion (){
		int n = size;
		//Step 1:- put last value in first index
		arr[1] = arr[n];
		size--;
		
		//Step 2:- Update Heap
		int i=1;
		while(i<size){
			int largest = i;
			int left = 2*i;
			int right = 2*i+1;
			if(left <= size && arr[left] > arr[i]){
				i=left;
			}
			if(right <= size && arr[right] > arr[i]){
				i=right;
			}
			
			if(i!=largest){
				swap(arr[i],arr[largest]);
			}else{
				return ;
			}
		}
	}
	//print function in max heap
	void print(){
		for(int i = 1; i <= size; i++){
			cout<<arr[i]<<" ";
		}cout<<endl;
	}
};
int main(){
	maxheap h;
	h.insert(50);
	h.insert(51);
	h.insert(40);
	h.insert(52);
	h.insert(30);
	h.insert(59);
	cout<<"Max Heap element:- "<<endl;
	h.print();
	h.deletetion();
	cout<<"Max Heap element:- "<<endl;
	h.print();
}
