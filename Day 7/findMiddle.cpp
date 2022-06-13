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
// Here we are finding the length of the linked list
int get_length(Node* &head) {
   Node* curr = head;
   int len = 0;
   while(curr != NULL) {
       len++;
       curr = curr -> next;
   }
   return len;
}
Node *findMiddle(Node *head) {
   // Write your code here
    int leng = get_length(head);
   int mid = (leng/2) + 1;
   int count = 1;
   Node* crr = head;
   while(count != mid) {
       crr = crr -> next;
       count++;
   }
   return crr;
}
