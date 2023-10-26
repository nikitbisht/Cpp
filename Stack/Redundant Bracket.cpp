/*
Qn:- Reduntant Bracket
a pair of bracket is said to be redundant when a subexpression is surrounded by needless/useless bracked
conditions:
	valis paranthesis
	only { bracket
*/
#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool isRedundant(stack<int>&st,string &str){
	int i=0;
	while(str[i]!='\0'){
		if(str[i] =='('||str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/'){
			st.push(str[i]);
		}
		else if(str[i]==')'){	// closing bracket
			bool flag=true;
			while(st.top()!='('){
				char top=st.top();
				if(top=='+'||top=='-'||top=='*'||top=='/'){
					flag=false;
				}
				st.pop();
			}
			if(flag){
				return true;
			}
			st.pop();
		}
		i++;
	}
	return false;
}
int  main(){
	stack<int>st;
	string str;
	cout<<"Enter the string:- "<<endl;
	getline(cin,str);
	if(isRedundant(st,str)){
		cout<<"Redundant Bracket"<<endl;
	}else{
		cout<<"Not a Redundant Bracket"<<endl;
	}
	return 0;
}
