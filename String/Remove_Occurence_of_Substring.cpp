/*
Remove all Occurence of Substring
[d,a,a,b,c,b,a,a,b,c,b,c]
[d,a,b,a,a,b,c,b,c]
[d,a,b,a,b,c]
[d,a,b]
*/
#include<iostream>
#include<string>
using namespace std;
void removeOccurence(string s1,string s2){
	while(s1.length()!=0&&s1.find(s2)<s1.length()){
		s1.erase(s1.find(s2),s2.length());
	}
	cout<<s1<<endl;
}
int main(){
	string s1,s2;
	cout<<"Enter the string:- "<<endl;
	getline(cin,s1);
	cout<<"Enter the substring:- "<<endl;
	getline(cin,s2);
	cout<<"Ans:- "<<endl;
	removeOccurence(s1,s2);
	return 0;
}