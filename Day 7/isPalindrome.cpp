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


LinkedListNode<int> *reverseList(LinkedListNode<int> *head){
    LinkedListNode<int> *pre=NULL;
    LinkedListNode<int> *nex=NULL;
    
    while(head!=NULL){
        nex=head->next;
        head->next=pre;
        pre=head;
        head=nex;
    }
    return pre;
}

bool isPalindrome(LinkedListNode<int> *head) {
    // Write your code here.
    if(head==NULL || head->next==NULL){
        return true;
    }
    LinkedListNode<int> *slow=head;
    LinkedListNode<int> *fast=head;
    
    // Find Middle of The Linked List
    while(fast->next!=NULL && fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    // Reverse the Linked List
    slow->next=reverseList(slow->next);
    
    //Move slow to right half
    slow=slow->next;
    
    //Check If Left Half elements are equal to right half elements
    while(slow!=NULL){
        if(head->data!=slow->data){
            return false;
        }
        head=head->next;
        slow=slow->next;
    }
    return true;

}
