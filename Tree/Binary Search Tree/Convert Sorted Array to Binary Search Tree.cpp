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
    TreeNode* solve(vector<int> nums, int start,int end){
        //base case 
        if(start>end)   return NULL;
        int mid= start+(end-start)/2;
        TreeNode* newroot= new TreeNode(nums[mid]);
        newroot->left=solve(nums,start,mid-1);
        newroot->right=solve(nums,mid+1,end);
        return newroot;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return solve(nums,0,nums.size()-1);
    }
};
