/*
Qn:- Write a Program to print patten, if n=4
D
C D
B C D
A B C D
?
*/

#include<iostream>
using namespace std;
int main(){
	int n,i=1,j=1;
	cin>>n;
	char ch='A';
	while(i<=n){
		j=1;
		while(j<=i){
			cout<<" "<<char(ch+n-i+j-1)<<" ";
			j++;
		}
		cout<<endl;
		i++;
	}
	return 0;
}
