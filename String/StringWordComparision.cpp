/*
Sting comprassion
i/p=[a,a,b,b,b,c,c,c]
o/p=[a,2,b,3,c,3]

*/
#include<iostream>
#include<string>
using namespace std;
int stringComprassion(string s){
	int i=0;
	int ansIndex=0;
	while(i<s.length()){
		int j=i+1;
		while(j<s.length()&&s[i]==s[j]){
			j++;
		}
		s[ansIndex++]=s[i];
		int count=j-i;
		if(count>1){
			string cnt=to_string(count);
			for(char ch: cnt){
				s[ansIndex++]=ch;
			}
		}
		i=j;
	}
	return ansIndex;
}
int main() {
	string s;
	cout<<"enter the string :- "<<endl;
	getline(cin,s);
	cout<<stringComprassion(s)<<endl;
	return 0;
}
