/*
Qn:- Write a Program to print patten, if n=3
A B C
D E F
G H I
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
			cout<<" "<<ch<<" ";
			ch++;
			j++;
		}
		cout<<endl;
		i++;
	}
	return 0;
}
