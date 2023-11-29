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
    bool solve(TreeNode* root1,TreeNode* root2){
        //base case
        if(!root1&&!root2) return true;
        if(root1 && !root2) return false;
        if(!root1 && root2) return false;
        
        bool left= solve(root1->left,root2->right);
        bool right= solve(root1->right,root2->left);
        bool ans= (left && right) && (root1->val==root2->val);
        return ans;
    }
public:
    bool isSymmetric(TreeNode* root) {
        return solve(root->left,root->right);
    }
};
