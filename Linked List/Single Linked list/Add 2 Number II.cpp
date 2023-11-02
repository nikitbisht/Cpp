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
//REVESE THE LINKED LIST
        ListNode*reverse(ListNode* head){
            ListNode*curr=head;
            ListNode* pre=NULL;
            ListNode* next=NULL;
            while(curr!=NULL){
                next=curr->next;
                curr->next=pre;
                pre=curr;
                curr=next;
            }
            return pre;
        }
//INSERTION IN LINKEDLIST
        void insertAtBegning(ListNode* &head,ListNode* &tail,int x){
            ListNode*newnode=new ListNode(x);
            if(head==NULL){
                head=tail=newnode;
            }else{
                tail->next=newnode;
                tail=newnode;
            }
        }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode*temp1=reverse(l1);
        ListNode*temp2=reverse(l2);
        int carry=0;
        ListNode*anshead=NULL;
        ListNode* anstail=NULL;
      
        while(temp1!=NULL||temp2!=NULL||carry!=0){
            int val1=0,val2=0,sum=0;
          
            if(temp1!=NULL){
                val1=temp1->val;
            }
          
           if(temp2!=NULL){
                val2=temp2->val;
            }
          
            sum=val1+val2+carry;
            carry=sum/10;
            sum=sum%10;
          
            insertAtBegning(anshead,anstail,sum);

            if(temp1!=NULL){
                temp1=temp1->next;
            }
            if(temp2!=NULL){
                temp2=temp2->next;
            }
        }
        anshead=reverse(anshead);
        return anshead;
    }
};
