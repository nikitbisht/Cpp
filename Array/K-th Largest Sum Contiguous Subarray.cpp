//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int kthLargest(vector<int> &Arr,int N,int K){
        //create min heap
        priority_queue<int,vector<int>,greater<int>>pq;
        
        for(int i = 0; i < N; i++){
            int sum = 0;
            for(int j = i; j < N; j++){
                sum += Arr[j];
                
                if(pq.size() < K){
                    pq.push(sum);
                }else{
                    if(pq.top() < sum){
                        pq.pop();
                        pq.push(sum);
                    }
                }
            }
        }
        return pq.top();
    }
};
