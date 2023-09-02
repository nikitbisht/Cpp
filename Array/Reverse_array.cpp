//Reverse array afer m position
#include<iostream>
#include<vector>
using namespace std;
vector<int> reverse(vector<int>arr,int m){
	int s=m+1,e=arr.size()-1;
	while(s<=e){
		swap(arr[s],arr[e]);
		s++;
		e--;
	}
	return arr;
}


void print(vector<int>rev){
	cout<<endl;
	for(int i=0;i<rev.size();i++)
		cout<<rev[i]<<" ";
	cout<<endl;
}


int main(){
	int n,a;
	cin>>n;
	vector<int>arr;
	for(int i=0;i<n;i++){
		cin>>a;
		arr.push_back(a);
	}
	int m;
	cin>>m;
	vector<int>rev=reverse(arr,m);
	print(rev);
}
