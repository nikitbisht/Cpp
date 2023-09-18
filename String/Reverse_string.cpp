//Reverse String
#include<iostream>
using namespace std;
int getlength(char name[]) {
	int i=0;
	while(name[i]!='\0') {
		i++;
	}
	return i;
}
int reverse(char name[]) {
	int i=0;
	int j=getlength(name)-1;
	while(i<=j) {
		swap(name[i++],name[j--]);
	}
	return 0;
}
int main() {
	char name[20];
	cin>>name;
	reverse(name);
	cout<<name<<endl;
	return 0;
}