/*
Qn:- Find the element in the array
Ex:
arr[]={4,12,8,10}
key=8
*/
#include<iostream>
#include<math.h>
using namespace std;
int search(int arr[],int key,int n){
	for(int i=0;i<n;i++){
		if(arr[i]==key)
			return 1;
	}
	return 0;
}
int main(){
	int n;
	int arr[100];
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	int key;
	cin>>key;
	if(search(arr,key,n))
		cout<<"Present"<<endl;
	else
		cout<<"Not Present"<<endl;
	return 0;
}
