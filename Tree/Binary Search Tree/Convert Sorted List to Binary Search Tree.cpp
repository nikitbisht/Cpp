/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
//count no node in Linked list
    int countNode(ListNode* head){
        int cnt=0;
        ListNode* temp=head;
        while(temp){
            cnt++;
            temp=temp->next;
        }
        return cnt;
    }
//create tree from sorted list
    TreeNode* listToBst(ListNode* &head,int n){
        //base case
        if(n<=0||head==NULL){
            return NULL;
        }
        TreeNode* left=listToBst(head,n/2);
        TreeNode* root= new TreeNode(head->val);
        root->left=left;
        head=head->next;
        root->right=listToBst(head,n-n/2-1);
        return root;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return listToBst(head,countNode(head));
    }
};
