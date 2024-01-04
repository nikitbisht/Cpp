class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int>M;
        int ans = 0;
        //Store the Frequency 
        for(auto i : nums)
            M[i]++;
        //Process...
        for(auto i : M){
            if(i.second == 1) return -1;

            int rem = i.second % 3;
            ans += i.second / 3;
            
            if(rem) ans += 1;
        }

        return ans;
    }
};
