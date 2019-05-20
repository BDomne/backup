/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* swapPairs(struct ListNode* head)
{
    struct ListNode *result, *p, *q, *r, *tail;
    
    if(head == NULL || head->next == NULL){
        return head;
    }
    else{
        result=head->next;
    }
    
    tail=r=head;
    while(1)
    {
        if(r == NULL || r->next == NULL){
            break;
        }
        p=r;
        q=r->next;
        r=r->next->next;
        tail->next=q;
        q->next=p;
        p->next=r;
        tail=p;
    }
    
    return result;
}

