



struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    int list_len=1,j=0;
    struct ListNode* p;
    p=head;
    //���������ĳ���list_len 
    while(p->next!=NULL){
        list_len++;
        p=p->next;
       }
    p=head;
    //��һ�������n=1,Ҳ����ɾ������ĩβԪ�� 
    if(n==1&&n!=list_len){
    while(p->next->next!=NULL){
    	p=p->next;
	 }
	 p->next=NULL; 
	} 
	//��2�������n=list_len,Ҳ����ɾ�������һ��Ԫ�� 
    if(n==list_len){
    	head=head->next;
	}
	//�����������Ҫɾ����Ԫ���������м� 
	if(n!=1&&n!=list_len){
		while(j<list_len-n-1){
			j++;
			p=p->next;
		}
		p->next=p->next->next;
	}
    return head;
}
