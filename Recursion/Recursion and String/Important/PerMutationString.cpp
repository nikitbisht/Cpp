//PerMutation of String
/*
ip= abc
op= abc acb bac bca cab cba

*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void solve(string str,int index,vector<string>&ans){
	//base case
	if(index>=str.length()){
		ans.push_back(str);
	}
	//Swapping Approch
	for(int i=index;i<str.length();i++){
		swap(str[i],str[index]);
		solve(str,index+1,ans);
		//Backtracking
		swap(str[i],str[index]);			
	}
}
int main(){
	string str;
	cout<<"Enter the String "<<endl;
	getline(cin,str);
	vector<string>ans;
	solve(str,0,ans);
	cout<<"The Premutation of "<<str<<" is:- "<<endl;
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<endl;
	}
	return 0;
}