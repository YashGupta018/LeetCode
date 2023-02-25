class Solution {
public:
    map<pair<ListNode*, TreeNode*>, bool> m;
    bool check(ListNode* head, TreeNode* root, ListNode* ihead) {
        if(head==NULL) {
            return true;
        }
        if(root==NULL) {
            return false;
        }
        if(m.count({head, root})!=0) {
            return m[{head, root}];
        }
        bool o1=false,o2=false;
        if(ihead->val==root->val) {
            o1 = check(ihead->next, root->left, ihead) || check(ihead->next, root->right, ihead);
        }
        else {
            o1 = check(ihead, root->left, ihead) || check(ihead, root->right, ihead);
        }
        if(head->val==root->val) {
            o2 = check(head->next, root->left, ihead) || check(head->next, root->right, ihead);
        }
        return m[{head, root}]=o1||o2;
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        return check(head, root, head);
    }
};