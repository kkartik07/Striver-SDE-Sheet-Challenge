Node* merge(Node* h1,Node* h2){
	if(h1==NULL)return h2;
	if(h2==NULL)return h1;

	Node* res=new Node(0);
	Node* temp=res;

	while(h1!=NULL && h2!=NULL){
		if(h1->data < h2->data){
			temp->child=h1;
			temp=temp->child;
			h1=h1->child;
		}
		else{
			temp->child=h2;
			temp=temp->child;
			h2=h2->child;
		}
	}
	if(h1)temp->child=h1;
	else temp->child=h2;

	return res->child;
}
Node* flattenLinkedList(Node* head) 
{
	if(head==NULL || head->next==NULL)return head;

	Node* newHead=head->next;
	newHead=flattenLinkedList(newHead);
	head->next=NULL;
	head=merge(head,newHead);
	return head;
}