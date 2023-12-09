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
    TreeNode* find(TreeNode* curr){
        TreeNode* pred=curr->left;
        while(pred->right!=NULL && pred->right!=curr){
            pred=pred->right;
        }
        return pred;
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        //Morris Traversal
        TreeNode* curr=root;
        vector<int>ans;
        while(curr){
            if(!curr->left){
                ans.push_back(curr->val);
                curr=curr->right;
            }else{
                //find predessor
                TreeNode* pred=find(curr);
                //Create Temporary Node
                if(!pred->right){
                    pred->right=curr;
                    curr=curr->left;
                }
                //Remove Temporary Node
                else{
                    pred->right=NULL;
                    ans.push_back(curr->val);
                    curr=curr->right;
                }
            }
        }
        return ans;
    }
};
