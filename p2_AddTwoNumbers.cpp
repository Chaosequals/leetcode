/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == NULL || l2 == NULL)
            return l1==NULL?l2:l1 ;
        
        ListNode* temp = new ListNode(0) ;
        ListNode* res = temp ;
        
        int c = 0 ;
        temp->val = (l1->val + l2->val + c)%10 ;
        c = (l1->val + l2->val + c)/10 ;            //carry bit
            
        l1 = l1->next ;
        l2 = l2->next ;
        while(l1 != NULL && l2 != NULL)
        {
            ListNode* temp2 = new ListNode(0) ;
            temp->next = temp2 ;
            temp = temp->next ;
            
            temp->val = (l1->val + l2->val + c)%10 ;
            c = (l1->val + l2->val + c)/10 ;
            
            l1 = l1->next ;
            l2 = l2->next ;     
        }
        
        while(l1 != NULL)
        {
            ListNode* temp2 = new ListNode(0) ;
            temp->next = temp2 ;
            temp = temp->next ;
            
            temp->val = (l1->val + c)%10 ;
            c = (l1->val + c)/10 ;
            
            l1 = l1->next ;
        }
        
        while(l2 != NULL)
        {
            ListNode* temp2 = new ListNode(0) ;
            temp->next = temp2 ;
            temp = temp->next ;
            
            temp->val = (l2->val + c)%10 ;
            c = (l2->val + c)/10 ;
            
            l2 = l2->next ;
        }
        
        if(c != 0)
        {
            ListNode* temp2 = new ListNode(1) ;
            temp->next = temp2 ;
        }
        return res ;
        
    }
};
