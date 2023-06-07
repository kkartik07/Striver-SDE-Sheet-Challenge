#include <bits/stdc++.h>

/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    if(first==NULL)return second;
    if(second==NULL)return first;

    Node<int>* ans, *tail;
    if(first->data<second->data){
        ans=first;
        first=first->next;
    } else {
      ans = second;
      second=second->next;
    }

    tail=ans;
    while(first!=NULL && second!=NULL){
        if(first->data<second->data){
            tail->next=first;
            tail=first;
            first=first->next;
        }
        else{
            tail->next=second;
            tail=second;
            second=second->next;
        }
    }

    if(first==NULL)tail->next=second;
    else tail->next=first;
    return ans;
}
