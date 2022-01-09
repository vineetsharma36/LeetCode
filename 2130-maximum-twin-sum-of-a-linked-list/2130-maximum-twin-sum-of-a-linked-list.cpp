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
    int pairSum(ListNode* head) {
        vector<int> v;
        int res=INT_MIN;
        while(head){
            v.push_back(head->val);
            head=head->next;
        }
        int i=0, j=v.size()-1;
        while(i<j){
            res=max(res, v[i++]+v[j--]);
        }
        return res;
    }
};