#include<iostream>
using namespace std;
int main(){
	int n,cnt = 0;
	cout<<"Enter the  no:- "<<endl;
	cin>>n;
	bool prime[n+1];
	prime[0] = prime[1] = false;
	for(int i=2; i<n; i++){
		prime[i] = true;
	}
	for(int i=2; i<n; i++){
		if(prime[i]){
			cnt ++;
			for(int j=2*i; j<n; j+=i){
				prime[j] = false;
			}
		}
	}
	cout<<cnt<<endl;
	return 0;
}