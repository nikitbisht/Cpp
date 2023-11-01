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
        ListNode*prev=NULL;
        ListNode*forward=NULL;
        ListNode*curr=head;
        while(curr!=NULL){
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        return prev;
    }
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==NULL||head->next==NULL||left==right){
            return head;
        }
        ListNode*head1=NULL;
        ListNode*headtail=head;
        ListNode*tail=NULL;
        ListNode*curr=head;
        ListNode*prev=NULL;
        int i=1;
        while(i<=right){
            if(i==left){
                headtail=prev;
                head1=curr;
                if(prev!=NULL)
                    headtail->next=NULL;

            }
            if(i==right){
                tail=curr->next;
                curr->next=NULL;
            }
            i++;
              prev=curr;
            curr=curr->next;
        }
        curr=head1;
        if(left==1){        //special case
            headtail=reverseList(head);
            head1->next=tail;
            return headtail;
        }
        else{
            headtail->next=reverseList(head1);
            head1->next=tail;
            return head;
        }
    }
};
