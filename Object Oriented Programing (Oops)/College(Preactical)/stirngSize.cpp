#include<iostream>
#include<string>
using namespace std;
int main(){
	string s1="Myworld";
	string s2="myworld";
	int ans= s1.compare(s2);
	if(ans==0){
		cout<<"Sting are equal"<<endl;
	}
	else if(ans<0){
		cout<<"S1 is greater than s2"<<endl;
	}
	else if(ans>0){
		cout<<"S1 is smaller than s2"<<endl;
	}
	return 0;
}