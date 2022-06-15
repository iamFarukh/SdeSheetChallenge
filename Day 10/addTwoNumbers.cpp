#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
            int data;
	        Node *next;
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
        };

*****************************************************************/

Node *addTwoNumbers(Node *head1, Node *head2)
{
    // Write your code here.
    Node* head =new Node(-1);
    Node* cur=head;
    int sum=0,carry=0;
    while(head1!=NULL && head2!=NULL){
        sum = head1->data +head2->data +carry;
        Node * temp =new Node(sum%10);
        if(sum > 9)
            carry=sum/10;
        else carry=0;
        cur ->next =temp;
        cur=cur->next;
        head1=head1->next;
        head2=head2 ->next;
    }
    while(head1!=NULL){
        sum =head1->data +carry;
        Node *t=new Node(sum%10);
        if(sum >  9)carry=sum/10;
        else carry=0;
        cur->next=t;
        cur=cur->next;
        head1=head1->next;
    }
    while(head2!=NULL){
        sum =head2->data +carry;
        Node *t=new Node(sum%10);
        if(sum >  9)carry=sum/10;
        else carry=0;
        cur->next=t;
        cur=cur->next;
        head2=head2->next;
    }
    if(carry!=0){
        Node* t=new Node(carry);
        cur ->next =t;
    }
    return head->next;
}
