/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    int getSize(ListNode*&head){
        ListNode* temp=head;
        int cnt=0;
        while(temp!=NULL){
            temp=temp->next;
            cnt++;
        }
        return cnt;
    }
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int a=getSize(headA);
        int b=getSize(headB);

        ListNode*temp1=headA;
        ListNode*temp2=headB;

        if(a>b){
            while(b!=a){
                temp1=temp1->next;
                b++;
            }
        }else{
            while(a!=b){
                temp2=temp2->next;
                a++;
            }
        }
        while(temp1!=NULL&&temp2!=NULL){
            if(temp1==temp2){
                return temp1;
            }
            temp1=temp1->next;
            temp2=temp2->next;
        }
        return NULL;
    }
};
