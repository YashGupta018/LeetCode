class Solution {
public:
    unordered_map<int, int>mp;
    TreeNode* make_tree(int start, int end, int &idx, vector<int>& postorder, vector<int>& inorder) {
        if(start > end) return NULL;
        TreeNode* root = new TreeNode(postorder[idx]);
        int i = mp[root->val];
        idx--;
        root->right = make_tree(i+1, end, idx, postorder, inorder);
        root->left = make_tree(start, i-1, idx, postorder, inorder);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int idx=postorder.size()-1;
        for(int i{}; i<inorder.size(); ++i) {
            mp[inorder[i]] = i;
        }
        return make_tree(0, inorder.size()-1, idx, postorder, inorder);
    }
};