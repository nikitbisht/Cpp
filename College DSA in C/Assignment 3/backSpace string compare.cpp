class Solution {
private:
    string makeValid(string &s){
        int i=0;
        stack<char>st;
        while(i<s.size()){
            if(s[i]=='#'){
                if(!st.empty()){
                    st.pop();
                }
            }
            else{
                st.push(s[i]);
            }
            i++;
        }
        s.erase();
        while(!st.empty()){
            s.push_back(st.top());
            st.pop();
        }
        return s;
    }
public:
    bool backspaceCompare(string s, string t) {
        s=makeValid(s);
        t=makeValid(t);
    return s==t;
    }
};
