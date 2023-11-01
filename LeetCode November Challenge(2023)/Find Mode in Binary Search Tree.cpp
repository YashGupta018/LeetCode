class Solution {
private:
    vector<int> mode;
    int max_count;
    int prev;
    int count;

public:
    vector<int> findMode(TreeNode* root) {
        if (root == NULL) {
            return mode;
        }

        mode.clear();
        max_count = 0;
        prev = -1;
        count = 0;

        inorder(root);

        return mode;
    }

    void inorder(TreeNode* root) {
        if (root == NULL) {
            return;
        }

        inorder(root->left);

        if (prev == -1) {
            prev = root->val;
            count = 1;
        } else if (prev == root->val) {
            count++;
        } else {
            prev = root->val;
            count = 1;
        }

        if (count > max_count) {
            max_count = count;
            mode = {root->val};
        } else if (count == max_count) {
            mode.push_back(root->val);
        }

        inorder(root->right);
    }
};