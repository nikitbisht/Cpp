//Stack Basics
#include<iostream>
using namespace std;
class stack{
	public:
		int top;
		int *arr;
		int size;
	stack(int size){
		this->size =size;
		this->arr=new int[size];
		this->top=-1;
	}
	//Push function
	void push(int data){
		if(size-top>1){
			arr[++top]=data;
		}else{
			cout<<"Stack Overflow"<<endl;
		}
	}
	//Pop function
	void pop(){
		if(top>=0){
			top--;
		}else{
			cout<<"Stack Underflow"<<endl;
		}
	}
	//Peek function
	inline int peek(){
		return arr[top];
	}
	//Empty function
	inline bool empty(){
		return top==-1;
	}
	//Display fn of stack
	void display(){
		cout<<"Stack element are:- "<<endl;
		for(int i=top;i>=0;i--){
			cout<<arr[i]<<" ";
		}
		cout<<endl;
	}
};
int main(){
	int n,m,a;
	cout<<"enter the size of stack:- "<<endl;
	cin>>n;
	stack st(n);
	cout<<"Enter Stack element:- "<<endl;
	for(int i=0;i<n;i++){
		cin>>a;
		st.push(a);
	}
	st.display();
	cout<<"Enter the element you want to delete:- "<<endl;
	cin>>m;
	for(int i=0;i<m;i++){
		st.pop();
	}
	cout<<"Stack peek:- "<<st.peek()<<endl;
	st.display();
	return 0;
}