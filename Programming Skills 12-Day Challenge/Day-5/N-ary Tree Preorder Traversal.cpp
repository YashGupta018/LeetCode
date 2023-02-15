class Solution {
public:
    vector<int> preorder(Node* root) {
        if (!root) return {};
        vector<int> v;
        v.push_back(root->val);
        for (int i=0; i<root->children.size(); i++) {
            vector<int>v1 = preorder(root->children[i]);
            v.insert(v.end(), v1.begin(), v1.end());
        }
        return v;
    }
};