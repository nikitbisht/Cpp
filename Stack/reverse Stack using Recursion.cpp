//Reverse STack Using recursion
#include<iostream>
#include<stack>
using namespace std;

//Insert at bottom
void insertBottom(stack<int>&st,int num){
	//base case 
	if(st.empty()){
		st.push(num);
		return ;
	}
	int n=st.top();
	st.pop();
	insertBottom(st,num);
	st.push(n);
	return ;
}

//reverse Stack
void reverseStack(stack<int>&st){
	//base case 
	if(st.empty()){
		return ;
	}
	int num=st.top();
	st.pop();
	reverseStack(st);
	insertBottom(st,num);
	return ;
}
//display stack
void displayStack(stack<int> st){
	while(st.size()>=1){
		cout<<st.top()<<" ";
		st.pop();
	}
	cout<<endl;
}

int  main(){
	int n,a;
	stack<int>st;
	cout<<"Size of stack:- "<<endl;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a;
		st.push(a);
	}
	cout<<"STack element are:- "<<endl;
	displayStack(st);
	reverseStack(st);
	cout<<"STack element after reverse"<<endl;
	displayStack(st);	
	return 0;
}