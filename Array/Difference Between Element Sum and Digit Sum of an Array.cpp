class Solution {
private:
	int getDigit(int n){
		int rem = 0;
		while(n){
			rem += n % 10;
			n = n / 10;		
		}
	    return rem;
    }

public:
    int differenceOfSum(vector<int>& nums) {
        int S_element = 0;
        int S_digit = 0;
        int n = nums.size();
        for(int i = 0 ;i < n;i++){
            S_element += nums[i];
            if(nums[i] >= 1 && nums[i] <= 9){
                S_digit += nums[i];
            } else{
                S_digit += getDigit(nums[i]);
            }
        }
        return abs(S_element - S_digit);
    }
};
