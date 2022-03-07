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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL && l2!=NULL)
            return l2;
        if(l1!=NULL && l2==NULL)
            return l1;
        if(l1==NULL && l2==NULL)
            return NULL;
        
        ListNode* l3= new ListNode();
        ListNode* l4= new ListNode();
        l4->next=l3;
        while(l1 && l2)
        {           
            if(l1->val<l2->val)
            {
                l3->val=l1->val;
                l1=l1->next;
            }
            else
            {                        
                l3->val=l2->val;
                l2=l2->next;
            }
            l3->next=new ListNode();
            l3=l3->next;
        }
        while(l1)
        {
            if(l1)
            {
                l3->val=l1->val;
                l1=l1->next;
                if(l1)
                {
                    l3->next=new ListNode();
                    l3=l3->next;
                }
            }    
        }
        while(l2)
        {
            if(l2)
            {
                l3->val=l2->val;
                l2=l2->next;
                if(l2)
                {
                    l3->next=new ListNode();
                    l3=l3->next;
                }
            }  
        }
        return l4->next;
    }
};