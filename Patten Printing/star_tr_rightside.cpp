/*
Qn:- Write a Program to print patten, if n=4
* * * *
  * * *
    * *
      *
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
		while(j<=i-1){
			cout<<" ";
			j++;
		}
		while(j<=n){
			cout<<"*";	
			j++;
		}
		cout<<endl;
		i++;
	}
	return 0;
}
