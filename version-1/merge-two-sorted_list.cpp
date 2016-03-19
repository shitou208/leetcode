/***
将两个有序链表进行合并，新生成的链表也保证是有序的。
（有一个要求：必须是在原有两个链表的某一个的基础之上和并出新的链表，不能引入新的链表）
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 //（默认链表是从小到大的顺序排列）

 //当前版本的算法，可以实现功能，但运行时间不符合要求，待改进
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
   
   struct ListNode *p,*q,*temp;
   //先判断两个list中是否有某一个为空链表
   if(l1==NULL||l2==NULL){
      return (l1==NULL)?l2:l1;
   }
   else{
      //先比较两个链表首元素大小，确定以哪个为基础生成新聊表
   if((l1->val)>=(l2->val)){
        p=l1;
        q=l2;
        while(p!=NULL&&q->next!=NULL){
        if(p->val>=q->next->val) {
            q=q->next;
        }  
        else{
            temp=p;
            temp->next=q->next;
            q->next=temp;
            p=p->next;
            }
        }
        if(p!=NULL){
           q->next=p;
          }
        return l2;
   }
   else{
        p=l2;
        q=l1;
        while(p!=NULL&&q->next!=NULL){
        if(p->val>=q->next->val) {
            q=q->next;
        }  
        else{
            temp=p;
            temp->next=q->next;
            q->next=temp;
            p=p->next;
            }
        }
        if(p!=NULL){
           q->next=p;
          }
   	    return l1;
   }

   }
}