class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        return sortedListToBST( head, NULL );
    }
private:
    TreeNode *sortedListToBST(ListNode *head, ListNode *tail) {
        if( head == tail )
            return NULL;
        if( head->next == tail ) {	
    		TreeNode *root = new TreeNode( head->val );
            return root;
        }
    	ListNode *mid = head, *temp = head;
        while( temp != tail && temp->next != tail ) {
            mid = mid->next;
            temp = temp->next->next;
        }
    	TreeNode *root = new TreeNode( mid->val );
        root->left = sortedListToBST( head, mid );
        root->right = sortedListToBST( mid->next, tail );
        return root;
    }
};