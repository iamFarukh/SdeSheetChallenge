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
   // Write your code here.
   Node<int> *ans = new Node<int>(-1);  // ans node
   Node<int> *ansHead = ans;    // store to return
   
   while(first!=NULL && second!=NULL){  // either becomes NULL -> break
       if(first->data >= second->data){
           ans->next = second;    // simple
           ans = ans->next;
           second = second->next;
       }
       else{  
           ans->next = first;    // simple
           ans = ans->next;  
           first = first->next;
       }
   }
   
   if(first!=NULL){      // if first has leftover
       while(first!=NULL){
           ans->next = first;
           ans = ans->next;
           first = first->next;
       }
   }
   if(second!=NULL){      // if second has leftover
       while(second!=NULL){
           ans->next = second;
           ans = ans->next;
           second = second->next;
       }
   }
   return ansHead->next;     // simple
}
