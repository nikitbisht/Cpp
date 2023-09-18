//Punction Palindrone
#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
// Two Pointer approch
char toLower(char ch) {
	if(ch>='A'&&ch<='Z') {
		ch=ch+32;			//ch=ch-'A'+'a'
		return ch;
	}
	return ch;
}
bool isPun(char ch) {
	if(ch>='a'&&ch<='z'||ch>='A'&&ch<='Z'||ch>=48&&ch<=57)
		return 0;
	return 1;
}
bool is_palindrome(char name[]) {
	int i=0;
	int j=strlen(name)-1;
	while(i<=j) {
		if(isPun(name[i])) {
			i++;
		} else if(isPun(name[j])) {
			j--;
		} else if(toLower(name[i])!=toLower(name[j])) {
			return 0;
		} else
			i++;
		j--;
	}
	return 1;
}
int main() {
	char name[10],rev[10];
	cin>>name;
	cout<<is_palindrome(name)<<endl;
	return 0;
}