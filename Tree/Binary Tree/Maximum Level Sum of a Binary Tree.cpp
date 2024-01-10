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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int maxi = INT_MIN;
        int level = 0;
        int ans = -1;
        while(!q.empty()){
            int size = q.size();
            int sum = 0;
            level++;
            for(int i = 0; i < size ;i++){
                TreeNode* frontNode = q.front();
                q.pop();
                sum += frontNode->val;
                if(frontNode->left)
                    q.push(frontNode->left);
                if(frontNode->right)
                    q.push(frontNode->right);
            }
            if(sum > maxi){
                maxi = sum;
                ans = level;
            }
        }
        return ans;
    }
};
