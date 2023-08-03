/*
Qn:- Write a Program to print patten, if n=3
A A A
B B B
C C C 
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
		while(j<=n){
			cout<<" "<<char(ch+i-1)<<" ";
			j++;
		}
		//ch++;
		cout<<endl;
		i++;
	}
	return 0;
}
