/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* rotateRight(struct ListNode* head, int k)
{
    struct ListNode *p=head, *q;
    int index=0, n=0, i;
    
    if(head == NULL || head->next == NULL){
        return head;
    }
    while(p != NULL)
    {
        if(p->next == NULL){
            q=p;
        }
        p=p->next;
        ++n;
    }
    k=k%n;
    if(k == 0){
        return head;
    }
    q->next=head;
    
    for(i=0; i<k; ++i){
        index=(index+n-1)%n;
    }
    q=head;
    p=head->next;
    for(i=1; i<index; ++i)
    {
        q=q->next;
        p=p->next;
    }
    q->next=NULL;
    
    return p;
}

