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
    bool isEvenOddTree(TreeNode* root) {
        bool evenIndex=true;
        int temp=INT_MIN;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode* frontNode=q.front();
                q.pop();
                //even index --> odd value --> incresing order
                if(evenIndex){      //True
                    if(frontNode->val %2==0){
                        return false;
                    }
                    if(temp<frontNode->val){
                        temp=frontNode->val;
                    }else return false;
                }
                //Odd Index --> even value --> decresing order
                else{
                    if(frontNode->val %2==0){
                        if(temp>frontNode->val){
                        temp=frontNode->val;
                        }else return false;
                    }else return false;
                }
                if(frontNode->left){
                    q.push(frontNode->left);
                }
                if(frontNode->right){
                    q.push(frontNode->right);
                }
            }
            evenIndex=!evenIndex;
            if(!evenIndex){
                temp=INT_MAX;
            }else{
                temp=INT_MIN;
            }
        }
        return true;
    }
};
