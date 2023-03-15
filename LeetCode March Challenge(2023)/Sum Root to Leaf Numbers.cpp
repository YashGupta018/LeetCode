class Solution {
public:
    void findSum(TreeNode* root, int temp ,int &ans) {
        if(root==NULL){
            return;
        }
        temp=temp*10+root->val;
        if(root->left==NULL and root->right==NULL) {
            ans+=temp;
        }
        findSum(root->left,temp,ans);
        findSum(root->right,temp,ans);
    }
    int sumNumbers(TreeNode* root) {
        if(root==NULL) {
            return 0;
        }
        int ans=0;
        findSum(root,0,ans);
        return ans;
    }
};