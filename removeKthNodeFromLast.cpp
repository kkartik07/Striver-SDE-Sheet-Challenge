Node* removeKthNode(Node* head, int K)
{
    Node* dummy = new Node();
    dummy->next = head;
    Node* slow = dummy;
    Node* fast = dummy;
    for(int i=1;i<=K;i++)
    {
        fast = fast->next;
    }
    while(fast->next!=NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = slow->next->next;
    return dummy->next;
}