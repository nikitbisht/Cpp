class Solution {
private:
//Recursion
    int solveRec(vector<int>&nums,int base, int n){
        if(n==base) return nums[n];
        if(n < base) return 0;
        
        int inclu = solveRec(nums,base,n-2) + nums[n];
        int exclu = solveRec(nums,base,n-1) + 0;

        return max(inclu,exclu);
    }

//Top down Dp
    int solveDp(vector<int>&nums,int base,int n,vector<int>&dp){
        if(n==base) return nums[n];
        if(n < base) return 0;

        if(dp[n] != -1) return dp[n];

        
        int inclu = solveDp(nums,base,n-2,dp) + nums[n];
        int exclu = solveDp(nums,base,n-1,dp) + 0;

        return dp[n] = max(inclu,exclu)        ;
    }
//Bottom up dp
    int solveTabu(vector<int>&nums,int base,int n){
        vector<int>dp(n+1,0);
        dp[base] = nums[base];
        for(int i=base+1; i<=n; i++){
            int inclu = 0;
            if(i-2>= 0){
                inclu = dp[i-2] + nums[i];
            }
            int exclu = dp[i-1] + 0;

            dp[i] = max(inclu,exclu);
        }
        return dp[n];
    }

//Space Optimization
int solveOpti(vector<int>&nums,int base,int n){
    int pre1 = nums[base];
    int pre2 = 0;
    int curr = 0;
    for(int i=base+1; i<=n; i++){
        int inclu = pre2+nums[i];
        int exclu = pre1 + 0;

        curr = max(inclu,exclu);
        pre2 = pre1;
        pre1 = curr;
    }
    return max(pre1,pre2);
}
public:
    int rob(vector<int>& nums) {
        int n =nums.size();
        if(n == 1) return nums[0];

//Recursion
        // return max(solveRec(nums,0,n-2),solveRec(nums,1,n-1));

//Recursion + memorization
        //vector<int>dp(n,-1);
        // return max(solveDp(nums,0,n-2,dp),solveDp(nums,1,n-1,dp));
        
//Tabulation
        //return max(solveTabu(nums,0,n-2),solveTabu(nums,1,n-1));

//Space Optimization
        return max(solveOpti(nums,0,n-2),solveOpti(nums,1,n-1));
    }
};
