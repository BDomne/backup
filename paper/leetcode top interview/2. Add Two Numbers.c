/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) 
{
    struct ListNode *rr, *r, *p=l1, *q=l2;
    int i, n, m=0, tmp;
    
    rr=r=(struct ListNode*)malloc(sizeof(struct ListNode));
    tmp=0;
    while(p)
    {
        tmp++;
        p=p->next;
    }
    n=tmp;
    tmp=0;
    while(q)
    {
        tmp++;
        q=q->next;
    }
    if(tmp>n){
        n=tmp;
    }
    p=l1;
    q=l2;
    for(i=0; i<n; i++)
    {
        if(p!=NULL && q!=NULL){
            tmp=p->val+q->val+m;
        }
        else
        {
            if(p!=NULL){
                tmp=p->val+m;
            }
            if(q!=NULL){
                tmp=q->val+m;
            }
        }
        m=tmp/10;
        r->val=tmp%10;
        r->next=(struct ListNode*)malloc(sizeof(struct ListNode));
        r=r->next;
        if(p!=NULL){
            p=p->next;
        }
        if(q!=NULL){
            q=q->next;
        }
    }
    if(m!=0)
    {
       r->val=m;
       r->next=NULL;
    }
    else
    {
       p=rr;
       while(1)
       {
           if(p->next == r)
           {
               p->next=NULL;
               free(r);
               break;
           }
           p=p->next;
       }
    }
    
    return rr;
}
