/*
Qn:- Write a Program to print patten, if n=4
1 
2 3
3 4 5
4 5 6 7 
?
*/

#include<iostream>
using namespace std;
int main(){
	int n,i=1,j=1;
	cin>>n;
	while(i<=n){
		j=1;
		while(j<=i){
			cout<<" "<<i+j-1<<" ";
			j++;
		}
		cout<<endl;
		i++;
	}
	return 0;
}
