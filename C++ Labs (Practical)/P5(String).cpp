//P5
#include<iostream>
#include<string>
using namespace std;
// Add string and number whats Happen
void task01(){
	string str="ABC";
	int a=1;
	string str2=str+a;
	cout<<str2<<endl;
}
//Check Palindrone
void task02(){
	string str;
	cin>>str;
	bool flag=true;
	int start=0,end=str.length()-1;
	while(start<end){
		if(str[start]!=str[end]){
			flag=false;
		}
		start++;
		end--;
	}
	if(flag){
		cout<<"Yes, its a Palindrone"<<endl;
	}
	else{
		cout<<"No, its not a Palindrone"<<endl;
	}
}
//Compare String
void task03(){
	string str,str2;
	cin>>str;
	cin>>str2;
	if(str.compare(str2)){
		cout<<"String are Not Equal"<<endl;
	}
	else
		cout<<"String are Equal"<<endl;
}
// Check compare() fn return values
void task04(){
	string str="Hello";
	string str2="hello";
	string str3="Hell";
	string str4="Hello world";
	string str5="hello";
	string str6="Hello";
	
	int x=str.compare(str6);
	cout<<"x= "<<x<<endl;
	x=str.compare(str3);		//x=1 because of str length is greater
	cout<<"x= "<<x<<endl;
	x=str.compare(str4);		//x=-6 because of str length is smaller by 6 char of str4
	cout<<"x= "<<x<<endl;
	x=str.compare(str5);		//x= -32 due to ASCII value difference
	cout<<"x= "<<x<<endl;
	x=str2.compare(str6);		//x= +32 due to ASCII value
	cout<<"x= "<<x<<endl;	
}
//Mutable or not
void task05(){
	string a="hello";
	cout<<&a<<endl;
	a[0]='j';
	cout<<&a<<endl;
	cout<<a<<endl;
}
int main(){
	task01();
	task02();
	task03();
	task04();
	task05();
	return 0;
}
