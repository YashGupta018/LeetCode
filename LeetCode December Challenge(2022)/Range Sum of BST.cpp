class Solution {
    public:
    int rangeSumBST(TreeNode* root, int L, int H) {
        int ans = 0;
        while(root)
            if(root -> left && root -> val >= L) {
                auto pre = root -> left;  
                while(pre -> right && pre -> val <= H) pre = pre -> right;
                pre -> right = root;
                auto tmp = root;
                root = root -> left;                    
                tmp -> left = nullptr;
            }
			else {
                if(root -> val >= L && root -> val <= H) ans += root -> val;
                if(root -> val < H) root = root -> right;
                else break;
            }
        return ans;
    }
};