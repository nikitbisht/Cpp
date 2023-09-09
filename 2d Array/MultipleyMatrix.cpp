//Multiply two Matrix
#include<iostream>
using namespace std;
#define Max_Size 10

void multiplyMatrix(int arr1[Max_Size][Max_Size],int arr2[Max_Size][Max_Size],int ans[Max_Size][Max_Size],int n){
	int ans1=0,i,j,k;
	for(i=0;i<n;i++){				//rows
		for(j=0;j<n;j++){		
			for(k=0;k<n;k++){		//column
				ans1+=arr1[i][k]*arr2[k][j];
			}
			ans[i][j]=ans1;
			ans1=0;
		}
	}
}

//Input
void Input(int arr[Max_Size][Max_Size],int &n){
	cout<<"Enter the Size of Array:- "<<endl;
	cin>>n;
	cout<<"Enter the Element :- "<<endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			cin>>arr[i][j];
	}
	cout<<endl;
}
//Print
void print(int arr[Max_Size][Max_Size],int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			cout<<arr[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
}

//Main
int main(){
	int arr1[Max_Size][Max_Size];
	int arr2[Max_Size][Max_Size];
	int ans[Max_Size][Max_Size];
	int n;
	Input(arr1,n);
	Input(arr2,n);
	print(arr1,n);
	print(arr2,n);
	multiplyMatrix(arr1,arr2,ans,n);
	
	print(ans,n);
	return 0;
	
}