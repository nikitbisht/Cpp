class Solution {
public:
    string minWindow(string s, string t) {
        int sSize = s.size();
        int tSize = t.size();
        if(sSize < tSize) return "";
        unordered_map<char,int>freq;

        for(auto ch : t){
            freq[ch]++;
        }
        int count = freq.size();      
        int i=0,j=0;
        int index = 0;
        int maxi = INT_MAX;
        while(j<sSize){
            if(freq.find(s[j]) != freq.end()){
                freq[s[j]]--;
                if(freq[s[j]] == 0){
                    count--;
                }
            }

            if(count == 0){
                while(count==0){
                    if(maxi > j-i+1){
                        maxi = j-i+1;
                        index = i;
                    }
                    if(freq.find(s[i]) != freq.end()){
                        freq[s[i]]++;
                        if(freq[s[i]] > 0){
                            count++;
                        }
                    }
                    i++;
                }
            }
            j++;
        }
        if(maxi == INT_MAX) return "";

        return s.substr(index,maxi);
    }
};
