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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* s1head=new ListNode(-1);
        ListNode*s1tail=s1head;
        while(list1!=NULL&&list2!=NULL){
            if(list1->val < list2->val){
                s1tail->next=list1;
                s1tail=list1;
                list1=list1->next;
            }
            else{
                s1tail->next=list2;
                s1tail=list2;
                list2=list2->next;
            }
        }
        while(list1!=NULL){
            s1tail->next=list1;
            s1tail=list1;
            list1=list1->next;
        }
        while(list2!=NULL){
            s1tail->next=list2;
            s1tail=list2;
            list2=list2->next;
        }
        return s1head->next;
    }
};
