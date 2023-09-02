// Check Sorted or Rotated
/*
focus on case then code
case 1:- 	1 2 3 4 5		arr[i-1]>arr[i]	||arr[n-1]>arr[0]		1 pair
case 2:-	4 5 1 2 3		arr[i-1]>arr[i]	||arr[n-1]>arr[0]		1 pair
case 3:-	4 1 6 7 4		arr[i-1]>arr[i]	||arr[n-1]>arr[0]		2 pair
*/
#include<iostream>
#include<vector>
using namespace std;
int check_rotate(vector<int>arr){
	int count=0;
	for(int i=1;i<arr.size();i++){
		if(arr[i-1]>arr[i])
			count++;
	}
	if(arr[arr.size()-1]>arr[0])
		count++;
	return count<=1;
}
int main(){
	int n,a;
	cin>>n;
	vector<int>arr;
	for(int i=0;i<n;i++){
		cin>>a;
		arr.push_back(a);
	}
	cout<<check_rotate(arr)<<endl;
	return 0;
}
