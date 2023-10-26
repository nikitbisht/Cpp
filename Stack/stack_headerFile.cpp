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
