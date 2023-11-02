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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL||head->next==NULL){
            return head;
        }
        ListNode* anshead=new ListNode(-1);
        ListNode* anstail=anshead;
        int i=1;
        ListNode* pre=NULL;
        ListNode* curr=head;
        ListNode* next=curr->next;
        while(curr!=NULL){
            if(i%2==0){
                anstail->next=curr;
                anstail=curr;
                next=curr->next;
                anstail->next=pre;
                pre=anstail;
                anstail=anstail->next;
                curr=next;
            }else{
                pre=curr;
              curr=curr->next;
            }
            i++;
        }
       if(i%2==0){
           anstail->next=pre;
           anstail=anstail->next;
       }
        anstail->next=NULL;
        return anshead->next;
    }
};
