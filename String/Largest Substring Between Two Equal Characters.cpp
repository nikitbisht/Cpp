class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        //         a,b,c     frequency,last_index
        unordered_map<char , pair<int,int>>M;
        //Maping the frequency and last index
        for(int i = 0; i < s.size(); i++){
            char ch = s[i];
            M[ch].first++;
            M[ch].second = i;
        }
        //Finding the ans
        int ans = -1;
        for(int i = 0; i < s.size(); i++){
            char ch = s[i];
            if(M[ch].first >= 2){
                ans = max(ans, M[ch].second - i - 1);
            }
        }
        return ans;
    }
};

//Modified version

class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        unordered_map<char, int> firstIndex;
        int ans = -1;
        
        for (int i = 0; i < s.size(); i++) {
            if (firstIndex.find(s[i]) != firstIndex.end()) {
                ans = max(ans, i - firstIndex[s[i]] - 1);
            } else {
                firstIndex[s[i]] = i;
            }
        }

        return ans;
    }
};

