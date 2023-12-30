class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int n = words.size();
       if(n==1) return true;
       int arr[26]={0};
        for(auto s: words){
            for( auto c: s){
                arr[c - 'a']++;
            }
        }

        for(int i = 0; i < 26; i++){
            if(arr[i] % n != 0){
                return false;
            }
        }
        
        return true;
    }
};
