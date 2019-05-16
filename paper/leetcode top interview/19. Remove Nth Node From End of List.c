/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n)
{
    struct ListNode *p, *q, *r;
    int i;
    
    p=q=head;
    for(i=0; i<n; ++i){
        p=p->next;
    }
    if(p == NULL)
    {
        head=q->next;
        free(q);
        return head;
    }
    while(p->next != NULL)
    {
        p=p->next;
        q=q->next;
    }
    r=q->next;
    q->next=r->next;
    free(r);
    
    return head;
}
