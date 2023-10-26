//Valid Parenthesis
/*
Qn:- Reverse a string using Stack
*/
#include<iostream>
#include<stack>
#include<string>
using namespace std;
bool matches(char top,char ch){
	if(ch==')'&&top=='('||ch==']'&&top=='['||ch=='}'&&top=='{'){
		return true;
	}
	return false;
}
bool isValidParanthesis(stack<int>&st,string str){
	int i=0;
	while(str[i]!='\0'){
		if(str[i] =='(' || str[i]=='[' || str[i]=='{'){
			st.push(str[i]);
		}
		else if(str[i]==')'||str[i]==']'||str[i]=='}'){
			if(st.empty()){
				return false;
			}
			char top=st.top();
			if(matches(top,str[i])){
				st.pop();
			}else{
				return false;
			}
		}
		i++;
	}
	if(st.empty()){
		return true;
	}
	return false;
}
int  main(){
	stack<int>st;
	string str;
	cout<<"Enter the string:- "<<endl;
	getline(cin,str);
	if(isValidParanthesis(st,str)){
		cout<<"Valid Paranthesis"<<endl;
	}else{
		cout<<"Not a Valid Paranthesis"<<endl;
	}
	return 0;
}