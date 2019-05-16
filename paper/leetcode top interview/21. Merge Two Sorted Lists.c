/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int cmp(const void *a, const void *b)
 {
	 return *(int*)a - *(int*)b;
 }

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) 
{
	struct ListNode *p=l1, *q=l2, *r;
	int *a, i, n=0;

	if(l1 == NULL){
		return l2;
	}
	if(l2 == NULL){
		return l1;
	}

	while(p != NULL)
	{
		n++;
		p=p->next;
	}
	while(q != NULL)
	{
		n++;
		q=q->next;
	}

	a=(int*)malloc(sizeof(int)*n);
	n=0;
	p=l1;
	q=l2;
	while(p != NULL)
	{
		a[n]=p->val;
		n++;
		p=p->next;
	}
	while(q != NULL)
	{
		a[n]=q->val;
		n++;
		q=q->next;
	}
	qsort(a, n, sizeof(int), cmp);

	p=l1;
	q=l2;
	if(l1->val < l2->val){
		r=l1;
		p=p->next;
	}
	else
	{
		r=l2;
		q=q->next;
	}

	for(i=1; i<n; ++i)
	{
		if(p != NULL && p->val == a[i]){
			r->next=p;
			p=p->next;
		}
		else
		{
			r->next=q;
			q=q->next;
		}
		r=r->next;
	}
	free(a);

	if(l1->val < l2->val){
		return l1;
	}
	return l2;
}
