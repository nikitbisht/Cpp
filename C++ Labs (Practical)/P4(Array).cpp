// P4
#include<iostream>
#define Max_Size 100
using namespace std;
//display Array
void task01(int*arr,int n){
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
//Delete Array Element
void task02(int *arr,int n){
	int k,i;
	cout<<"Enter the Element index(0-<n) you want to delete:- "<<endl;
	cin>>k;
	for(i=k;i<n-1;i++){
		swap(arr[i],arr[i+1]);
	}
	arr[i]=0;
	task01(arr,n);
}
//Multiply Matrix
void task03(){
	int arr1[Max_Size][Max_Size];
	int arr2[Max_Size][Max_Size];
	int result[Max_Size][Max_Size];
	int n,m;
	cout<<"Enter no of rows"<<endl;
	cin>>n;
	cout<<"Enter the element of first Matrix"<<endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>arr1[i][j];
		}
	}
	cout<<"Enter the element of second Matrix"<<endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>arr2[i][j];
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			int ans=0;
			for(int k=0;k<n;k++){
				ans+=arr1[i][k]*arr2[k][j];
			}
			result[i][j]=ans;
		}
	}
	cout<<"Matrix Multiplication"<<endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<result[i][j]<<" ";
		}
		cout<<endl;
	}
}
//Pair Sum (two loop)
void task04(){
	int n,sum,cnt=0;
	cout<<"Size of array:- "<<endl;
	cin>>n;
	int arr[Max_Size];
		cout<<"Array Element:- "<<endl;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cout<<"Enter the number you want to find her no of Pair sum:- "<<endl;
	cin>>sum;
	for(int i=0;i<n;i++){
			int y=sum-arr[i];
		for(int j=i+1;j<n;j++){
			if(arr[j]==y){
				cnt++;
			}
		}
	}
	cout<<"Total number of Pair Sum:- "<<cnt<<endl;
}
//Rotate Array
void task05(){
	int n,k;
	cout<<"Size of array:- "<<endl;
	cin>>n;
	int arr[Max_Size];
	cout<<"Array Element:- "<<endl;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
		cout<<"Enter the number of time to rotate array:- "<<endl;
	cin>>k;
	while(k!=0){
		int last=arr[n-1];
		for(int i=n-1;i>0;i--){
			arr[i]=arr[i-1];
		}
		arr[0]=last;
		k--;
	}
	task01(arr,n);
}
int main(){
	int n;
	cout<<"Size of array:- "<<endl;
	cin>>n;
	cout<<"Array Element:- "<<endl;
	int arr[Max_Size];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	task01(arr,n);
	task02(arr,n);
	task03();
	task04();
	task05();
}
