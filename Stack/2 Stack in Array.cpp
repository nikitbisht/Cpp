// 2Stack in Array
#include<iostream>
using namespace std;
class stack{
	public:
		int *arr;
		int top1;
		int top2;
		int size;
	stack(int size){
		this->size=size;
		this->top1=-1;
		this->top2=size;
		this->arr=new int[size];
	}
	//Push function for stack 1
	void push1(int data){
		if(top2-top1>1){
			arr[++top1]=data;
		}
		else{
			cout<<"Stack Overflow"<<endl;
		}
	}
	//Push function for stack 2
	void push2(int data){
		if(top2-top1>1){
			arr[--top2]=data;
		}
		else{
			cout<<"Stack Overflow"<<endl;
		}
	}
	//Pop function for stack 1
	int pop1(){
		if(top1>=0){
			return arr[top1--];
		}
		else{
			return -1;
		}
	}
	//Pop function for stack 1
	int pop2(){
		if(top2<size){
			return arr[top2++];
		}
		else{
			return -1;
		}
	}
	
	//dispaly fn for stack 1
	void display1(){
		for(int i=top1;i>=0;i--){
			cout<<arr[i]<<" ";
		}
	}
	//dispaly fn for stack 2
	void display2(){
		for(int i=top2;i<=size;i++){
			cout<<arr[i]<<" ";
		}
	}
};
