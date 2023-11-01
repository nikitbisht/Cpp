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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL||head->next==NULL||k<0){
            return head;
        }
        int size=0;
        ListNode*pre=head;
        ListNode*cur=NULL;
        while(pre!=NULL){
            size++;
            pre=pre->next;
        }
        k=k%size;   // now value of k is less but still in same rotation
        pre=NULL;
        while(k!=0){
            pre=head;
            cur=head->next;
            while(cur->next!=NULL){
                pre=pre->next;
                cur=cur->next;
            }
            cur->next=head;
            head=cur;
            pre->next=NULL;
            k--;
        }
        return head;  
    }
};
