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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode* fast=head;
        ListNode* prev=new ListNode(-101,fast);
        ListNode* nxt=fast->next;
        ListNode* temp=new ListNode(-1);
        ListNode* slow=new ListNode(-1,temp);
        while(fast)
        {
            if(nxt==NULL){
                if(fast->val!=prev->val)
                {
                    temp->next=new ListNode(fast->val); 
                    temp=temp->next;
                }
                break;
            }
            if(fast->val!=prev->val && fast->val!=nxt->val){
                temp->next=new ListNode(fast->val); 
                temp=temp->next;
            }
            fast=fast->next;
            prev=prev->next;
            nxt=nxt->next;
        }
        // for(auto x:mp)
        // {
        //     if(x.second==1)
        //     {
        //         temp->next=new ListNode(x.first); 
        //         temp=temp->next;
        //     }
        // }
        return slow->next->next;
    }
};