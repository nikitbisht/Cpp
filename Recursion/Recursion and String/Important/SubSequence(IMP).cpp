//Subsequence
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void solve(string str,string output,int index,vector<string>&ans){
	//base case
	if(index>=str.length()){
		if(output.length()>0){
			ans.push_back(output);
		}
		return ;
	}
	//exclusion
	solve(str,output,index+1,ans);
	//inclusion
	char ch=str[index];
	output.push_back(ch);
	solve(str,output,index+1,ans);
}
int main(){
	string str;
	getline(cin,str);
	string output;
	vector<string>ans;
	solve(str,output,0,ans);
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<endl;
	}
	return 0;
}