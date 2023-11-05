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
    int getSize(ListNode* head){
        int cnt=0;
        ListNode*temp=head;
        while(temp!=NULL){
            cnt++;
            temp=temp->next;
        }
        return cnt;
    }
public:
    ListNode* swapNodes(ListNode* head, int k) {
        if(head==NULL||head->next==NULL){
            return head;
        }
        int size=getSize(head);
        int posi=size-k+1;
        //if Size = 2 than this logic works
        if(size==2){
            ListNode* next = head->next;
            head->next=NULL;
            next->next=head;
            head=next;
            return head;
        }
        ListNode* leftpre=NULL;
        ListNode* leftcurr=NULL;
        ListNode* rightpre=NULL;
        ListNode* rightcurr=NULL;
        //main pointer for traversing
        ListNode* pre=NULL;
        ListNode* curr=head;

        int i=1;
        //Set the pointer in their k the index ans k-1 index
        while(i<=posi||i<=k){
            if(i==k){
                leftpre=pre;
                leftcurr=curr;
            }
            if(i==posi){
                rightpre=pre;
                rightcurr=curr;
            }
            i++;
            pre=curr;
            curr=curr->next;
        }
        //Edge Cases
        if(k==1||k==size){
            swap(leftcurr->next,rightcurr->next);
            if(k==size){    //pointing last node
                swap(head,leftpre->next);
                head=leftcurr;
            }else{          //Pointing first Node
                swap(head,rightpre->next);
                head=rightcurr;
            }
        }else{
            swap(leftpre->next,rightpre->next);
            swap(leftcurr->next,rightcurr->next);
        }   
        return head;
    }
};
