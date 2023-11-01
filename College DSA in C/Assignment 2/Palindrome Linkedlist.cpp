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
private:
    ListNode* getMid(ListNode*&head){
        ListNode*slow=head;
        ListNode*fast=head->next;
        while(fast!=NULL&&fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* reverse(ListNode*& head){
        ListNode*pre=NULL;
        ListNode*curr=head;
        ListNode*forward=NULL;
        while(curr!=NULL){
            forward=curr->next;
            curr->next=pre;
            pre=curr;
            curr=forward;
        }
        return pre;
    }
public:
    bool isPalindrome(ListNode* head) {
        if(head==NULL||head->next==NULL){
            return true;
        }
        ListNode* start=head;
        ListNode*mid=getMid(head);
        ListNode*head2=mid->next;
        head2=reverse(head2);
        while(head2!=NULL){
            if(start->val!=head2->val){
                return false;
            }
            head2=head2->next;
            start=start->next;
        }
        return true;
    }
};
