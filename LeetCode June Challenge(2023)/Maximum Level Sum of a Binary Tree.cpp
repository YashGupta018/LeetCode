class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int level=0;
        int mx= INT_MIN;
        int level_number;
        while(q.size()) {
            int k=q.size();
            level++;
            int sum=0;
            while(k--) {
                auto x =q.front();
                q.pop();
                sum+=x->val;
                if(x->left!=NULL) {
                    q.push(x->left);
                }
                if(x->right!=NULL) {
                    q.push(x->right);
                }
            }
            if(mx<sum) {
                mx=sum;
                level_number=level;
            }
        }
        return level_number;
    }
};