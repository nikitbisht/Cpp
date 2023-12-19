//Lowe triganlar mtrix
#include<iostream>
using namespace std;
int main(){
	int n = 3;
	cout<<"Ener the data;:- "<<endl;
	int arr[10][10];
	for(int i =0;i<n;i++){
		for(int j = 0;j<n;j++){
			scanf("%d",&arr[i][j]);
		}
	}
	cout<<"hel"<<endl;
	for(int i =n/2;i<n ;i++){	//row
		for(int j =0;j<n;j++){	//column
			if(j<=i){
				cout<<arr[i][j]<<" ";
			}
		}
	}
}