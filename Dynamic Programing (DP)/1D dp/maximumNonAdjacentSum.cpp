#include <bits/stdc++.h> 
int solveRec(vector<int>&nums,int n){
    //base case
    if(n==0) return nums[n];
    if(n < 0) return 0;

    int inclu = solveRec(nums, n-2) + nums[n];
    int excl = solveRec(nums,n-1) + 0;

    return max(inclu,excl);
}

int solveMem(vector<int>& nums,int n,vector<int>&dp){
    //base case
    if(n==0) return nums[n];
    if(n < 0) return 0;

    if(dp[n] != -1) return dp[n];

    int inclu = solveMem(nums, n-2,dp) + nums[n];
    int excl = solveMem(nums,n-1,dp) + 0;

    return dp[n] = max(inclu,excl);
}


int solveTabu(vector<int>&nums){
    int n = nums.size();
    vector<int>dp(n,-1);
    dp[0] = nums[0];
    for(int i=1; i<n; i++){
        int inclu = dp[i-2] + nums[i];
        int exclu = dp[i-1] + 0;

        dp[i] = max(inclu,exclu);
    }
    return dp[n-1];
}


int solveSpaceOpti(vector<int>&nums){
    int n = nums.size();
    int pre1 = nums[0];
    int pre2 = 0;
    for(int i=1; i<n; i++){
        int inclu = pre2 + nums[i];
        int excl = pre1 + 0;

        int ans = max(inclu,excl);
        pre2 = pre1;
        pre1 = ans;
    }
    return max(pre1,pre2);
}

int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    //simple recursion
    // return solveRec(nums,n-1);

    // recursion + Memorization
    vector<int>dp(n,-1);
    // return solveMem(nums,n-1,dp);


    //Tabulation
    // return solveTabu(nums);


    return solveSpaceOpti(nums);
}
