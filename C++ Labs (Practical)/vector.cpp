#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	vector<int> v;
	int a;
	cout<<"Enter the data:- "<<endl;
	for(int i = 0 ;i< 5;i++){
		cin>>a;
		v.push_back(a);
	}
	v.resize(v.size()-1);
	v.erase(remove(v.begin(),v.end(),5),v.end());
	reverse(v.begin(),v.end());
	cout<<"element are"<<endl;
	for(auto i : v){
		cout<<i<<" ";
	}
	return 0;
}