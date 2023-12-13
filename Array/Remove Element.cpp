class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.empty()) return 0;
        int i=0,j=nums.size()-1;
        int k=0;
        while(i<=j){
        if(nums[i]==val){
            swap(nums[i],nums[j]);
            j--;
        }
        else{
            k++;
            i++;
        }
    }
        return k;
    }
};
