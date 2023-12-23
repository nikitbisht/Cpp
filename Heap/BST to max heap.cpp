// } Driver Code Ends
//User function Template for C++

/*struct Node {
    int data;
    Node *left, *right;
};*/

class Solution{
  private:
    void storeBst(Node* root,vector<int>&ans){
        //base case
        if(!root) return ;
        storeBst(root->left,ans);
        ans.push_back(root->data);
        storeBst(root->right,ans);
    }
    void convertArrayToHeap(Node* &root,int& indx,vector<int>&ans){
        if(!root || indx >= ans.size()) return ;
        convertArrayToHeap(root->left,indx,ans);
        convertArrayToHeap(root->right,indx,ans);
        root->data = ans[indx++];
    }
  public:
    void convertToMaxHeapUtil(Node* root){
        vector<int>ans;
        storeBst(root,ans);
        int indx = 0;
        convertArrayToHeap(root,indx,ans);
    }
};
