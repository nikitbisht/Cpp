//Phone KeyPad Problem
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void solve(string str,string output,int index,vector<string>&ans,string mapping[]){
	//base case
	if(index>=str.length()){
		ans.push_back(output);
		return ;
	}
	int number=str[index]-'0';
	string value=mapping[number];
	for(int i=0;i<value.length();i++){
		output.push_back(value[i]);
		solve(str,output,index+1,ans,mapping);
		output.pop_back();
	}
}
int main(){
	string str;
	cout<<"Enter the string "<<endl;
	getline(cin,str);
	string output;
	vector<string> ans;
	string mapping[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
	solve(str,output,0,ans,mapping);
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<endl;
	}
	return 0;
}