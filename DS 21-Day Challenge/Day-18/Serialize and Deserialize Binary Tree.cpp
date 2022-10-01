class Codec {
public:
    string serialize(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        string str;
        while (!q.empty()) {
            if (q.front() == nullptr) {
                str = str + "#,";
            }
            else {
                q.push(q.front()->left);
                q.push(q.front()->right);
                str = str + to_string(q.front()->val) + ",";
            }
            q.pop();
        }
        return str;
    }
    TreeNode* deserialize(string data) {
        TreeNode* root = nullptr;
        queue<TreeNode**> q;
        q.push(&root);
        string::iterator first = data.begin();
        while (first != data.end()) {
            TreeNode** pp = q.front();
            if (*first == '#') {
                advance(first, 2);
            }
            else {
                string::iterator last = find(first, data.end(), ',');
                int val = stoi(string(first, last));
                *pp = new TreeNode(val);
                q.push(&((*pp)->left));
                q.push(&((*pp)->right));
                first = next(last);
            }
            q.pop();
        }
        return root;
    }
};