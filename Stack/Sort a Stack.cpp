//Sort a Stack
#include<iostream>
#include<stack>
using namespace std;

void insertPosition(stack<int>&st,int num){
	//base case 
	if(st.empty()||st.top()<num){
		st.push(num);
		return ;
	}
	int n=st.top();
	st.pop();
	insertPosition(st,num);
	st.push(n);
	return ;
}

//reverse Stack
void sortStack(stack<int>&st){
	//base case 
	if(st.empty()){
		return ;
	}
	int num=st.top();
	st.pop();
	sortStack(st);
	insertPosition(st,num);
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
	sortStack(st);
	cout<<"STack element after sort"<<endl;
	displayStack(st);	
	return 0;
}