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
    // Node to parent mapping usign Level order traversal
    TreeNode* nodeToParentMapping(TreeNode* root,map<TreeNode*,TreeNode*>&nodeToParent,int target){
       queue<TreeNode*>q;
       TreeNode* result=NULL;
       q.push(root);
       nodeToParent[root]=NULL;
        while(!q.empty()){
            TreeNode* frontNode = q.front(); q.pop();
            if(frontNode->val==target){
                result=frontNode;
            }
            if(frontNode->left){
                nodeToParent[frontNode->left]=frontNode;
                q.push(frontNode->left);
            }
            if(frontNode->right){
                nodeToParent[frontNode->right]=frontNode;
                q.push(frontNode->right);
            }
        }
        return result;
    }

    int burnTree(TreeNode* root,map<TreeNode* ,TreeNode*>& nodeToParent){
        queue<TreeNode*>q;
        q.push(root);
        int time=0;
        map<TreeNode* ,bool>visited;
        visited[root]=true;
        while(!q.empty()){
            int size =q.size();
            bool flag=false;
            for(int i=0;i<size ;i++){
                TreeNode* frontNode=q.front();  q.pop();
                //Left Node
                if(frontNode->left && !visited[frontNode->left]){
                    visited[frontNode->left]=true;
                    q.push(frontNode->left);
                    flag=true;
                }
                //Right Node
                if(frontNode->right && !visited[frontNode->right]){
                    visited[frontNode->right]=true;
                    q.push(frontNode->right);
                    flag=true;
                }
                //parent Node
                if(nodeToParent[frontNode] && !visited[nodeToParent[frontNode]]){
                    q.push(nodeToParent[frontNode]);
                    visited[nodeToParent[frontNode]]=true;
                    flag=true;
                }
            }
            if(flag==true)    
                time++;
        }
        return time;
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode*,TreeNode*>nodeToParent;
        TreeNode* targetNode = nodeToParentMapping(root,nodeToParent,start);
        int time=burnTree(targetNode,nodeToParent);
        return time;
    }
};
