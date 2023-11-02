//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
       stack<int>st;
       // Push the candidate in to stack 
       for(int i=0;i<n;i++){
           st.push(i);
       }
       //WE will run the loop until there is one candidate left in the stack and check whether one perseon know other or not
       while(st.size()!=1){
           int a=st.top();
           st.pop();
           int b=st.top();
           st.pop();
           if(M[a][b]==1){        //check person a known b or not
               st.push(b);
           }else{
               st.push(a);
           }
       }
       //now verify it celebrity or not
       int a=st.top();
       int cntzero=0;
       for(int i=0;i<n;i++){
           if(M[a][i]==0){
               cntzero++;
           }
       }
       int cntone=0;
       for(int i=0;i<n;i++){
           if(M[i][a]==1){
               cntone++;
           }
       }
       
       if(cntzero!=n){
           return -1;
       }
       if(cntone!=n-1){
           return -1;
       }
       return a;
    }
};
