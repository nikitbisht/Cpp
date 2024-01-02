class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int ans = 0;
        while(left < right){
            int mini = min(height[left],height[right]);
            int lenght = right - left;
            ans = max(ans,mini*lenght);

            if(height[left] < height[right]) left++;
            else right--;
            
        }
        return ans;
    }
};
