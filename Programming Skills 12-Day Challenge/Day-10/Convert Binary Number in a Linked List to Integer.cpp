class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int s=0;
        while(head!=NULL) {
            s=s*2+head->val;
            head=head->next;
        }
        return s;
    }
};