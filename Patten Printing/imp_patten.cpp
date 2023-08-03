/*
Qn:- Write a Program to print patten, if n=4
      1       
    1 2 1      
  1 2 3 2 1    
1 2 3 4 3 2 1  

*/
#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int i=1,j=1;
	while(i<=n){
		j=1;
		while(j<=n-i){
			cout<<" ";
			j++;
		}
		j=1;
		while(j<=i){
			cout<<j;
			j++;
		}
		j=i-1;
		while(j>=1){
			cout<<j;
			j--;
		}
		cout<<endl;
		i++;
	}
}
