class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(t2==NULL) return t1;
        if(t1==NULL) return t2;
        TreeNode* res=t1;
        stack<TreeNode*> s1, s2;
        s1.push(t1), s2.push(t2);
        while(!s1.empty()) {
            TreeNode* c1=s1.top();
            TreeNode* c2=s2.top();
            s1.pop(), s2.pop();
            c1->val+=c2->val;
            if(c1->right==NULL&&c2->right!=NULL) c1->right=c2->right;
            else if(c1->right!=NULL&&c2->right!=NULL) s1.push(c1->right), s2.push(c2->right);
            if(c1->left==NULL&&c2->left!=NULL) c1->left=c2->left;
            else if(c1->left!=NULL&&c2->left!=NULL) s1.push(c1->left), s2.push(c2->left);
        }
        return res;
    }
};