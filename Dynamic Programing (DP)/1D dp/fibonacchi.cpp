//Fibonacchi using Top Down Approch (DP) Recursion + memorization
#include<iostream>
using namespace std;
int fibo (int* dp,int n){
	if(n<=1) return n;
	if(dp[n])
		return dp[n];
	return dp[n] = fibo(dp,n-1)+fibo(dp,n-2);
}
int main(){
	int n;
	cout<<"Enter the no:- "<<endl;
	cin>>n;
	int dp[n+1] = {0};
	cout<<fibo(dp,n)<<endl;
	return 0;
}

//Bottom approch
int main(){
	int n;
	cout<<"Enter the no:- "<<endl;
	cin>>n;
	int dp[n+1];
	dp[0]=0;
	dp[1]=1;
	for(int i=2; i<=n; i++){
		dp[i] = dp[i-1]+dp[i-2];
	}
	cout<<dp[n]<<endl;
}

//Space Optimization
int main(){
	int n;
	cout<<"Enter the no:- "<<endl;
	cin>>n;
	if(n==0){
		cout<<0<<endl;
		return 0;
	}
	int pre1 = 1;
	int pre2 = 0;
	int curr = 1;
	for(int i=2; i<=n; i++){
		curr = pre1+pre2;
		pre2 = pre1;
		pre1 = curr;
	}
	cout<<pre1<<endl;	
}
