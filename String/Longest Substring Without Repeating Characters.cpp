class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //          a,b,c       ture,index
        unordered_map<char,int>M;
        int ans=0;
        int cnt = 0;
        for(int  i = 0; i < s.size(); i++){
            char ch = s[i];
            if(M.find(ch) == M.end()){ //means ch is not present in map
                M[ch] = i;
                cnt++;
            }else{
                i = M[ch];
                M.clear();
                cnt=0;
            }
            ans  = max(cnt,ans);
        }
        return ans;
    }
};
