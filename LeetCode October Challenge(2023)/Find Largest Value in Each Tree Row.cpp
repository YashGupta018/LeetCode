class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        int i,j,k,c=0;
        queue<TreeNode*>q;
        vector<int>ans;
        if(!root)
        return ans;
        q.push(root);
        while(!q.empty()){
            int levelsize=q.size();
            int m=INT_MIN;
            while(levelsize-->0) {
                TreeNode* curr=q.front();
                q.pop();
                m=max(m,curr->val);
                if(curr->left) {
                    q.push(curr->left);
                }
                if(curr->right) {
                    q.push(curr->right);
                }
            }
        ans.push_back(m);
        }
        return ans;
    }
};