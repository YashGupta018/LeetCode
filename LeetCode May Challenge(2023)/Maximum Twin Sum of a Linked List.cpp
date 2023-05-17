class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode* temp=head;
        stack<int>s;
        while(temp) {
            s.push(temp->val);
            temp=temp->next;
        }
        int mx=0;
        while(s.size()) {
            mx=max(mx,s.top()+head->val);
            head=head->next;
            s.pop();
            }
        return mx;
    }
};