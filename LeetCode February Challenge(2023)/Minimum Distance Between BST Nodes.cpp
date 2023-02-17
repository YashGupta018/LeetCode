class Solution {
private:
    int minNum{100000}, prev{-99999};
    void minDIFF(TreeNode* root) {
        if (!root) return;
        minDIFF(root->left);
        int s = root->val-prev;
        minNum = minNum<s ? minNum:s;
        prev+=s;
        minDIFF(root->right);
        return;
    }
public:
    int minDiffInBST(TreeNode* root) {
        minDIFF(root);
        return minNum;
    }
};