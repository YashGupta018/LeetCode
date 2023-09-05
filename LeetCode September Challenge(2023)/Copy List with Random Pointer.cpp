class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL)
            return NULL;
        Node* temp=head;
        while(temp!=NULL) {
            Node* newnode= new Node(temp->val);
            newnode->next=temp->next;
            temp->next=newnode;
            temp=newnode->next;
        }
        temp=head;
        while(temp!=NULL) {
            temp->next->random=(temp->random)?(temp->random->next):NULL;       
            temp=temp->next->next;
        }
        Node* original=head;
        Node* clone=head->next;
        Node* result=head->next;
        while(original!=NULL) {
            original->next=original->next->next;
            clone->next= (clone->next)?(clone->next->next):NULL;
            original=original->next;
            clone=clone->next;
        }
        return result;
    }
};