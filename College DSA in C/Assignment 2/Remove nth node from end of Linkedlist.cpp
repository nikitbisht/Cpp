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
    int sizeList(ListNode* &head){
        int cnt=0;
        ListNode*temp=head;
        while(temp!=NULL){
            cnt++;
            temp=temp->next;
        }
        return cnt;
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL){
            return head;
        }
        int posi = sizeList(head) - n + 1;
        if(posi==1){
            head=head->next;
        }else{
            int i=1;
            ListNode*curr=head;
            ListNode*pre=NULL;
            while(i<posi){
                pre=curr;
                curr=curr->next;
                i++;
            }
            pre->next=curr->next;
        }
        return head;
    }
};
