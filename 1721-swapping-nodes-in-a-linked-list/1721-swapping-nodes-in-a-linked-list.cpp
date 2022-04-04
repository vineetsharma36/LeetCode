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
    ListNode* swapNodes(ListNode* head, int k) {
        vector<int> v;
        ListNode* start=head;
        while(head){
            v.push_back(head->val);
            head=head->next;
        }
        head=start;
        int temp=v[k-1];
        v[k-1]=v[v.size()-k];
        v[v.size()-k]=temp;
        temp=0;
        while(head){
            head->val=v[temp++];
            head=head->next;
        }
        return start;
    }
};