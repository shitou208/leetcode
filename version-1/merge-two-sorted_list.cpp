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

 //当前版本的算法，经过了改进，已在leetcode上AC
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
   
   struct ListNode *p,*q,*temp,*temp2;
   //先判断两个list中是否有某一个为空链表
   if(l1==NULL||l2==NULL){
      return (l1==NULL)?l2:l1;
   }
   else{
    //判断一下l1和l2谁的首元素大，然后相应地确定以哪个list为基准
    if(l1->val<=l2->val)//l1为基准
    {
       p=l1;
       q=l2;      
       while(q!=NULL){
          temp2=q->next;//要先保存下一结点信息
         if(q->val>=p->val){
           while(p!=NULL&&q->val>=p->val){ 
            temp=p;
            p=p->next; 
          }
          q->next=temp->next;
          temp->next=q;
          temp=temp->next;//因为新插入了元素，所以temp位置发生了变化
         }
         else{
            q->next=temp->next;
            temp->next=q;
            temp=temp->next;//因为新插入了元素，所以temp位置发生了变化
         }
         if(p==NULL)//如果出现l1长度小于l2长度时
         {
           q->next=temp2;
           break;
         }
         q=temp2;
         }
       return l1; 
    }
    else//l2为基准
    {
      p=l2;
      q=l1;
      while(q!=NULL){
          temp2=q->next;//要先保存下一结点信息
         if(q->val>=p->val){
           while(p!=NULL&&q->val>=p->val){ 
            temp=p;
            p=p->next; 
          }
          q->next=temp->next;
          temp->next=q;
          temp=temp->next;
         }
         else{
            q->next=temp->next;
            temp->next=q;
            temp=temp->next;//因为新插入了元素，所以temp位置发生了变化（只要插入元素就会后移）
         }
         if(p==NULL)
         {
           q->next=temp2;
           break;
         }
         q=temp2;
       }  
       return l2; 
    }
   }
}