

// } Driver Code Ends
/*  Tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

// Should return true if tree is Sum Tree, else false
class Solution{
    private:
    pair<bool,int>sumTree(Node* root){
        //base case
        if(root==NULL){
            pair<bool,int>p=make_pair(true,0);
            return p;
        }
        //leaf node
        if(root->left==NULL && root->right==NULL){
            pair<bool,int>p=make_pair(true,root->data);
            return p;
        }
        pair<bool,int>left=sumTree(root->left);
        pair<bool,int>right=sumTree(root->right);
        
        bool diff = left.second+right.second == root->data;
        pair<bool,int>ans;
        if(left.first && right.first && diff){
            ans.first=true;
            ans.second = 2*root->data;
        }else{
            ans.first=false;
        }
        return ans;
    }

    public:
    bool isSumTree(Node* root){
        return sumTree(root).first;
    }
};
