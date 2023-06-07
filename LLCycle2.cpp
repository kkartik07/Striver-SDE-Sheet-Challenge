
Node *firstNode(Node *head)
{
    //    Write your code here.
    Node* slow=head;
    Node* fast=head;

    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)break;
    }
    if(fast==NULL || fast->next==NULL)return NULL;
    fast=head;
    while(fast!=slow){
        fast=fast->next;
        slow=slow->next;
    }
    return slow;
}