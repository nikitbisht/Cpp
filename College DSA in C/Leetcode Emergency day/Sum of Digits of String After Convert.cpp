class Solution {
public:
    int getLucky(string s, int k) {
        int ans = 0;
        //Find the total no
        for(auto ch : s){
            int value = ch - 'a' +1;
            while(value){
                ans += value % 10;
                value /= 10;
            }
        }
        k--;

        // process it k times
        while(k){
            int n = ans;
            ans = 0;
            while(n){
                ans += n%10;
                n = n/10;
            }
            k--;
        }
        return ans;
    }
};
