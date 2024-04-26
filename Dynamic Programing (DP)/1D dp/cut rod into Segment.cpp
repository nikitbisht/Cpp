class Solution{
private:
    int solve(int n,int x,int y,int z){
        //base case
        if(n == 0) return 0;
        if(n < 0) return INT_MIN;
        
        int a = solve(n-x,x,y,z);
        int b = solve(n-y,x,y,z);
        int c = solve(n-z,x,y,z);
        
        
        int ans = max(a,max(b,c))+1;
        return ans;
        
    }
    
    //Memorization
    int solveMemo(int n,int x,int y,int z , vector<int>&dp){
        //base case
        if(n == 0) return 0;
        if(n < 0) return INT_MIN;
        if(dp[n] != -1){
            return dp[n];
        }
        
        int a = solveMemo(n-x,x,y,z,dp);
        int b = solveMemo(n-y,x,y,z,dp);
        int c = solveMemo(n-z,x,y,z,dp);
        
        
        dp[n] = max(a,max(b,c))+1;
        return dp[n];
    }
    
    //Tabulor
    int solveTabu(int n,int x,int y,int z){
        //Analysis base case
        vector<int>dp(n+1,INT_MIN);
        dp[0] = 0;
        //find range
        for(int i=1; i<=n; i++){
            //analysi recurence relation
            if(i-x >= 0){
                dp[i] = max(dp[i],dp[i-x] + 1);
            }
            
            if(i-y >= 0){
                dp[i] = max(dp[i],dp[i-y]+1);
            }
            
            if(i-z >= 0){
                dp[i] = max(dp[i],dp[i-z]+1);
            }
        }
        
        if(dp[n]<0) return 0;
        return dp[n];
    }
public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Recursive
        // int ans = solve(n,x,y,z);
        
        
        //Memorization
        // vector<int>dp(n+1,-1);
        // int ans = solveMemo(n,x,y,z,dp);
        
        //Tabular
        return solveTabu(n,x,y,z);
    }
};
