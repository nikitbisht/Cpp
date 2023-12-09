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
    TreeNode* solve(vector<int>& preorder,int &indx, int bound){
        if(indx>=preorder.size() || preorder[indx]>bound)
            return NULL;
        TreeNode* root = new TreeNode(preorder[indx++]);
        //for every left node its is less than root node
        root->left = solve(preorder,indx,root->val);
        //for every right node it is greter than its previous bound
        root->right = solve(preorder,indx,bound);
        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int bound=INT_MAX;
        int indx=0;
        //Range base Approch
        return solve(preorder,indx,bound);
    }
};
