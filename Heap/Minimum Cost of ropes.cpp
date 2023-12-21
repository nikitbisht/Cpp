//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends
class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
       priority_queue<long long ,vector<long long >, greater<long long >>pq;
       for(int i=0;i<n;i++){
           pq.push(arr[i]);
       }
       long long cost = 0;
       long long sum = 0;
       while(pq.size() > 1){
           long long val1 = pq.top();
           pq.pop();
           long long val2 = pq.top();
           pq.pop();
           sum = val1 + val2;
           pq.push(sum);
           cost+=sum;
       }
       return cost;
    }
};
