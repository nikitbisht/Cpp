class Solution {
private:
//Solve using Recursion
    int solve(vector<int>&nums,int target){
        //base case
        if(target == 0) return 1;
        if(target < 0) return 0;

        int ans = 0;
        for(int i=0; i<nums.size(); i++){
            ans += solve(nums,target-nums[i]);
        }
        return ans;
    }

//Memorization
    int solveMemo(vector<int>&nums,int target,vector<int>&dp){
        //base case
        if(target == 0) return 1;
        if(target < 0) return 0;
        if(dp[target]!=-1) return dp[target];
        int ans = 0;
        for(int i=0; i<nums.size(); i++){
            ans += solveMemo(nums,target-nums[i],dp);
        }
        dp[target] = ans;
        return ans;
    }
//Tabulation
    int solveTabu(vector<int>&nums,int target){
        vector<double>dp(target+1,0);
        dp[0] = 1;
        for(int i=1; i<=target; i++){
            for(int j=0; j<nums.size(); j++){
                if(i-nums[j] >= 0){
                    dp[i] += dp[i-nums[j]];
                    // cout<<i<<":- "<<dp[i]<<endl;
                }
            }
        }
        return (int)dp[target];
    }

public:
    int combinationSum4(vector<int>& nums, int target) {
        // return solve(nums,target);
       
        //top - down dp
        // vector<int>dp(target+1,-1);
        // return solveMemo(nums,target,dp);

        //bottom-up dp
        return solveTabu(nums,target);
    }
};
