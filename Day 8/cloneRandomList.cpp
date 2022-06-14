#include <bits/stdc++.h> 
/*************************************************************

    Following is the LinkedListNode class structure

    template <typename T>   
    class LinkedListNode
    {
        public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode<T> *random;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*************************************************************/
LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    // Write your code here.
    LinkedListNode<int> *itr=head;
    while(itr!=NULL)
    {  
        LinkedListNode<int> *front=itr->next;
        LinkedListNode<int> *dumy=new LinkedListNode<int> (itr->data);
        dumy->next=itr->next;
        itr->next=dumy;
        itr=front;
    }
   itr=head;
   while(itr!=NULL)
   {
       itr->next->random=itr->random;
       itr=itr->next->next;
   }
   itr=head;
   LinkedListNode<int>* copy=new LinkedListNode<int> (0);
   LinkedListNode<int> *newnode=copy;
   while(itr!=NULL)
   {
       LinkedListNode<int> *front=itr->next->next;
       copy->next=itr->next;
       itr->next=front;
       itr=front;
       copy=copy->next;
    }
    return newnode->next;
}
