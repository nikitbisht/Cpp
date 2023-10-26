//Qn:- Delete middle element of stack
#include<iostream>
#include<stack>
using namespace std;
void deleteMiddleStack(stack<int>&st,int count,int size){
	//base case 
	if(count==size/2){
		st.pop();
		return ;
	}
	int num=st.top();
	st.pop();
	deleteMiddleStack(st,count+1,size);
	st.push(num);
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
	int count=0;
	deleteMiddleStack(st,count,st.size());
	displayStack(st);	
	return 0;
}