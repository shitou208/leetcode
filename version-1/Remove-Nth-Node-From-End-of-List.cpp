



struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    int list_len=1,j=0;
    struct ListNode* p;
    p=head;
    //先求出链表的长度list_len 
    while(p->next!=NULL){
        list_len++;
        p=p->next;
       }
    p=head;
    //第一种情况，n=1,也就是删除链表末尾元素 
    if(n==1&&n!=list_len){
    while(p->next->next!=NULL){
    	p=p->next;
	 }
	 p->next=NULL; 
	} 
	//第2种情况，n=list_len,也就是删除链表第一个元素 
    if(n==list_len){
    	head=head->next;
	}
	//第三种情况，要删除的元素在链表中间 
	if(n!=1&&n!=list_len){
		while(j<list_len-n-1){
			j++;
			p=p->next;
		}
		p->next=p->next->next;
	}
    return head;
}
