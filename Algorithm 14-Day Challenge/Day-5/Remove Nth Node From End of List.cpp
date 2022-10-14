class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {    
        ListNode *fast=head;
        for(int i=0;i<n;i++)
            fast=fast->next;
        if(fast==NULL)
        {
            ListNode *node=head;
            head=head->next;
            delete node;
            return head;
        }  
        ListNode *slow=head;
        while(fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next;
        }         
        ListNode *node=slow->next;
        slow->next=node->next;
        delete node;
    return head;
    }
};