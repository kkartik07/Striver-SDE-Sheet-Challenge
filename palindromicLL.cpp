#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/
LinkedListNode<int> *reverse(LinkedListNode<int>* head){
    if(head==NULL || head->next==NULL)return head;
    LinkedListNode<int> *prev=NULL,*curr=head,*ahead=head->next;
    while(curr!=NULL){
        curr->next=prev;
        prev=curr;
        curr=ahead;
        if(ahead!=NULL)ahead=ahead->next;
    }
    return prev;
}
bool isPalindrome(LinkedListNode<int> *head) {
    // Write your code here.
    if(head==NULL || head->next==NULL)return true;
    LinkedListNode<int> *slow=head,*fast=head;
    while(fast->next!=NULL && fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    slow->next=reverse(slow->next);
    LinkedListNode<int> *start=head;
    LinkedListNode<int> *mid=slow->next;
    while(mid!=NULL){
        if(mid->data!=start->data)return false;
        start=start->next;
        mid=mid->next;
    }
    slow->next=reverse(slow->next);
    return true;
}