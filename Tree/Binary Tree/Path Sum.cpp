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
    bool solve(TreeNode* root,int targetSum,int sum){
        if(root==NULL){
            return false;
        }
        sum+=root->val;
      //  target value path from root to leaf
        if((sum==targetSum) && (root->left==NULL) && (root->right==NULL)){
            return true;
        }
        bool left=solve(root->left,targetSum,sum);
        bool right=solve(root->right,targetSum,sum);
        
        bool ans=left||right;
        if(ans){
            return true;
        }
        else{
            return false;
        }
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum=0;
        return solve(root,targetSum,sum);
    }
};
