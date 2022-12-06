class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head -> next) return head;
        auto dummy = new ListNode(), ansIter = dummy, iter = head;
        for(iter = head; iter && iter -> next; iter = iter -> next -> next)
            ansIter = ansIter -> next = new ListNode(iter -> val);
        if(iter) ansIter = ansIter -> next = new ListNode(iter -> val);
        for(iter = head -> next; iter && iter -> next; iter = iter -> next -> next)
            ansIter = ansIter -> next = new ListNode(iter -> val);
        if(iter) ansIter = ansIter -> next = new ListNode(iter -> val);
        return dummy -> next;
    }
};