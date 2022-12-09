class Solution {
    public:
    int diff = INT_MIN;
    void getMax(TreeNode *root, int mx, int mi) {
        if(root == NULL) return;
        mx = max(mx, root->val);
        mi = min(mi, root->val);
        diff = max(diff, mx - mi);   
        getMax(root->left,mx,mi);
        getMax(root->right,mx,mi);
    }
    int maxAncestorDiff(TreeNode* root) {
        if(!root) return 0;
        int mx = INT_MIN, mi = INT_MAX;
        getMax(root,mx,mi);
        return diff;
    }
};