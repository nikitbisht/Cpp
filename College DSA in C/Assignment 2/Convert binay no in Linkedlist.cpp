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
    ListNode* reverseList(ListNode*&head){
        ListNode* cur=head;
        ListNode* pre=NULL;
        ListNode* next=NULL;
        while(cur!=NULL){
            next=cur->next;
            cur->next=pre;
            pre=cur;
            cur=next;
        }
        return pre;
    }
public:
    int getDecimalValue(ListNode* head) {
        if(head==NULL){
            return 0;
        }
        head=reverseList(head);
        ListNode* temp=head;
        int i=0,total=0;
        while(temp!=NULL){
            if(temp->val==1)
                total=pow(2,i)+total;
            temp=temp->next;
            i++;
        }
        return total;
    }
};
