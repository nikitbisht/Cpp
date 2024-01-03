class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans = 0;
        int pre_count = 0;
        for(int i = 0; i < bank.size(); i++){
            int curr_count = 0;
            for(auto ch : bank[i]){
                if(ch == '1') curr_count++;
            }
            ans += curr_count * pre_count;
            if(curr_count) pre_count = curr_count;
        }
        return ans;
    }
};
