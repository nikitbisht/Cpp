//INsert an Element at bottom of Stack
#include<iostream>
#include<stack>
using namespace std;

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
	int num;
	cout<<"Enter the bottom insert element:- "<<endl;
	cin>>num;
	insertBottom(st,num);
	displayStack(st);	
	return 0;
}