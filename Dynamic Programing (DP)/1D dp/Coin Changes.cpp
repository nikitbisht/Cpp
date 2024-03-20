class Solution {
private:
    int solveRec(vector<int>&coins,int amount){
        //base case
        if(amount == 0) return 0;
        if(amount < 0) return INT_MAX;

        int n = coins.size();
        int mini = INT_MAX;
        for(int i=0; i<n; i++){
            int ans = solveRec(coins,amount-coins[i]);
            if(ans != INT_MAX){
                mini = min(ans+1,mini);
            }
        }
        return mini;
    }


    //Top-Down Dp
    int solveDp(vector<int>& coins,int amount,vector<int>&dp){
        //base case
        if(amount == 0) return 0;
        if(amount < 0) return INT_MAX;
        
        if(dp[amount] != -1) return dp[amount];

        int n = coins.size();
        int mini = INT_MAX;
        for(int i=0; i<n; i++){
            int ans = solveDp(coins,amount-coins[i],dp);
            if(ans != INT_MAX){
                mini = min(ans+1,mini);
            }
        }
        dp[amount] = mini;
        return mini;
    }


    //Bottom Up dp
    int solveTabu(vector<int>&coins,int amount){
        vector<int>dp(amount+1,INT_MAX);
        //Base case
        dp[0] = 0;
        
        int n = coins.size();
        for(int i=1; i<=amount; i++){
            for(int j=0; j<n; j++){
                if(i-coins[j] >= 0 && dp[i-coins[j]] != INT_MAX){
                    dp[i] = min(dp[i],dp[i-coins[j]]+1);
                }
            }
        }

        return dp[amount];
    }

public:
    int coinChange(vector<int>& coins, int amount) {
    //Recursion
        // int ans = solveRec(coins,amount);


    //Recursion + memorization
        // vector<int>dp(amount+1,-1);
        // int ans = solveDp(coins,amount,dp);


    // Tabulation
        int ans = solveTabu(coins,amount);

        if(ans == INT_MAX) return -1;
        return ans;
    }
};
