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
    ListNode* reverse(ListNode* head){
        ListNode* curr=head;
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
    void reverse(vector<int> &ans){
        int i=0,j=ans.size()-1;
        while(i<=j){
            swap(ans[i],ans[j]);
            i++,j--;
        }
        return ;
    }
public:
    vector<int> nextLargerNodes(ListNode* head) {
        // if(head==NULL||h)
        ListNode* temp = reverse(head);
        vector<int>ans;
        stack<int>s;
        s.push(0);
        while(temp!=NULL){
            int curr=temp->val;
            while(s.size()>1 && s.top()<=curr){
                s.pop();
            }
            ans.push_back(s.top());
            s.push(curr);
            temp=temp->next;
        }
        reverse(ans);
        return ans;
    }
};
