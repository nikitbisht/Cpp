class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int maxi = INT_MIN;
        int indx = -1;
        for(int i=0;i<nums.size();i++){
            if(maxi < nums[i]){
                maxi = nums[i];
                indx = i;
            }
        }
        int sum = 0;
        for(int i = 0;i < k;i++){
            sum +=nums[indx];
            nums[indx] += 1;
        }
        return sum;
    }
};
