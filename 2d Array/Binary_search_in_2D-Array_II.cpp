// Binary Search in 2D array II
/*
element is shorted in row and column wise
1   4   7   11  15
2   5   8   12  19
3   6   9   16  22
10  13  14  17  24
18  21  23  26  30
*/
#include<iostream>
using namespace std;
bool binarySearch(int arr[][10],int target,int row,int column) {
	int rowIndex=0;
	int colIndex=column-1;
	while(rowIndex<row&&colIndex>=0){
		int element=arr[rowIndex][colIndex];
		if(element==target){
			return 1;
		}
		else if(element<target){		// element not present in this row || element present in this cloumn
			rowIndex++;
		}
		else if(element>target){		// element not present in ths cloumn || element present in this row
			colIndex--;;
		}
	}
	return 0;	
}

int main() {
	int arr[10][10];
	int row,column;
	cout<<"Enter the no of rows and coloum "<<endl;
	cin>>row>>column;
	cout<<"Enter Array Element:- "<<endl;
	for(int i=0; i<row; i++) {		//row
		for(int j=0; j<column; j++) {
			cin>>arr[i][j];
		}
	}
	cout<<"Your array is ready:- "<<endl;
	for(int i=0; i<row; i++) {
		for(int j=0; j<column; j++) {
			cout<<arr[i][j]<<"  ";
		}
		cout<<endl;
	}
	int target;
	cout<<"Enter the target:- "<<endl;
	cin>>target;
	if(binarySearch(arr,target,row,column))
		cout<<"Present"<<endl;
	else 
		cout<<"Not Present"<<endl;
	return 0;
}