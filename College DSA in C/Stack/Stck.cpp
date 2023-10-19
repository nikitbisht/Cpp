//Implement of Stack 
#include<iostream>
#define Max_Size 10
using namespace std;
//input Element (push)
void push(int *arr,int*top){
	if(*top==Max_Size-1){
		cout<<"Stack Overflow"<<endl;
		return;
	}
	else{
		int data;
		cin>>data;
		(*top)++;
		arr[*top]=data;
	}
}
void pop(int *arr,int*top){
	if(*top==-1){
		cout<<"Stack Underflow"<<endl;
		return ;
	}
	else
		(*top)--;
}

void display(int *arr,int top){
	for(int i=top;i>=0;i--)
		cout<<arr[i]<<" ";
}
int main(){
	int n,m;
	int top=-1;
	cout<<"Enter the Size of Stack: -"<<endl;
	cin>>n;
	int arr[Max_Size];
	for(int i=1;i<=n;i++)
		push(arr,&top);
	cout<<"Enter the Element you wanna delete"<<endl;
	cin>>m;
	for(int i=0;i<m;i++)
		pop(arr,&top);
	display(arr,top);
	return 0;
}