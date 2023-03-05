class Solution {
    public:
    vector<vector<int>> levelOrder(Node* root) {
        if (!root) return {};
        vector<vector<int>> ans;
        queue<Node*> q;
        q.push(root);
        while (!empty(q)) {
            int q_size = size(q);
            ans.push_back({});
            while (q_size--) {
                const Node* node = q.front(); q.pop();
                ans.back().push_back(node->val);
                for (Node* child : node->children) {
                    q.push(child);
                }
            }
        }
        return ans;
    }
};