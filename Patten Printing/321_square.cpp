/*
Qn:- Write a Program to print patten, if n=3
3 2 1
3 2 1
3 2 1
?
*/
#include<iostream>
using namespace std;
int main(){
	int n,i=1,j=1;
	cin>>n;
	while(i<=n){
		j=1;
		while(j<=n){
			cout<<" "<<n-j+1<<" ";
			j++;
		}
		cout<<endl;
		i++;
	}
	return 0;
}
