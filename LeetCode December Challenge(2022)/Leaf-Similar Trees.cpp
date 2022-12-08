class Solution {
public:
    void dfs(TreeNode* root, vector<int>& v) {
        if (!root) return;
        if (!(root->left || root->right)) {
            v.push_back(root->val);
        }
        dfs(root->left, v);
        dfs(root->right, v);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> v1{};
        vector<int> v2{};
        dfs(root1, v1);
        dfs(root2, v2);
        return v1 == v2;
    }
};