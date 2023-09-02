// Move Zeor at right
#include<iostream>
#include<vector>
using namespace std;
//Print 
void print(int arr[],int n){
	cout<<endl;
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}
//Move zero
int move_zero(int arr[],int n){
	int i=0,j=0;
	while(i<n&&j<n){
		if(arr[j]!=0){
			swap(arr[i],arr[j]);
			i++;
		}
		j++;
	}
	return 0;
}
//Main
int main(){
	int n;
	cin>>n;
	int arr[100];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	move_zero(arr,n);
	print(arr,n);
	return 0;
}
