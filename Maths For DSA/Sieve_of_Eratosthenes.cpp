//Sieve of Eratosthenes
/*
We know that prime no are allways comes in only his table

1. Make every no as a Prime
2. Loop i=2 --> <n (i ke table mai joo no aate hai uko non-prime krrdoo)

*/
//	TC:- O(n*log(log n))
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cout<<"Enter the  no:- "<<endl;
	cin>>n;
	vector<bool>prime(n+1,true);
	prime[0]=prime[1]=false;
	int cnt=0;
	for(int i=2;i<n;i++){
		if(prime[i]){
			cnt++;
			for(int j=2*i;j<n;j+=i){
				prime[j]=0;
			}	
		}
	}
	cout<<cnt<<endl;
}