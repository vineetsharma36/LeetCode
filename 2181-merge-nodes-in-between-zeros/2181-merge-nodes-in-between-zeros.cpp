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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* start=new ListNode(-1, nullptr);
        ListNode* res=start;
        vector<int> v;
        int sum=0;
        head=head->next;
        while(head){
            if(head->val==0){
                v.push_back(sum);
                sum=0;
            }
            else{
                sum+=head->val;
            }
            head=head->next;
        }
        for(auto& x:v){
            start->next=new ListNode(x, nullptr);
            start=start->next;
        }
        return res->next;
    }
};