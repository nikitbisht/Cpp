#include<iostream>
//#include<string>
using namespace std;
char getMaxiOccurence(string s) {
	int arr[26]= {0};
	int number=0;
	for(int i=0; i<s.length(); i++) {
		if(s[i]>='a'&&s[i]<='z')
			number= s[i]-'a';
		else
			number=s[i]-'A';
		arr[number]++;
	}
	int maxi=0,ans=0;
	for(int i=0; i<26; i++) {
		if(maxi<arr[i]) {
			ans=i;
			maxi=arr[i];
		}
	}	
	int ch='a'+ans;
	return ch;
}
int main() {
	string s;
	cin>>s;
	cout<<getMaxiOccurence(s)<<endl;
}