//Check Palindrome
#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
// Two Pointer approch
bool is_palindrome(char name[]) {
	int i=0;
	int j=strlen(name)-1;
	while(i<=j) {
		if(name[i]!=name[j])
			return 0;
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