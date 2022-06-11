LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head)  
{
   // Write your code here
   LinkedListNode<int> *dummynode = NULL;
   while(head != NULL){
    LinkedListNode<int> *nextt = head->next;
    head->next = dummynode;
       dummynode = head;
       head = nextt;
   }
   return dummynode;
}
