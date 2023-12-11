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
    TreeNode* placeNode(int val){
        TreeNode* newroot = new TreeNode(val);
        newroot->left = newroot->right = NULL;
        return newroot;
    }
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        //base case
        if(!root){
            root = placeNode(val);
            return root;
        }
        //left side
        if(root->val>val){
            root->left = insertIntoBST(root->left,val) ;
        }
        //right side
        else{
            root->right=insertIntoBST(root->right,val);
        }
        return root;
    }
};
