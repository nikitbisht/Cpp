class Solution {
public:
    int maxScore(string s) {
        int once = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '1')
                once++;
        }
        int zero = 0;
        int ans = 0;
        int sum = 0;
        for(int i = 0; i< s.size()-1; i++){
            if(s[i]=='0')
                zero++;
            if(s[i]=='1')
                once--;
            
            sum = zero + once;
            ans = max(ans,sum);
        }
        return ans;
    }
};
