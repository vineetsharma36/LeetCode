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
    ListNode* partition(ListNode* head, int x) {
        ListNode* start=new ListNode(-1);
        ListNode* res=start;
        ListNode* headst=head;
        while(head){
            if(head->val<x){
                res->next=new ListNode(head->val);
                res=res->next;
            }
            head=head->next;
        }
        head=headst;
        while(head){
            if(head->val>=x){
                res->next=new ListNode(head->val);
                res=res->next;
            }
            head=head->next;
        }
        return start->next;
    }
};