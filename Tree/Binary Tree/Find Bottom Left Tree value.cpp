/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    pair<int,int> solve(TreeNode* root,int height){
        //base case
        if(root==NULL){
            pair<int,int>temp=make_pair(height-1,0);
            return temp;
        }
        if(root->left==NULL && root->right==NULL){
            pair<int,int>temp=make_pair(height,root->val);
            return temp;
        }
        cout<<"left of "<<root->val<<endl;
        pair<int,int>left=solve(root->left,height+1);
        cout<<"right of "<<root->val<<endl;
        pair<int,int>right=solve(root->right,height+1);
        
        pair<int,int>ans;
        if(left.first < right.first){
            ans.first=right.first;
            ans.second=right.second;
        }else{
            ans.first=left.first;
            ans.second=left.second;
        }
        cout<<ans.first<<"  a   "<<ans.second<<endl;
        return ans;
    }
public:
    int findBottomLeftValue(TreeNode* root) {
        return solve(root,1).second;
    }
};
