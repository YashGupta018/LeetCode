class Solution {
public:
    int nodeCount(ListNode *head) {
        int c = 0;
        while (head) {
            ++c;
            head = head->next;
        }
        return c;
    }
    vector<ListNode *> splitListToParts(ListNode *root, int k) {
        const int N = nodeCount(root);
        int elements_per_group = N / k;
        int extra_nodes = N % k;
        vector<ListNode *> result(k);
        ListNode *curr = root;
        for (int i = 0; i < k; i++) {
            int remaining = elements_per_group;
            if (extra_nodes > 0) {
                remaining += 1;
                --extra_nodes;
            }
            result[i] = curr;
            ListNode *prev = nullptr;
            while (remaining--) {
                prev = curr;
                curr = curr->next;
            }
            if (prev)
                prev->next = nullptr;
        }
        return result;
    }
};