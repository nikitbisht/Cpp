//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    private:
    int solve(int*wt,int *val,int index,int capacity){
        //base case
        if(index == 0){
            if(capacity >= wt[0]) return val[0];
            else return 0;
        }
        
        int include = 0;
        //incluse
        if(capacity >= wt[index]){
            include = val[index] + solve(wt,val,index-1,capacity-wt[index]);
        }
        //exclude
        int exclude = 0 + solve(wt,val,index-1,capacity);
        
        int ans = max(include,exclude);
        
        return ans;
    }
    
    
    int solveMemo(int*wt,int *val,int index,int capacity,vector<vector<int>>&dp){
        //base case
        if(index == 0){
            if(capacity >= wt[0]) return val[0];
            else return 0;
        }
        
        if(dp[index][capacity] != -1){
            return dp[index][capacity];
        }
        
        int include = 0;
        //incluse
        if(capacity >= wt[index]){
            include = val[index] + solveMemo(wt,val,index-1,capacity-wt[index],dp);
        }
        //exclude
        int exclude = 0 + solveMemo(wt,val,index-1,capacity,dp);
        
        dp[index][capacity] = max(include,exclude);
        
        return dp[index][capacity];
    }
    
    int solveTabu(int*wt,int *val,int index,int capacity){
        vector<vector<int>>dp(index,vector<int>(capacity+1,0));
        //analysis base case
        for(int w = wt[0]; w<=capacity; w++){
            if(wt[0] <= capacity) dp[0][w]= val[0];
            else  dp[0][w] = 0;
        }
        
        //traverst the reamning
        for(int i=1; i<index; i++){
            for(int w=0; w<=capacity; w++){
                //include
                int include = 0;
                if(wt[i] <= w){
                    include = val[i] + dp[i-1][w-wt[i]];
                }
                int exclude = 0 + dp[i-1][w];
                
                dp[i][w] = max(include,exclude);
            }
        }
        
        return dp[index-1][capacity];
    }
    
    
    int solveSpace(int*wt,int *val,int index,int capacity){
        //you can do with 2 array pre and curr, now i use only 1
        vector<int>dp(capacity+1,0);
        //analysis base case
        for(int w = wt[0]; w<=capacity; w++){
            if(wt[0] <= capacity) dp[w]= val[0];
            else  dp[w] = 0;
        }
        
        //traverse reaming into right to left
        for(int i=1; i<index; i++){
            for(int w=capacity; w>=0; w--){
                int include = 0;
                //include
                if(wt[i] <= w){
                    include = val[i] + dp[w-wt[i]];
                }
                //exlcude
                int exclude = dp[w];
                
                dp[w] = max(include,exclude);
            }
        }
        return dp[capacity];
    }
    
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) { 
    
        //   return solve(wt,val,n-1,W);
        //Memorization
        // vector<vector<int>>dp(n,vector<int>(W+1,-1));   
        // return solveMemo(wt,val,n-1,W,dp);
        
        //Tabulation
        // return solveTabu(wt,val,n,W);
        
        //Space opti
        return solveSpace(wt,val,n,W);
      
      
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends
