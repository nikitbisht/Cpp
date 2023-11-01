class Solution {
public:
    bool isValid(string s) {
    //Use LIFO principle
    stack<char> st;
    int i=0;
    while(i<s.length()){
        if(s[i]=='('||s[i]=='['||s[i]=='{'){
            st.push(s[i]);
        }
        else{
             if(st.empty()||(s[i]=='}'&&st.top()!='{')||(s[i]==')'&&st.top()!='(')||
                            (s[i]==']'&&st.top()!='[')){
            return false;
            }
        st.pop();
        }
        i++;
    }
    return st.empty();
    }
};
