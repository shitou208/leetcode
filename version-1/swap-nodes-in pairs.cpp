/*
Given a linked list, swap every two adjacent nodes and return its head.
For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.
Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
*/
struct ListNode* swapPairs(struct ListNode* head) {
     struct ListNode *p,*q,*temp,*last;
     int i=1;
     p=head;
     if(head==NULL||head->next==NULL){
     	return head;
     }
     else{
       while(p!=NULL){
       if(p->next==NULL){
       	return head;
       }         
       else{
       	 q=p->next->next;
         temp=p->next;
         p->next=temp->next;
         temp->next=p;
         if(i==1){head=temp;}
         else{last->next=temp;}
         i++;
         last=p;
         p=q;
        }
       }
      return head;
     }
}