// Next and previous Gratest Element
#include<iostream>
#include<stack>
#include<vector>
using namespace std;
//Previous Gratest Element
vector<int> prevGretestElement(vector<int>& arr){
	int n=arr.size();
	vector<int>ans(n);
	stack<int>st;
	st.push(108);
	for(int i=0;i<n;i++){
		int curr=arr[i];
		while(st.top()<=curr){
			st.pop();
		}
		ans[i]=st.top();
		st.push(curr);
	}
	return ans;
}
//Next Gretest element
vector<int> nextGretestElement(vector<int>&arr){
	int n=arr.size();
	vector<int>ans(n);
	stack<int>st;
	st.push(108);
	for(int i=n-1;i>=0;i--){
		int curr=arr[i];
		while(st.top()<=curr){
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
	vector<int>prev=prevGretestElement(arr);
	vector<int>next=nextGretestElement(arr);
	cout<<"108 said that no gretest elment found:"<<endl;
	cout<<"Previous Gratest Element"<<endl;
	display(prev);
	cout<<"Next Gratest Element"<<endl;
	display(next);
	return 0;
}