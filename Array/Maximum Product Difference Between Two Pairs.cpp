class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int n = nums.size();
        int maxi1 = INT_MIN, maxi2 = INT_MIN;
        int mini1 = INT_MAX, mini2 = INT_MAX;
        for(int i = 0;i < n;i++){
            //Find maximun
            if(maxi1 <= nums[i] || maxi2 <= nums[i]){
                maxi2 = max(maxi1,maxi2);
                maxi1 = nums[i];
            }
            //Find mininum
            if(mini1 >= nums[i] || mini2 >= nums[i]){
                mini2 = min(mini2,mini1);
                mini1 = nums[i];
            }
        }
        int ans = (maxi1*maxi2 - mini1*mini2);
        return ans;
    }
};
