/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        if(node==NULL){
            return ;
        }
        ListNode* temp=node->next;

        while(temp!=NULL){
            node->val=temp->val;
            temp=temp->next;
            if(temp!=NULL){
                node=node->next;
            }
        }
        node->next=NULL;
    }
};
