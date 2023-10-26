// Next and previous Smaller element
#include<iostream>
#include<stack>
#include<vector>
using namespace std;
//PREVIOUS SMALLER ELEMENT
vector<int> prevSmallerElement(vector<int>&arr){
	int n=arr.size();
	stack<int>st;
	vector<int>ans(n);
	st.push(-1);
	for(int i=0;i<n;i++){
		int curr=arr[i];
		while(st.top()>=curr){
			st.pop();
		}
		ans[i]=st.top();
		st.push(curr);
	}
	return ans;
}
//NEXT SMALLER ELEMENT
vector<int> nextSmallerElement(vector<int>&arr){
	int n=arr.size();
	vector<int>ans(n);
	stack<int>st;
	st.push(-1);
	for(int i=n-1;i>=0;i--){
		int curr=arr[i];
		while(st.top()>=curr){
			st.pop();
		}
		ans[i]=st.top();
		st.push(curr);
	}
	return ans;
}
//Display
void display(vector<int>&arr){
	int n=arr.size();
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
int main(){
	int n,a;
	cout<<"Enter the size of array:- "<<endl;
	cin>>n;
	vector<int>arr;
	for(int i=0;i<n;i++){
		cin>>a;
		arr.push_back(a);
	}
	vector<int>prev=prevSmallerElement(arr);
	vector<int>next=nextSmallerElement(arr);
	cout<<"Previous Smaller Element"<<endl;
	display(prev);
	cout<<"Next Smaller Element"<<endl;
	display(next);
}