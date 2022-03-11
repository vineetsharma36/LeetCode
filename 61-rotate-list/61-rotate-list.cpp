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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)
            return head;
        ListNode* temp=head;
        int n=1;
        while(temp->next){
            n++;
            temp=temp->next;
        }
        k=k%n;
        temp->next=head;
        for(int i=0;i<=n-k;i++){
            temp=temp->next;
        }
        ListNode* start=temp;
        for(int i=0;i<n;i++){
            //cout<<temp->val<<" ";
            if(i==n-1){
                temp->next=NULL;
            }
            temp=temp->next;
        }
        return start;
    }
};