class Solution {
private:
    //Recusion Approch
    int solve(vector<int>&cost,int n){
        //base case
        if(n<=1) return cost[n];

        return min(solve(cost,n-1),solve(cost,n-2))+cost[n];
    }


    //Recursion + Memorization (Top-down  Dp Approch)
    int solve1(vector<int>&cost,int n,vector<int>&dp){
        //base case
        if(n<=1) return cost[n];

        if(dp[n] != -1) return dp[n];
        return dp[n] = min(solve1(cost,n-1,dp),solve1(cost,n-2,dp))+cost[n];
    }


    //Tabulation (Bottom-Up dp Approch)
    int solve2(vector<int>&cost,int n){
        //Step1:- Create Dp
        vector<int>dp(n+1,-1);
        //Step2:- Anaylis Base case
        dp[0] = cost[0];
        dp[1] = cost[1];
        //Step3:- Anaylis loop range
        for(int i=2; i<n; i++){
            dp[i] = min(dp[i-1],dp[i-2])+cost[i];
        }
        return min(dp[n-1],dp[n-2]);
    }


    //Space Optimization
    int solve3(vector<int>&cost,int n){
        int pre1 = cost[1];
        int pre2 = cost[0];
        int curr = 0;
        for(int i=2; i<n; i++){
            curr = min(pre1,pre2)+cost[i];
            pre2 = pre1;
            pre1= curr;
        }
        return min(pre1,pre2);
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

    //Recursion
        // return min(solve(cost,n-1),solve(cost,n-2));


    //Recursion + Memorization (Top-down  Dp Approch)
        // vector<int>dp(n+1,-1);
        //return min(solve1(cost,n-1,dp),solve1(cost,n-2,dp));


    //Tabulation (Bottom-Up dp Approch)
        // return solve2(cost,n);


    //Space Optimization
        return solve3(cost,n);
    }
};
