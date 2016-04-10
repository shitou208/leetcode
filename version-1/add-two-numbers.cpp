/***
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
**/
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    bool carry_flag=false;
    struct ListNode *p,*q,*last;
    //如果存在空链表
    if(l1==NULL||l2==NULL){
    	return (l1==NULL)?l2:l1;
    }
    else{
        //以l1为基础链表（以哪个开始不影响）
         p=l1;
         q=l2;
         while(p!=NULL&&q!=NULL){
          if((q->val+p->val)>9){
          	p->val=(carry_flag)?(q->val+p->val+1)%10:(q->val+p->val)%10;
          	carry_flag=true;
          }
           else{
           	if((q->val+p->val)==9&&carry_flag){
           		p->val=0;
           		carry_flag=true;
           	}
           	else{
           	    p->val=(carry_flag)?(q->val+p->val+1):(q->val+p->val);
          	    carry_flag=false;
             }
           }
         if(p->next==NULL){ last=p;}
         p=p->next;
         q=q->next;
         }
        //循环结束，检查一下是哪个list先遍历完了
         if(p==NULL&&q==NULL)//两个list长度相同
         {
          //如果在最后一位还产生了进位，那么就要malloc出一个新的结点存放进位值
          if(carry_flag){
             struct ListNode* extra;
             extra=(struct ListNode*)malloc(sizeof(struct ListNode));
             extra->val=1;
             extra->next=last->next;
             last->next=extra;
          }
         }
         if(p==NULL&&q!=NULL)//l2比l1长
         {
            last->next=q;
            while(q!=NULL){
            if(q->next==NULL) {last=q;}//保存最后一个结点的信息，后面用
            if(q->val==9&&carry_flag){
            q->val=0;
            carry_flag=true;
            q=q->next;
             }
             else{
             q->val=(carry_flag)?(q->val+1):q->val;
             carry_flag=false;
             q=q->next;
             }
          }
          if(carry_flag){
             struct ListNode* extra;
             extra=(struct ListNode*)malloc(sizeof(struct ListNode));
             extra->val=1;
             extra->next=last->next;
             last->next=extra;
          }
         }
         if(p!=NULL&&q==NULL)//l1比l2长
         {
            while(p!=NULL){
            if(p->next==NULL) {last=p;}//保存最后一个结点的信息，后面用
            if(p->val==9&&carry_flag){
            p->val=0;
            carry_flag=true;
            p=p->next;
             }
             else{
             p->val=(carry_flag)?(p->val+1):p->val;
             carry_flag=false;
             p=p->next;
             }
          }
          if(carry_flag){
             struct ListNode* extra;
             extra=(struct ListNode*)malloc(sizeof(struct ListNode));
             extra->val=1;
             extra->next=last->next;
             last->next=extra;
          }
         }
        return  l1;
         }
}