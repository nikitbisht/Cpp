class Solution {
private:
    void solve(string word, string &beginWord, unordered_map<string,int>& mp, vector<vector<string>>& ans, vector<string>&temp){
        //base case
        if(word == beginWord){
            reverse(temp.begin(),temp.end());
            ans.push_back(temp);
            //backtrack
            reverse(temp.begin(),temp.end());
            return ;
        }

        int step = mp[word];
        for(int i=0; i<word.size(); i++){
            char orginal = word[i];
            for(char ch='a'; ch<='z'; ch++){
                word[i] = ch;
                if(mp.find(word) != mp.end() && mp[word]+1 == step){
                    temp.push_back(word);
                    solve(word,beginWord,mp,ans,temp);
                    //backtrack
                    temp.pop_back();
                }
            }
            word[i] = orginal;
        }
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st(wordList.begin(),wordList.end());
        st.erase(beginWord);

        queue<string>q;
        q.push(beginWord);

        unordered_map<string,int>mp;
        mp[beginWord] = 0;

        while(!q.empty()){
            string word = q.front();
            int step = mp[word];
            q.pop();

            if(word == endWord) break;

            for(int i=0; i<word.size(); i++){
                char original = word[i];
                for(char ch='a'; ch<='z'; ch++){
                    word[i] = ch;
                    if(st.count(word) > 0){
                        q.push(word);
                        st.erase(word);
                        mp[word] = step+1;
                    }
                }
                word[i] = original;
            }
        }
        vector<vector<string>>ans;
        for(auto it: mp){
            cout<<it.first<<" "<<it.second<<endl;
        }
        vector<string>temp;
        temp.push_back(endWord);
        if(mp.find(endWord)!=mp.end()){
            solve(endWord,beginWord,mp,ans,temp);
        }
        return ans;
    }
};
