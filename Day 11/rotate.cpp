#include <bits/stdc++.h> 
/********************************

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

********************************/


Node *rotate(Node *head, int k) {
     // Write your code here.
    if(head==NULL || head->next==NULL || k==0){
        return head;
    }
    
    int len=1;
    Node* curr=new Node(0);
    curr=head;
    
    while(curr->next!=NULL){
        curr=curr->next;
        len++;
    }
    
    curr->next=head;
    k=k%len;
    k=len-k;
    while(k--){
        curr=curr->next;
    }
    head=curr->next;
    curr->next=NULL;

    return head;
}
