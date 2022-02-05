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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();
        map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            while(lists[i])
            {
                mp[lists[i]->val]++;
                lists[i]=lists[i]->next;
            }
        }
        ListNode* temp=new ListNode();
        ListNode* head=temp;
        for(auto x:mp)
        {
            int z=x.second;
            while(z--)
            {
                temp->next=new ListNode(x.first);
                temp=temp->next;
            }
        }
        return head->next;
    }
};