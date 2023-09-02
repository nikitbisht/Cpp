//Merge Sorted Array

#include<iostream>
#include<vector>
using namespace std;
//Print array
void print(vector<int>arr){
	cout<<endl;
	for(int i=0;i<arr.size();i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}
// merge Sorted
vector<int> merge_sorted(vector<int>arr1,vector<int>arr2){
	int i=0,j=0;
	vector<int>arr3;
	while(i<arr1.size()&&j<arr2.size()){
		if(arr1[i]<arr2[j]){
			arr3.push_back(arr1[i++]);
		}
		else{
			arr3.push_back(arr2[j++]);
		}
	}
	while(i<arr1.size()){
		arr3.push_back(arr1[i++]);
	}
	while(j<arr2.size()){
		arr3.push_back(arr2[j++]);
	}
	return arr3;
}

//input in array
vector<int>input(vector<int>arr){
	cout<<"Size of array:- "<<endl;
	int n,a;
	cin>>n;
	cout<<"Add element in array:- "<<endl;	
	for(int i=0;i<n;i++){
		cin>>a;
		arr.push_back(a);
	}
	return arr;
}
//main function
int main(){
	vector<int>arr1;
	vector<int>arr2;
	vector<int>arr3;
	arr1=input(arr1);
	arr2=input(arr2);
	arr3=merge_sorted(arr1,arr2);
	print(arr3);
}
