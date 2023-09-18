/*
Permutution in String
s2=[e,i,b,a,c,v]
s1=[a,b]		permutution of ab=ab,ba		and ba is present in stirng
true
*/
#include<iostream>
#include<string>
using namespace std;
bool isCheck(int a[26],int b[26]) {
	for(int i=0; i<26; i++) {
		if(a[i]!=b[i])
			return 0;
	}
	return 1;
}
bool isPermutation(string s1,string s2) {
	int count1[26]= {0},count2[26]= {0};
	//character count array
	for(int i=0; i<s1.length();i++) {
		int number=s1[i]-'a';
		count1[number]++;
	}
	//traverse s2 in window of s1 length and compare
	int i=0;
	while(i<s2.length()&&i<s1.length()) {
		int number=s2[i++]-'a';
		count2[number]++;
	}
	if(isCheck(count1,count2))
		return 1;
	//aage ke window process
	while(i<s2.length()) {
		//Add new character
		int newchar=s2[i]-'a';
		count2[newchar]++;
		//Remove old character
		int index=s2[i-s1.length()];
		int oldchar=index-'a';
		count2[oldchar]--;
		i++;
		if(isCheck(count1,count2))
			return 1;
	}
	return 0;
}
int main() {
	string s2,s1;
	cout<<"enter the string :- "<<endl;
	getline(cin,s2);
	cout<<"enter premutation:- "<<endl;
	getline(cin,s1);
	if(isPermutation(s1,s2))
		cout<<"Present";
	else
		cout<<"Not-Present";
	return 0;
}