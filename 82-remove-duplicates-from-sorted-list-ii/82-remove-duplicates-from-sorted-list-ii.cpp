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
        ListNode* temp=new ListNode(-1);
        ListNode* slow=new ListNode(-1,temp);
        map<int,int> mp;
        while(fast)
        {
            mp[fast->val]++;
            fast=fast->next;
        }
        for(auto x:mp)
        {
            if(x.second==1)
            {
                temp->next=new ListNode(x.first); 
                temp=temp->next;
            }
        }
        return slow->next->next;
    }
};