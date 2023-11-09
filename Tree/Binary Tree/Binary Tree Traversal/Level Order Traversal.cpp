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
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>result;
        if(root==NULL){
            return result;
        }
        vector<int> ans;
        queue<TreeNode*>q;
        q.push(root);
        //Seprator
        q.push(NULL);
        while(!q.empty()){
            TreeNode*frontNode=q.front();
            q.pop();
            //previous level is complete traversal
            if(frontNode==NULL){
                result.push_back(ans);
                ans.clear();
                //Queue still have some element so add seprator
                if(!q.empty()){
                    q.push(NULL);
                }
            }
            else{
                ans.push_back(frontNode->val);
                if(frontNode->left){
                    q.push(frontNode->left);
                }
                if(frontNode->right){
                    q.push(frontNode->right);
                }
            }
        }
        return result;
    }
};