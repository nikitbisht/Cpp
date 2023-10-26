/*
Qn:- Minimum Cost to make a String valid
ex:- {}{},{{}} valid
	{}}, }{, {}{ invalid
	{{{}
	if 2nd bracket is reverse then it make valid no of cost = 1
Conditions:-
	no of opening bracket = no of closing bracket
	every close bracket should hace open bracket before it
Logic:-
	1. if strig length is odd means invalid return -1;
	2. remove valid part
	3. remaing part below 3 types
		{{{,	}}},	}}}{{{
	4. count opening and closing bracket
	5. solve these patten and try to make a formula
	ans=((a+1)/2)+((b+1)/2)
	
*/
//Valid Parenthesis
/*
Qn:- Reverse a string using Stack
*/
#include<iostream>
#include<stack>
#include<string>
using namespace std;
int minCost(stack<int>&st,string str){
	if(str.size()&1){
		return -1;
	}
	int i=0;
	while(str[i]!='\0'){
		if(str[i] =='{'){
			st.push(str[i]);
		}
		else if(str[i]=='}'){ 
			if(!st.empty()&&st.top()=='{'){
				st.pop();
			}else{
				st.push(str[i]);
			}
		}
		i++;
	}
	int a=0,b=0;
	while(!st.empty()){
		if(st.top()=='{'){
			a++;
		}
		else if(st.top()=='}'){
			b++;
		}
		st.pop();
	}
	int ans1=(a+1)/2;
	int ans2=(b+1)/2;
	return ans1+ans2;
}
int  main(){
	stack<int>st;
	string str;
	cout<<"Enter the string:- "<<endl;
	getline(cin,str);
	cout<<"MINIMUN NO OF COST:- "<<minCost(st,str)<<endl;
	return 0;
}

