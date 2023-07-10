class Solution {
public:
    int depth(TreeNode* root) {
        if(root==NULL)return INT_MAX;
        if(root->left==NULL && root->right==NULL)return 1;
        return 1 + min(depth(root->left),depth(root->right));
    }
    int minDepth(TreeNode* root) {
        if(root==NULL)return 0;
        return depth(root);
    }
};