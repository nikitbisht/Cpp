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
    vector<int> preorderTraversal(TreeNode* root) {
        //Preorder Traversal using Morris Traversal
        vector<int>ans;
        TreeNode* curr=root;
        while(curr){
            if(!curr->left){
                ans.push_back(curr->val);
                curr=curr->right;
            }else{
                //fing predessor
                TreeNode* pred=curr->left;
                while(pred->right!=NULL && pred->right!=curr){
                    pred=pred->right;
                }
                //Create Temporary Node
                if(!pred->right){
                    ans.push_back(curr->val);
                    pred->right=curr;
                    curr=curr->left;
                }
                //Remove Temporary Node
                else{
                    pred->right=NULL;
                    curr=curr->right;
                }
            }
        }
        return ans;
    }
};
