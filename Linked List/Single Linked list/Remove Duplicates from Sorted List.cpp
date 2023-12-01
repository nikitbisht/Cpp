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
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head||!head->next)  return head;
        ListNode* curr=head;
        ListNode* next=head->next;
        while(curr!=NULL && curr->next!=NULL){
            while(next!=NULL && curr->val==next->val){
                next=next->next;
            }
            curr->next=next;
            curr=next;
        }
        return head;
    }
};
