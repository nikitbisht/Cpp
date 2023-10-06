#include<iostream>
using namespace std;
int main(){
	int a,b;
	cout<<"Enter the value of a and b: "<<endl;
	cin>>a>>b;
	if(a==b&&a==0&&b==0){
		cout<<"You win"<<endl;
	}
	else
		cout<<"Looser"<<endl;
	cout<<(a&b)<<endl;
	return 0;
}