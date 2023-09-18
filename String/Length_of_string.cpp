//Length of Stirng ?
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int getlength(char name[]) {
	int i=0;
	while(name[i]!='\0') {
		i++;
	}
	return i;
}
int main() {
	char name[20];
	cin>>name;
	cout<<getlength(name)<<endl;
}
