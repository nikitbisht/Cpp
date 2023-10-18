// SubSets
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void solve(vector<int>arr,vector<int>output,int index,vector<vector<int>>&ans){
	//base case
	if(index>=arr.size()){
		ans.push_back(output);
		return ;
	}
	//exclusion
	solve(arr,output,index+1,ans);
	//inclusion
	int number=arr[index];
	output.push_back(number);
	solve(arr,output,index+1,ans);
}
int main(){
	int n;
	cout<<"Enter the size of array :- "<<endl;
	cin>>n;
	cout<<"Enter array Element:- "<<endl;
	vector<int>arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	vector<vector<int>>ans;
	vector<int>output;
	int index=0;
	solve(arr,output,index,ans);
	for(int i=0;i<ans.size();i++){
		for(int j=0;j<ans[i].size();j++){
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
//	std::cout<<ans<<endl;
	return 0;
}
