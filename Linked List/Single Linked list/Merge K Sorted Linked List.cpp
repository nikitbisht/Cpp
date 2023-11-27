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
    ListNode* mergeTwoLinkedList(ListNode* l1,ListNode* l2){
        ListNode* ansHead = new ListNode(-1);
        ListNode* ansTail=ansHead;
        while(l1!=NULL && l2!=NULL){
            if(l1->val <= l2->val){
                ansTail->next=l1;
                ansTail=l1;
                l1=l1->next;
            }
            else{
                ansTail->next=l2;
                ansTail=l2;
                l2=l2->next;
            }
        }
        if(l1!=NULL){
            ansTail->next=l1;
        }
        if(l2!=NULL){
            ansTail->next=l2;
        }
        ansTail->next=l1?l1 : l2;

        ListNode*temp=ansHead;
        ansHead=ansHead->next;
        delete temp;
        return ansHead;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* ansList=NULL;
        if(lists.empty())    return ansList;
        int size=lists.size();
        for(int i=0;i<size;i++){
            ansList = mergeTwoLinkedList(ansList,lists[i]);
        }
        return ansList;
    }
};
