/*
Qn:- Reverse a string using Stack
*/
#include<iostream>
#include<stack>
using namespace std;
int  main(){
	stack<int>st;
	string str;
	cout<<"Enter the string:- "<<endl;
	getline(cin,str);
	char i=0;
	while(str[i]!='\0'){
		st.push(str[i]);
		i++;
	}
	i=0;
	while(str[i]!='\0'){
		str[i]=st.top();
		st.pop();
		i++;
	}
	cout<<str<<endl;
}