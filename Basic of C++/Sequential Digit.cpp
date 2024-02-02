class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string s = "123456789";
        vector<int>ans;
        for(int i =0;i<9;i++){
            int num = 0;
            for(int j = i;j<9;j++){
                num = num *10 + s[j]-'0';
                if(num<=high && num>=low)
                    ans.push_back(num);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
