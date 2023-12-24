class Solution {
public:
    int minOperations(string s) {
        int n = s.size(), cnt = 0;

        for (int i = 0; i < n; i+=2) {
            if (s[i] == '0') {
                cnt++;
            }
        }

        for (int i = 1; i < n; i+=2) {
            if (s[i] == '1') {
                cnt++;
            }
        }

        return min(cnt, n-cnt);
    }
};

//2nd Method
class Solution {
public:
    int minOperations(string s) {
        int count1 = 0;
        int count2 = 0;
        char toggle1 = '0';
        char toggle2 = '1';

        for(int i = 0 ;i < s.size(); i++){
            if(toggle1 != s[i])
                count1++;
            if(toggle2 != s[i])
                count2++;
            swap(toggle1,toggle2);
        }
        return min(count1,count2);
    }
};
