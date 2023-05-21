class Solution {
public:
    int widthOfBinaryTree(TreeNode* a) {
        vector<int>v;
        if(!a)
        return 0;
        int ans = 1;
        queue<pair<TreeNode*,long long int>>q;
        q.push({a,0});
        while(!q.empty()) {
            int sz = q.size();
            int a1 = 0, b1 = 0;
            int l = 0;
            int mn = q.front().second;
            for(int i = 0; i < sz; i++) {
                auto p = q.front();
                TreeNode* b = p.first;
                long long int k = p.second-mn;
                q.pop();
                if(i == 0)
                a1 = k;
                if(i == sz-1)
                b1 = k;
                if(b->left)
                q.push({b->left,2*k+1});
                if(b->right)
                q.push({b->right,2*k+2});
            }
            ans = max(ans,b1-a1+1);
        }
        return ans;
    }
};