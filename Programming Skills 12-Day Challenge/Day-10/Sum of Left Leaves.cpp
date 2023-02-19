class Solution {
public:
    int res = 0;
    void dfs(TreeNode* root, int direction) {
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL) {
            if(direction == 0)
                res += root->val;
            return;
        }
        dfs(root->left, 0);
        dfs(root->right, 1);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        dfs(root, -1);
        return res;
    }
};