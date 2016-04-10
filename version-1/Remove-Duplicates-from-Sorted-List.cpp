/*
Given a sorted linked list, delete all duplicates such that each element appear only once.
For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *deleteDuplicates(struct ListNode *head)
{
    struct ListNode *p, *q, *temp;
    int last;
    if(head == NULL)
    {
        return NULL;
    }
    p = head;
    last = head->val;
    while(p != NULL && p->next != NULL)
    {
        q = p->next;
        if(p->next->val == last)
        {
            temp = q;
            q = q->next;
            p->next = q;
            free(temp);
        }
        else
        {
            last = p->next->val;
            p = p->next;
            if(q->next == NULL)
            {
                return head;
            }
        }
        if(q != NULL && q->next == NULL)
        {
            if(last == q->val)
            {
                p->next = q->next;
                free(q);
                return head;
            }
        }
        //p=q;
    }
    return head;
}