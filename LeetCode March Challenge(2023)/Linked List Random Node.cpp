class Solution {
public:
    ListNode* HeadNode;
    Solution(ListNode* head) {
        HeadNode = head;
    }
    int getRandom() {
        int res, len = 1;
        ListNode* x = HeadNode;
        while(x){
            if(rand() % len == 0) {
                res = x->val;
            }
            len++;
            x = x->next;
        }
        return res;
    }
};
