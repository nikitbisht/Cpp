//Stack using STL 
#include<iostream>
#include<stack>
using namespace std;
int main(){
	stack<int>st;
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	st.push(5);
	cout<<"Stack top:- "<<st.top()<<" ";
	st.pop();
	cout<<st.top()<<" ";
	st.pop();
	cout<<st.top()<<endl;
	if(st.empty()){
		cout<<"Stack is empty "<<endl;
	}else{
		cout<<"Stack is not empty "<<endl;
	}
	return 0;
}